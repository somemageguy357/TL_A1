//This define is required for anywhere both SFML and libcurl are included. 
//It prevents multiple definitions of functions min and max
#define NOMINMAX 
#include "Downloader.h"
#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
	//Create the window to render to.
	sf::RenderWindow oWindow(sf::VideoMode(800, 600), "GD2P03 Assignment 1");
	
	CDownloader oDownloader;
	oDownloader.Init();

	//Downloads the list of URLs and stores them in the string data.
	std::string sData = "";

	if (oDownloader.Download("https://raw.githubusercontent.com/MDS-HugoA/TechLev/main/ImgListSmall.txt", sData))
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

	sData = "";
	oDownloader.Download(sVecURLs[0].c_str(), sData);//download the first image

	sf::Texture oTexture; 	//Create a texture to load the data into.
	oTexture.loadFromMemory(sData.c_str(), sData.length());

	sf::Sprite oSprite; 	//Create a sprite to draw the texture to screen.
	oSprite.setTexture(oTexture);
	oSprite.setPosition(0, 0);

	while (oWindow.isOpen())
	{
		sf::Event oWinEvent;

		while (oWindow.pollEvent(oWinEvent))
		{
			if (oWinEvent.type == sf::Event::Closed)
			{
				oWindow.close();
			}
		}

		oWindow.clear();
		//Drawing the sprite
		oWindow.draw(oSprite);
		oWindow.display();
	}

	curl_global_cleanup();

	return 0;
}