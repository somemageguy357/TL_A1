#include "UIButton.h"

CUIButton::CUIButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, EButtonType _eButtonType/*, std::string _sButtonText*/)
{
	m_oButtonShape.setSize(_v2fSize);
	m_oButtonShape.setPosition(_v2fPosition);

	m_eButtonType = _eButtonType;
}

CUIButton::~CUIButton()
{
}

void CUIButton::Update(sf::RenderWindow* _poWindow, bool _bIsClicking)
{
	CheckMouseOverlap(_poWindow, _bIsClicking);
}

void CUIButton::Render(sf::RenderWindow* _poWindow)
{
	_poWindow->draw(m_oButtonShape);
}

void CUIButton::CheckMouseOverlap(sf::RenderWindow* _poWindow, bool _bIsClicking)
{
	sf::Vector2i v2iMousePosition = sf::Mouse::getPosition(*_poWindow);

	if (v2iMousePosition.x >= m_oButtonShape.getGlobalBounds().left &&
		v2iMousePosition.x <= m_oButtonShape.getGlobalBounds().left + m_oButtonShape.getGlobalBounds().width &&
		v2iMousePosition.y >= m_oButtonShape.getGlobalBounds().top &&
		v2iMousePosition.y <= m_oButtonShape.getGlobalBounds().top + m_oButtonShape.getGlobalBounds().height)

	{
		m_oButtonShape.setFillColor(sf::Color::Green);

		if (_bIsClicking == true)
		{
			OnClick();
		}
	}

	else if (m_oButtonShape.getFillColor() != sf::Color::White)
	{
		m_oButtonShape.setFillColor(sf::Color::White);
	}
}

void CUIButton::OnClick()
{
	if (m_eButtonType == EButtonType::NextPage)
	{

	}

	else if (m_eButtonType == EButtonType::PrevPage)
	{

	}

	else if (m_eButtonType == EButtonType::SaveCollage)
	{

	}

	else if (m_eButtonType == EButtonType::LoadSmall)
	{

	}

	else if (m_eButtonType == EButtonType::LoadLarge)
	{

	}

	else if (m_eButtonType == EButtonType::Display1)
	{

	}

	else if (m_eButtonType == EButtonType::Display4)
	{

	}

	else if (m_eButtonType == EButtonType::Display9)
	{

	}

	else if (m_eButtonType == EButtonType::Display16)
	{

	}

	else if (m_eButtonType == EButtonType::Display25)
	{

	}

	else if (m_eButtonType == EButtonType::Display36)
	{

	}

	else if (m_eButtonType == EButtonType::Display49)
	{

	}

	else if (m_eButtonType == EButtonType::Display64)
	{

	}

	else if (m_eButtonType == EButtonType::Quit)
	{

	}
}