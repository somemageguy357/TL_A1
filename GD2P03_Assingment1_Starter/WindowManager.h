#pragma once
#include "SFML/Graphics.hpp"

class CWindowManager
{
public:
	static CWindowManager* GetInstance()
	{
		if (m_poInstance == nullptr)
		{
			m_poInstance = new CWindowManager();
		}

		return m_poInstance;
	}

	CWindowManager();
	~CWindowManager();

	sf::RenderWindow* GetMainWindow();

private:
	static CWindowManager* m_poInstance;

	sf::RenderWindow* m_poMainWindow = nullptr;
};