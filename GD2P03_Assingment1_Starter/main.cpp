//This define is required for anywhere both SFML and libcurl are included. 
//It prevents multiple definitions of functions min and max
#define NOMINMAX 
#include <SFML/Graphics.hpp>

#include "Downloader.h"
#include "ImageManager.h"
#include "UIManager.h"

#include <vector>

int main()
{
	int iWindowWidth = 800;
	int iWindowHeight = 900; //800 + 100 for UI space
	
	//The MAX amount that can be displayed on a page at one time. Must be a rounded square value. 
	//Accepted values are 1(1x1), 4(2x2), 9(3x3), 16(4x4), 25(5x5), 36(6x6), 49(7x7), and 64(8x8).
	int iImagesPerPage = 9;

	//Create the window to render to.
	sf::RenderWindow oWindow(sf::VideoMode(iWindowWidth, iWindowHeight), "GD2P03 Assignment 1");
	
	CDownloader* poDownloader = new CDownloader();
	poDownloader->Init();

	CImageManager::GetInstance()->CreateImages(poDownloader);
	CImageManager::GetInstance()->RepositionImages(iWindowWidth, iWindowHeight, iImagesPerPage);

	while (oWindow.isOpen() == true)
	{
		bool bIsClicking = false;

		sf::Event oWindowEvent;

		while (oWindow.pollEvent(oWindowEvent) == true)
		{
			if (oWindowEvent.type == sf::Event::MouseButtonPressed && oWindowEvent.mouseButton.button == sf::Mouse::Left)
			{
				bIsClicking = true;
			}

			if (oWindowEvent.type == sf::Event::Closed)
			{
				oWindow.close();
			}
		}

		oWindow.clear();

		//---UPDATE
		CUIManager::GetInstance()->Update(&oWindow, bIsClicking);

		//---RENDER
		CUIManager::GetInstance()->Render(&oWindow);
		CImageManager::GetInstance()->Render(&oWindow);

		oWindow.display();
	}

	curl_global_cleanup();
}