#pragma once
#define NOMINMAX 
#include "Downloader.h"
#include <SFML/Graphics.hpp>
#include <vector>

class CImageManager
{
public:
	CImageManager();
	~CImageManager();

	static CImageManager* GetInstance()
	{
		if (m_poInstance == nullptr)
		{
			m_poInstance = new CImageManager();
		}

		return m_poInstance;
	}

	void Render(sf::RenderWindow* _poWindow);

	void CreateImages(CDownloader* _poDownloader);

	void RepositionImages(int _iWindowWidth, int _iWindowHeight, int _iImagesPerPage);

	std::vector<sf::RectangleShape*> GetImageShapes();

private:
	static CImageManager* m_poInstance;

	std::vector<sf::Texture*> m_oVecTexPtrs;
	std::vector<sf::RectangleShape*> m_oVecRectPtrs;
};