/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : UIText.cpp
Description : Contains function definitions for UIText.h.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#include "UIText.h"
#include "UIManager.h"

CUIText::CUIText(unsigned int _uiTextSize, sf::Vector2f _v2fPosition, std::string _sText, sf::Color _oColour)
{
	m_oText.setFont(*CUIManager::GetInstance()->GetUIFont());
	m_oText.setCharacterSize(_uiTextSize);
	m_oText.setString(_sText);
	m_oText.setOrigin(m_oText.getGlobalBounds().width / 2, (m_oText.getGlobalBounds().height / 2) + 3);
	m_oText.setPosition(_v2fPosition);
	m_oText.setFillColor(_oColour);
}

CUIText::~CUIText()
{
}

void CUIText::Render(sf::RenderWindow* _poWindow)
{
	_poWindow->draw(m_oText);
}

void CUIText::SetString(std::string _sString)
{
	m_oText.setString(_sString);
	m_oText.setOrigin(m_oText.getGlobalBounds().width / 2, (m_oText.getGlobalBounds().height / 2) + 3);
	m_oText.setPosition(m_oText.getPosition());
}