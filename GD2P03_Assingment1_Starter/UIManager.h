/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : PageManager.h
Description : Manages the UI elements that are displayed to the window.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include "SFML/Graphics.hpp"

#include "UIButton.h"

#include <vector>

class CUIManager
{
public:
	/// <summary>
	/// Gets the singleton instance of CUIManager.
	/// </summary>
	/// <returns>A pointer to the CUIManager singleton.</returns>
	static CUIManager* GetInstance()
	{
		if (m_poInstance == nullptr)
		{
			m_poInstance = new CUIManager();
			CreateUIElements();
		}

		return m_poInstance;
	}

	/// <summary>
	/// Updates any changes made to the UI elements as well as checking mouse overlap for button events.
	/// </summary>
	/// <param name="_poWindow:">The render window to check mouse position in.</param>
	/// <param name="_bIsClicking:">If the mouse is currently clicking (for button events).</param>
	void Update(sf::RenderWindow* _poWindow, bool _bIsClicking);

	/// <summary>
	/// Renders all UI elements to the given render window.
	/// </summary>
	/// <param name="_poWindow:">The window to render to.</param>
	void Render(sf::RenderWindow* _poWindow);

	/// <summary>
	/// Sets the text displaying current and max page values.
	/// </summary>
	/// <param name="_iCurrentPage:">The current page.</param>
	/// <param name="_iMaxPage:">The max page.</param>
	void UpdatePageNumberText(int _iCurrentPage, int _iMaxPage);

	/// <summary>
	/// Gets the font that is used for UI text.
	/// </summary>
	/// <returns>The font that is used for UI text.</returns>
	sf::Font* GetUIFont();

private:
	static CUIManager* m_poInstance;

	static std::vector<CUIButton*> m_oVecButtonPtrs;
	static std::vector<CUIText*> m_oVecTextPtrs;
	static CUIText* m_poPageNumberText;

	static sf::Font* m_poUIFont;

	CUIManager();
	~CUIManager();

	//Creates and positions all UI elements (buttons and text).
	static void CreateUIElements();
};