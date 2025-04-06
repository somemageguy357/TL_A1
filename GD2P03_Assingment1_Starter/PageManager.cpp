#include "PageManager.h"
#include "UIManager.h"
#include "ImageManager.h"

CPageManager* CPageManager::m_poInstance = nullptr;

CPageManager::CPageManager() {}

CPageManager::~CPageManager() {}

void CPageManager::SetMaxPages(unsigned int _uiMaxPages)
{
	m_uiMaxPages = _uiMaxPages;
	CUIManager::GetInstance()->UpdatePageNumberText(m_uiCurrentPage, m_uiMaxPages);

	if (m_uiCurrentPage > m_uiMaxPages)
	{
		SetCurrentPage(m_uiMaxPages);
	}
}

unsigned int CPageManager::GetMaxPages()
{
	return m_uiMaxPages;
}

void CPageManager::SetCurrentPage(unsigned int _uiCurrentPage)
{
	if (_uiCurrentPage < m_uiMaxPages && _uiCurrentPage > 1)
	{
		m_uiCurrentPage = _uiCurrentPage;
		CUIManager::GetInstance()->UpdatePageNumberText(m_uiCurrentPage, m_uiMaxPages);
		CImageManager::GetInstance()->RepositionImages();
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