#include "UIManager.h"

CUIManager* CUIManager::m_poInstance = nullptr;
std::vector<CUIButton*> CUIManager::m_oVecButtonPtrs(14);

CUIManager::CUIManager()
{
}

CUIManager::~CUIManager()
{
}

void CUIManager::Update(sf::RenderWindow* _poWindow, bool _bIsClicking)
{
	for (size_t i = 0; i < m_oVecButtonPtrs.size(); i++)
	{
		m_oVecButtonPtrs[i]->Update(_poWindow, _bIsClicking);
	}
}

void CUIManager::Render(sf::RenderWindow* _poWindow)
{
	for (size_t i = 0; i < m_oVecButtonPtrs.size(); i++)
	{
		m_oVecButtonPtrs[i]->Render(_poWindow);
	}
}

void CUIManager::CreateButtons()
{
	CUIButton* poNextPageBtn = new CUIButton({ 40.0f, 40.0f }, { 10.0f, 800.0f }, EButtonType::NextPage);
	CUIButton* poPrevPageBtn = new CUIButton({ 40.0f, 40.0f }, { 70.0f, 800.0f }, EButtonType::PrevPage);
	CUIButton* poSaveCollageBtn = new CUIButton({ 40.0f, 40.0f }, { 130.0f, 800.0f }, EButtonType::SaveCollage);
	CUIButton* poLoadLargeBtn = new CUIButton({ 40.0f, 40.0f }, { 190.0f, 800.0f }, EButtonType::LoadLarge);
	CUIButton* poLoadSmallBtn = new CUIButton({ 40.0f, 40.0f }, { 250.0f, 800.0f }, EButtonType::LoadSmall);
	CUIButton* poDisplay1Btn = new CUIButton({ 40.0f, 40.0f }, { 310.0f, 800.0f }, EButtonType::Display1);
	CUIButton* poDisplay4Btn = new CUIButton({ 40.0f, 40.0f }, { 370.0f, 800.0f }, EButtonType::Display4);
	CUIButton* poDisplay9Btn = new CUIButton({ 40.0f, 40.0f }, { 430.0f, 800.0f }, EButtonType::Display9);
	CUIButton* poDisplay16Btn = new CUIButton({ 40.0f, 40.0f }, { 490.0f, 800.0f }, EButtonType::Display16);
	CUIButton* poDisplay25Btn = new CUIButton({ 40.0f, 40.0f }, { 550.0f, 800.0f }, EButtonType::Display25);
	CUIButton* poDisplay36Btn = new CUIButton({ 40.0f, 40.0f }, { 610.0f, 800.0f }, EButtonType::Display36);
	CUIButton* poDisplay49Btn = new CUIButton({ 40.0f, 40.0f }, { 670.0f, 800.0f }, EButtonType::Display49);
	CUIButton* poDisplay64Btn = new CUIButton({ 40.0f, 40.0f }, { 730.0f, 800.0f }, EButtonType::Display64);
	CUIButton* poQuitBtn = new CUIButton({ 40.0f, 40.0f }, { 790.0f, 800.0f }, EButtonType::Quit);

	m_oVecButtonPtrs[0] = poNextPageBtn;
	m_oVecButtonPtrs[1] = poPrevPageBtn;
	m_oVecButtonPtrs[2] = poSaveCollageBtn;
	m_oVecButtonPtrs[3] = poLoadLargeBtn;
	m_oVecButtonPtrs[4] = poLoadSmallBtn;
	m_oVecButtonPtrs[5] = poDisplay1Btn;
	m_oVecButtonPtrs[6] = poDisplay4Btn;
	m_oVecButtonPtrs[7] = poDisplay9Btn;
	m_oVecButtonPtrs[8] = poDisplay16Btn;
	m_oVecButtonPtrs[9] = poDisplay25Btn;
	m_oVecButtonPtrs[10] = poDisplay36Btn;
	m_oVecButtonPtrs[11] = poDisplay49Btn;
	m_oVecButtonPtrs[12] = poDisplay64Btn;
	m_oVecButtonPtrs[13] = poQuitBtn;
}