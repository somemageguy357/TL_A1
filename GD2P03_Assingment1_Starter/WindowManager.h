/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : WindowManager.h
Description : Contains the main window that all images and UI elements are updated and rendered to.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include "SFML/Graphics.hpp"

class CWindowManager
{
public:
	/// <summary>
	/// Gets the singleton instance of CWindowManager.
	/// </summary>
	/// <returns>A pointer to the CWindowManager singleton.</returns>
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

	/// <summary>
	/// Gets the main window.
	/// </summary>
	/// <returns>The main window.</returns>
	sf::RenderWindow* GetMainWindow();

private:
	static CWindowManager* m_poInstance;

	sf::RenderWindow* m_poMainWindow = nullptr;
};