/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : UIText.h
Description : UI text that displays to the render window. Is also used within buttons.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include "SFML/Graphics.hpp"

class CUIText
{
public:
	CUIText() = delete;

	/// <summary>
	/// Creates a UI text element that is to be displayed on the render window.
	/// </summary>
	/// <param name="_uiTextSize:">The font size of the text.</param>
	/// <param name="_v2fPosition:">The position of the text.</param>
	/// <param name="_sText:">The string value of the text.</param>
	/// <param name="_oColour:">The colour of the text.</param>
	CUIText(unsigned int _uiTextSize, sf::Vector2f _v2fPosition, std::string _sText, sf::Color _oColour = sf::Color::Black);
	
	~CUIText();

	/// <summary>
	/// Displays the text element to the render window.
	/// </summary>
	/// <param name="_poWindow:">The window to render to.</param>
	void Render(sf::RenderWindow* _poWindow);

	/// <summary>
	/// Sets the string value of the text.
	/// </summary>
	/// <param name="_sString:">The string value of the text.</param>
	void SetString(std::string _sString);

private:
	sf::Text m_oText;
};