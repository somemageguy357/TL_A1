/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : PageManager.cpp
Description : Contains function definitions for PageManager.h.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#include "PageManager.h"
#include "UIManager.h"
#include "ImageManager.h"

CPageManager* CPageManager::m_poInstance = nullptr;

CPageManager::CPageManager() {}

CPageManager::~CPageManager() {}

void CPageManager::SetMaxPages(unsigned int _uiMaxPages)
{
	m_uiMaxPages = _uiMaxPages;

	if (m_uiCurrentPage > m_uiMaxPages)
	{
		m_uiCurrentPage = m_uiMaxPages;
	}

	CUIManager::GetInstance()->UpdatePageNumberText(m_uiCurrentPage, m_uiMaxPages);
}

unsigned int CPageManager::GetMaxPages()
{
	return m_uiMaxPages;
}

void CPageManager::SetCurrentPage(unsigned int _uiCurrentPage)
{
	if (_uiCurrentPage < m_uiMaxPages && _uiCurrentPage > 0)
	{
		m_uiCurrentPage = _uiCurrentPage;
		CUIManager::GetInstance()->UpdatePageNumberText(m_uiCurrentPage, m_uiMaxPages);
	}
}

unsigned int CPageManager::GetCurrentPage()
{
	return m_uiCurrentPage;
}

void CPageManager::IncrementCurrentPage()
{
	if (m_uiCurrentPage < m_uiMaxPages)
	{
		m_uiCurrentPage += 1;
		CUIManager::GetInstance()->UpdatePageNumberText(m_uiCurrentPage, m_uiMaxPages);
		CImageManager::GetInstance()->RepositionImages();
	}
}

void CPageManager::DecrementCurrentPage()
{
	if (m_uiCurrentPage > 1)
	{
		m_uiCurrentPage -= 1;
		CUIManager::GetInstance()->UpdatePageNumberText(m_uiCurrentPage, m_uiMaxPages);
		CImageManager::GetInstance()->RepositionImages();
	}
}