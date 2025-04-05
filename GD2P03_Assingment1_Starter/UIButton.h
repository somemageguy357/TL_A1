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

class CUIButton : public CUIElement
{
public:
	CUIButton() = delete;
	CUIButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, EButtonType _eButtonType, std::string _sButtonText, sf::Color _oColour = sf::Color::Black);
	~CUIButton();

	void Update(sf::RenderWindow* _poWindow, bool _bIsClicking);

	void Render(sf::RenderWindow* _poWindow);

private:
	EButtonType m_eButtonType;
	sf::RectangleShape m_oButtonShape;
	CUIText* m_poButtonText = nullptr;

	void CheckMouseOverlap(sf::RenderWindow* _poWindow, bool _bIsClicking);

	void OnClick();
};