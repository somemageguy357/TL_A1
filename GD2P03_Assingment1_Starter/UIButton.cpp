/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : UIButton.cpp
Description : Contains function definitions for UIButton.h.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#include "UIButton.h"
#include "PageManager.h"
#include "ImageManager.h"
#include "WindowManager.h"

CUIButton::CUIButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, EButtonType _eButtonType, std::string _sButtonText, sf::Color _oTextColour)
{
	m_oButtonShape.setSize(_v2fSize);
	m_oButtonShape.setOrigin(m_oButtonShape.getGlobalBounds().width / 2, m_oButtonShape.getGlobalBounds().height / 2);
	m_oButtonShape.setPosition(_v2fPosition);
	m_eButtonType = _eButtonType;
	m_poButtonText = new CUIText(14, _v2fPosition, _sButtonText, _oTextColour);
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

	m_poButtonText->Render(_poWindow);
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
		CPageManager::GetInstance()->IncrementCurrentPage();
	}

	else if (m_eButtonType == EButtonType::PrevPage)
	{
		CPageManager::GetInstance()->DecrementCurrentPage();
	}

	else if (m_eButtonType == EButtonType::SaveCollage)
	{
		CImageManager::GetInstance()->SaveCollage();
	}

	else if (m_eButtonType == EButtonType::LoadSmall)
	{
		//disabled
		//CImageManager::GetInstance()->SetLoadedImageList(EImageList::SmallList);
	}

	else if (m_eButtonType == EButtonType::LoadLarge)
	{
		//disabled
		//CImageManager::GetInstance()->SetLoadedImageList(EImageList::LargeList);
	}

	else if (m_eButtonType == EButtonType::Display1)
	{
		CImageManager::GetInstance()->SetImagesPerPage(1);
	}

	else if (m_eButtonType == EButtonType::Display4)
	{
		CImageManager::GetInstance()->SetImagesPerPage(4);
	}

	else if (m_eButtonType == EButtonType::Display9)
	{
		CImageManager::GetInstance()->SetImagesPerPage(9);
	}

	else if (m_eButtonType == EButtonType::Display16)
	{
		CImageManager::GetInstance()->SetImagesPerPage(16);
	}

	else if (m_eButtonType == EButtonType::Display25)
	{
		CImageManager::GetInstance()->SetImagesPerPage(25);
	}

	else if (m_eButtonType == EButtonType::Display36)
	{
		CImageManager::GetInstance()->SetImagesPerPage(36);
	}

	else if (m_eButtonType == EButtonType::Display49)
	{
		CImageManager::GetInstance()->SetImagesPerPage(49);
	}

	else if (m_eButtonType == EButtonType::Display64)
	{
		CImageManager::GetInstance()->SetImagesPerPage(64);
	}

	else if (m_eButtonType == EButtonType::Quit)
	{
		CWindowManager::GetInstance()->GetMainWindow()->close();
	}
}