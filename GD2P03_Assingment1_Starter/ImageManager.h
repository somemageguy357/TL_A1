/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : ImageManager.h
Description : Creates and contains the images that are displayed to the render window and starts the download process to retrieve them.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#define NOMINMAX 
#include <SFML/Graphics.hpp>

#include "Downloader.h"

#include <vector>
#include <string>

enum class EImageList
{
	SmallList,
	LargeList
};

class CImageManager
{
public:
	/// <summary>
	/// Gets the singleton instance of CImageManager.
	/// </summary>
	/// <returns>A pointer to the CImageManager singleton.</returns>
	static CImageManager* GetInstance()
	{
		if (m_poInstance == nullptr)
		{
			m_poInstance = new CImageManager();
		}

		return m_poInstance;
	}

	/// <summary>
	/// Loops through all images and renders them to the given render window.
	/// </summary>
	/// <param name="_poWindow:">The window to render to.</param>
	void Render(sf::RenderWindow* _poWindow);

	/// <summary>
	/// Sets the max number of images that are to be displayed on the page.
	/// </summary>
	/// <param name="_iImagesPerPage:">The max number of images on the page.</param>
	void SetImagesPerPage(int _iImagesPerPage);

	/// <summary>
	/// Sets the image list to load from.
	/// </summary>
	/// <param name="_eImageList:">The image list/file to load from.</param>
	void SetLoadedImageList(EImageList _eImageList);

	/// <summary>
	/// Gets the URLS from the image list and uses them to download the textures that are applied to the created images.
	/// </summary>
	/// <param name="_poDownloader:">Pointer to the downloader that is used to retrieve the URLs.</param>
	void CreateImages(CDownloader* _poDownloader);

	/// <summary>
	/// Positions the images to fit the page correctly.
	/// </summary>
	void RepositionImages();

	/// <summary>
	/// Saves the currently displayed set of images to file.
	/// </summary>
	void SaveCollage();

private:
	static CImageManager* m_poInstance;

	CDownloader* m_poDownloader = nullptr;

	std::vector<sf::Texture*> m_oVecTexPtrs;
	std::vector<sf::RectangleShape*> m_oVecAllImagePtrs;
	std::vector<sf::RectangleShape*> m_oVecDisplayImagePtrs;

	//The MAX amount that can be displayed on a page at one time. Must be a rounded square value. 
	//Accepted values are 1(1x1), 4(2x2), 9(3x3), 16(4x4), 25(5x5), 36(6x6), 49(7x7), and 64(8x8).
	//This value is set by buttons.
	int m_iImagesPerPage = 4;

	EImageList m_eImageList = EImageList::SmallList;

	std::string m_sImageListAddress = "https://raw.githubusercontent.com/MDS-HugoA/TechLev/main/ImgListSmall.txt";

	CImageManager();
	~CImageManager();
};