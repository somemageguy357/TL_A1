#pragma once
#include "SFML/Graphics.hpp"

#include "UIButton.h"

#include <vector>

class CUIManager
{
public:
	static CUIManager* GetInstance()
	{
		if (m_poInstance == nullptr)
		{
			m_poInstance = new CUIManager();
			CreateUIElements();
		}

		return m_poInstance;
	}

	void Update(sf::RenderWindow* _poWindow, bool _bIsClicking);

	void Render(sf::RenderWindow* _poWindow);

	void UpdatePageNumberText(int _iCurrentPage, int _iMaxPage);

	sf::Font* GetUIFont();

private:
	static CUIManager* m_poInstance;

	static std::vector<CUIButton*> m_oVecButtonPtrs;
	static std::vector<CUIText*> m_oVecTextPtrs;
	static CUIText* m_poPageNumberText;

	static sf::Font* m_poUIFont;

	CUIManager();
	~CUIManager();

	static void CreateUIElements();
};