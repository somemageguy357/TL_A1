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
			CreateButtons();
		}

		return m_poInstance;
	}

	void Update(sf::RenderWindow* _poWindow, bool _bIsClicking);

	void Render(sf::RenderWindow* _poWindow);

private:
	static CUIManager* m_poInstance;

	static std::vector<CUIButton*> m_oVecButtonPtrs;

	CUIManager();
	~CUIManager();

	static void CreateButtons();
};