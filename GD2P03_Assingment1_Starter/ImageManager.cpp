/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : ImageManager.cpp
Description : Contains function definitions for ImageManager.h.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#include "ImageManager.h"

#include <filesystem>

#include "WindowManager.h"
#include "PageManager.h"
#include "ThreadPool.h"

CImageManager* CImageManager::m_poInstance = nullptr;

CImageManager::CImageManager() {}

CImageManager::~CImageManager() 
{
	for (size_t i = 0; i < m_oVecAllImagePtrs.size(); i++)
	{
		delete m_oVecAllImagePtrs[i];
	}

	for (size_t i = 0; i < m_oVecTexPtrs.size(); i++)
	{
		delete m_oVecTexPtrs[i];
	}
}

void CImageManager::Render(sf::RenderWindow* _poWindow)
{
	//Only render the images that are to be displayed to the current page.
	for (size_t i = 0; i < m_oVecDisplayImagePtrs.size(); i++)
	{
		_poWindow->draw(*m_oVecDisplayImagePtrs[i]);
	}
}

void CImageManager::SetImagesPerPage(int _iImagesPerPage)
{
	m_iImagesPerPage = _iImagesPerPage;

	CPageManager::GetInstance()->SetCurrentPage(1);
	CPageManager::GetInstance()->SetMaxPages(ceil((float)m_oVecAllImagePtrs.size() / (float)m_iImagesPerPage));

	RepositionImages();
}

void CImageManager::SetLoadedImageList(EImageList _eImageList)
{
	if (m_eImageList != _eImageList)
	{
		m_eImageList = _eImageList;

		if (m_eImageList == EImageList::SmallList)
		{
			m_sImageListAddress = "https://raw.githubusercontent.com/MDS-HugoA/TechLev/main/ImgListSmall.txt";
		}

		else
		{
			m_sImageListAddress = "https://raw.githubusercontent.com/MDS-HugoA/TechLev/main/ImgListLarge.txt";
		}

		CreateImages(m_poDownloader);
	}
}

void CImageManager::CreateImages(CDownloader* _poDownloader)
{
	m_poDownloader = _poDownloader;

	//Downloads the list of URLs and stores them in the string data.
	std::string sData = "";

	if (m_poDownloader->Download(m_sImageListAddress.c_str(), sData))
	{
		std::cout << sData << "\n";
		printf("data length: %zd\n", sData.length());
	}

	else
	{
		printf("data failed to download");
	}

	//split the urls
	size_t iPos = 0;
	size_t iOldPos = 0;
	std::vector<std::string> oVecURLs;

	while (iPos != std::string::npos)
	{
		iPos = sData.find('\n', iOldPos);
		if (iOldPos < sData.length())
		{
			oVecURLs.push_back(sData.substr(iOldPos, iPos - iOldPos));
			printf("url [%zd] : %s\n", oVecURLs.size() - 1, oVecURLs[oVecURLs.size() - 1].c_str());
			iOldPos = iPos + 1;
		}
	}

	//Thread pool for downloading the images.
	CThreadPool oThreadPool;
	std::vector<std::string> oVecDataStrings(oVecURLs.size());

	for (size_t i = 0; i < oVecURLs.size(); i++)
	{
		oVecDataStrings[i] = "";
		oThreadPool.Submit(CTask(&oVecURLs[i], &oVecDataStrings[i]));
	}

	while (oThreadPool.GetTaskProcessed() < oVecURLs.size()) {}
	oThreadPool.Stop();

	for (size_t i = 0; i < oVecURLs.size(); i++)
	{
		sf::Texture* poTexture = new sf::Texture();
		m_oVecTexPtrs.push_back(poTexture);
		poTexture->loadFromMemory(oVecDataStrings[i].c_str(), oVecDataStrings[i].length());

		sf::RectangleShape* poRect = new sf::RectangleShape();
		m_oVecAllImagePtrs.push_back(poRect);
		poRect->setTexture(poTexture);
	}

	CPageManager::GetInstance()->SetMaxPages(ceil((float)m_oVecAllImagePtrs.size() / (float)m_iImagesPerPage));
}

void CImageManager::RepositionImages()
{
	//Image position and size data.
	int iSpacing = 10; //Spacing between images, as well as padding space for the window borders (both x and y).
	int iImagesPerLine = sqrt(m_iImagesPerPage); //The max number of images to be displayed on each horizontal line.
	int iHorizontalDisplaySpace = CWindowManager::GetInstance()->GetMainWindow()->getSize().x - (iSpacing * (iImagesPerLine + 1)); //The remaining space per line that images will take up after space and padding subtractions.
	float fImageSize = (float)iHorizontalDisplaySpace / (float)iImagesPerLine; //The width and height for the images.

	int iImagesToDisplay = m_iImagesPerPage;
	int iPageStartingImage = (CPageManager::GetInstance()->GetCurrentPage() - 1) * m_iImagesPerPage;

	if (iImagesToDisplay > m_oVecAllImagePtrs.size() - iPageStartingImage)
	{
		iImagesToDisplay = m_oVecAllImagePtrs.size() - iPageStartingImage;
	}

	//Clear the image display vector and resize it to match the number of images that are to be displayed.
	m_oVecDisplayImagePtrs.clear();
	m_oVecDisplayImagePtrs.resize(iImagesToDisplay);

	//Reposition and resize all the images that are to be displayed.
	for (size_t i = 0; i < iImagesToDisplay; i++)
	{
		m_oVecAllImagePtrs[i + iPageStartingImage]->setSize(sf::Vector2f(fImageSize, fImageSize));

		int iXPos = (iSpacing * ((i % iImagesPerLine) + 1)) + (fImageSize * (i % iImagesPerLine));
		int iYPos = (iSpacing * ((i / iImagesPerLine) + 1)) + (fImageSize * (i / iImagesPerLine));
		m_oVecAllImagePtrs[i + iPageStartingImage]->setPosition(sf::Vector2f(iXPos, iYPos));

		m_oVecDisplayImagePtrs[i] = m_oVecAllImagePtrs[i + iPageStartingImage];
	}
}

void CImageManager::SaveCollage()
{
	//Create a RenderTexture that will draw the display images to it.
	//The RenderWindow is 800x900 and creating an Image/Texture of that will include the UI.
	//The full space for the display images is 800x800.
	sf::RenderTexture oRenderTexture;
	oRenderTexture.create(CWindowManager::GetInstance()->GetMainWindow()->getSize().x, CWindowManager::GetInstance()->GetMainWindow()->getSize().y - 100);

	for (size_t i = 0; i < m_oVecDisplayImagePtrs.size(); i++)
	{
		oRenderTexture.draw(*m_oVecDisplayImagePtrs[i]);
	}

	std::string sSaveFileName = "SavedImage";

	//If an image with the current filename exists: add a number to it. SFML saveToFile overwrites the file instead of creating a new one.
	if (std::filesystem::exists("SavedImages/" + sSaveFileName + ".png") == true)
	{
		int i = 0;

		while (std::filesystem::exists("SavedImages/" + sSaveFileName + ".png") == true)
		{
			i += 1;
			sSaveFileName = "SavedImage (" + std::to_string(i) + ")";
		}
	}

	sf::Image oImage = oRenderTexture.getTexture().copyToImage();
	oImage.flipVertically();
	oImage.saveToFile("SavedImages/" + sSaveFileName + ".png");
}