/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : UIButton.h
Description : An interactable UI button that can perform other functions.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include "UIText.h"

enum class EButtonType
{
	n,
	PrevPage,
	NextPage,
	SaveCollage,
	LoadLarge,
	LoadSmall,
	Display1,
	Display4,
	Display9,
	Display16,
	Display25,
	Display36,
	Display49,
	Display64,
	Quit
};

class CUIButton
{
public:
	CUIButton() = delete;

	/// <summary>
	/// Creates a button that will be displayed to the render window and can be interacted with by clicking it.
	/// </summary>
	/// <param name="_v2fSize:">The size of the button.</param>
	/// <param name="_v2fPosition:">The position of the button.</param>
	/// <param name="_eButtonType:">The Button Type.</param>
	/// <param name="_sButtonText:">The text to display on the button.</param>
	/// <param name="_oTextColour:">The colour of the button's text.</param>
	CUIButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, EButtonType _eButtonType, std::string _sButtonText, sf::Color _oTextColour = sf::Color::Black);
	
	~CUIButton();

	/// <summary>
	/// Calls the button's CheckMouseOverlap function which determines if the mouse is currently positioned over it.
	/// </summary>
	/// <param name="_poWindow:">The window to check the mouse position in.</param>
	/// <param name="_bIsClicking:">Will proceed to call the button's OnClick function if true AND the mouse is positioned over the button.</param>
	void Update(sf::RenderWindow* _poWindow, bool _bIsClicking);

	/// <summary>
	/// Displays the button to the render window.
	/// </summary>
	/// <param name="_poWindow:">The window to render to.</param>
	void Render(sf::RenderWindow* _poWindow);

private:
	EButtonType m_eButtonType;
	sf::RectangleShape m_oButtonShape;
	CUIText* m_poButtonText = nullptr;
	
	/// <summary>
	/// Checks if the mouse is currently positioned over the button. Changes the colour of the button if it is and checks to 
	/// see if the mouse is being clicked. If it is, it will call OnClick.
	/// </summary>
	/// <param name="_poWindow:">The window to check the mouse position in.</param>
	/// <param name="_bIsClicking:">Will proceed to call the button's OnClick function if true AND the mouse is positioned over the button.</param>
	void CheckMouseOverlap(sf::RenderWindow* _poWindow, bool _bIsClicking);

	//Goes through a list of enums and compares it to the buttons Button Type where it will call the appropriate button function.
	void OnClick();
};