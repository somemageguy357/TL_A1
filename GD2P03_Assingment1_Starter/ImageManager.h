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
	static CImageManager* GetInstance()
	{
		if (m_poInstance == nullptr)
		{
			m_poInstance = new CImageManager();
		}

		return m_poInstance;
	}

	void Render(sf::RenderWindow* _poWindow);

	void SetImagesPerPage(int _iImagesPerPage);

	void SetLoadedImageList(EImageList _eImageList);

	void CreateImages(CDownloader* _poDownloader);

	void RepositionImages();

	std::vector<sf::RectangleShape*> GetImageShapes();

	void SaveCollage();

private:
	static CImageManager* m_poInstance;

	std::vector<sf::Texture*> m_oVecTexPtrs;
	std::vector<sf::RectangleShape*> m_oVecRectPtrs;

	//The MAX amount that can be displayed on a page at one time. Must be a rounded square value. 
	//Accepted values are 1(1x1), 4(2x2), 9(3x3), 16(4x4), 25(5x5), 36(6x6), 49(7x7), and 64(8x8).
	//This value is set by buttons.
	int m_iImagesPerPage = 1;

	EImageList m_eImageList = EImageList::SmallList;

	std::string m_sImageListAddress = "https://raw.githubusercontent.com/MDS-HugoA/TechLev/main/ImgListSmall.txt";

	CImageManager();
	~CImageManager();
};