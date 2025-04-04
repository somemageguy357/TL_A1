#include "WindowManager.h"

CWindowManager* CWindowManager::m_poInstance = nullptr;

CWindowManager::CWindowManager()
{
	m_poMainWindow = new sf::RenderWindow(sf::VideoMode(800, 900), "GD2P03 Assignment 1");
}

CWindowManager::~CWindowManager()
{
}

sf::RenderWindow* CWindowManager::GetMainWindow()
{
	return m_poMainWindow;
}