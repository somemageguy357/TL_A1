#pragma once
#include "UIElement.h"

class CUIText : public CUIElement
{
public:
	CUIText() = delete;
	CUIText(unsigned int _uiTextSize, sf::Vector2f _v2fPosition, std::string _sText, sf::Color _oColour = sf::Color::Black);
	~CUIText();

	void Render(sf::RenderWindow* _poWindow);

	void SetString(std::string _sString);

private:
	sf::Text m_oText;
};