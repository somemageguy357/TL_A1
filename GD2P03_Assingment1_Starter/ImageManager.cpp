#include "ImageManager.h"
#include "WindowManager.h"

CImageManager* CImageManager::m_poInstance = nullptr;

CImageManager::CImageManager() {}

CImageManager::~CImageManager() {}

void CImageManager::Render(sf::RenderWindow* _poWindow)
{
	for (size_t i = 0; i < m_oVecRectPtrs.size(); i++)
	{
		_poWindow->draw(*m_oVecRectPtrs[i]);
	}
}

void CImageManager::SetImagesPerPage(int _iImagesPerPage)
{
	m_iImagesPerPage = _iImagesPerPage;
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

		//reload images
	}
}

void CImageManager::CreateImages(CDownloader* _poDownloader)
{
	//Downloads the list of URLs and stores them in the string data.
	std::string sData = "";

	if (_poDownloader->Download(m_sImageListAddress.c_str(), sData))
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
	std::vector<std::string> sVecURLs;

	while (iPos != std::string::npos)
	{
		iPos = sData.find('\n', iOldPos);
		if (iOldPos < sData.length())
		{
			sVecURLs.push_back(sData.substr(iOldPos, iPos - iOldPos));
			printf("url [%zd] : %s\n", sVecURLs.size() - 1, sVecURLs[sVecURLs.size() - 1].c_str());
			iOldPos = iPos + 1;
		}
	}

	for (size_t i = 0; i < /*sVecURLs.size()*/ 1; i++)
	{
		sData = "";

		_poDownloader->Download(sVecURLs[i].c_str(), sData);

		sf::Texture* poTexture = new sf::Texture();
		m_oVecTexPtrs.push_back(poTexture);
		poTexture->loadFromMemory(sData.c_str(), sData.length());

		sf::RectangleShape* poRect = new sf::RectangleShape();
		m_oVecRectPtrs.push_back(poRect);
		poRect->setTexture(poTexture);
	}
}

void CImageManager::RepositionImages()
{
	int iSpacing = 10; //Spacing between images, as well as padding space for the window borders (both x and y).
	int iImagesPerLine = sqrt(m_iImagesPerPage); //The max number of images to be displayed on each horizontal line.
	int iHorizontalDisplaySpace = CWindowManager::GetInstance()->GetMainWindow()->getSize().x - (iSpacing * (iImagesPerLine + 1)); //The remaining space per line that images will take up after space and padding subtractions.
	float fImageSize = (float)iHorizontalDisplaySpace / (float)iImagesPerLine; //The width and height for the images.

	int iImagesToDisplay = m_iImagesPerPage;

	if (iImagesToDisplay > m_oVecRectPtrs.size())
	{
		iImagesToDisplay = m_oVecRectPtrs.size();
	}

	for (size_t i = 0; i < iImagesToDisplay; i++)
	{
		m_oVecRectPtrs[i]->setSize(sf::Vector2f(fImageSize, fImageSize));

		int iXPos = (iSpacing * ((i % iImagesPerLine) + 1)) + (fImageSize * (i % iImagesPerLine));
		int iYPos = (iSpacing * ((i / iImagesPerLine) + 1)) + (fImageSize * (i / iImagesPerLine));
		m_oVecRectPtrs[i]->setPosition(sf::Vector2f(iXPos, iYPos));
	}
}

std::vector<sf::RectangleShape*> CImageManager::GetImageShapes()
{
	return m_oVecRectPtrs;
}

void CImageManager::SaveCollage()
{
	sf::RenderTexture oRenderTexture;
	oRenderTexture.create(800, 800);

	for (size_t i = 0; i < CImageManager::GetInstance()->GetImageShapes().size(); i++)
	{
		oRenderTexture.draw(*CImageManager::GetInstance()->GetImageShapes()[i]);
	}

	sf::Image oImage = oRenderTexture.getTexture().copyToImage();
	oImage.flipVertically();
	oImage.saveToFile("SavedImages/SavedImage.png");
}