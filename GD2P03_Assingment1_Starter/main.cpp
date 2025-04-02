//This define is required for anywhere both SFML and libcurl are included. 
//It prevents multiple definitions of functions min and max
#define NOMINMAX 
#include "Downloader.h"
#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
	//Create the window to render to.
	sf::RenderWindow window(sf::VideoMode(800, 600), "GD2P03 Assignment 1");
	
	CDownloader downloader;
	downloader.Init();

	//Downloads the list of URLs and stores them in the string data.
	std::string data = "";
	if (downloader.Download(
		"https://raw.githubusercontent.com/MDS-HugoA/TechLev/main/ImgListSmall.txt",
		data))
	{
		std::cout << data << "\n";
		printf("data length: %zd\n", data.length());
	}
	else
	{
		printf("data failed to download");
	}

	//split the urls
	size_t pos = 0;
	size_t oldPos = 0;
	std::vector<std::string> urls;
	while (pos != std::string::npos)
	{
		pos = data.find('\n', oldPos);
		if (oldPos < data.length())
		{
			urls.push_back(data.substr(oldPos, pos - oldPos));
			printf("url [%zd] : %s\n", urls.size() - 1, urls[urls.size() - 1].c_str());
			oldPos = pos + 1;
		}
	} 

	data = "";
	downloader.Download(urls[0].c_str(), data);//download the first image

	sf::Texture txtr; 	//Create a texture to load the data into.
	txtr.loadFromMemory(data.c_str(), data.length());
	sf::Sprite sprite; 	//Create a sprite to draw the texture to screen.
	sprite.setTexture(txtr);
	sprite.setPosition(0, 0);

	while (window.isOpen())
	{
		sf::Event winEvent;
		while (window.pollEvent(winEvent))
		{
			if (winEvent.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		//Drawing the sprite
		window.draw(sprite);
		window.display();
	}

	curl_global_cleanup();

	return 0;
}