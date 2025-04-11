/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : WindowManager.cpp
Description : Contains function definitions for WindowManager.h.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

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