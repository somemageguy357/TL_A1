//This define is required for anywhere both SFML and libcurl are included. 
//It prevents multiple definitions of functions min and max
#define NOMINMAX 
#include <SFML/Graphics.hpp>

#include "Downloader.h"
#include "ImageManager.h"
#include "UIManager.h"
#include "WindowManager.h"
#include "ThreadPool.h"

#include <vector>

int main()
{
	//Get a pointer to the main window.
	sf::RenderWindow* poMainWindow = CWindowManager::GetInstance()->GetMainWindow();
	
	CDownloader* poDownloader = new CDownloader();
	poDownloader->Init();

	CImageManager::GetInstance()->CreateImages(poDownloader);
	CImageManager::GetInstance()->RepositionImages();

	while (poMainWindow->isOpen() == true)
	{
		bool bIsClicking = false;

		sf::Event oWindowEvent;

		while (poMainWindow->pollEvent(oWindowEvent) == true)
		{
			if (oWindowEvent.type == sf::Event::MouseButtonPressed && oWindowEvent.mouseButton.button == sf::Mouse::Left)
			{
				bIsClicking = true;
			}

			if (oWindowEvent.type == sf::Event::Closed)
			{
				poMainWindow->close();
			}
		}

		poMainWindow->clear();

		//Render images on page first.
		CImageManager::GetInstance()->Render(poMainWindow);

		CUIManager::GetInstance()->Update(poMainWindow, bIsClicking);
		CUIManager::GetInstance()->Render(poMainWindow);

		poMainWindow->display();
	}

	curl_global_cleanup();
}