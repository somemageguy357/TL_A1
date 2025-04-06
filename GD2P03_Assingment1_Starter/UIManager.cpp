#include "UIManager.h"

CUIManager* CUIManager::m_poInstance = nullptr;
std::vector<CUIButton*> CUIManager::m_oVecButtonPtrs(14);
std::vector<CUIText*> CUIManager::m_oVecTextPtrs(2);
CUIText* CUIManager::m_poPageNumberText = nullptr;
sf::Font* CUIManager::m_poUIFont = nullptr;

CUIManager::CUIManager() {}

CUIManager::~CUIManager() {}

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

	for (size_t i = 0; i < m_oVecTextPtrs.size(); i++)
	{
		m_oVecTextPtrs[i]->Render(_poWindow);
	}
}

void CUIManager::UpdatePageNumberText(int _iCurrentPage, int _iMaxPage)
{
	m_poPageNumberText->SetString(std::to_string(_iCurrentPage) + "/" + std::to_string(_iMaxPage));
}

sf::Font* CUIManager::GetUIFont()
{
	return m_poUIFont;
}

void CUIManager::CreateUIElements()
{
	m_poUIFont = new sf::Font();
	m_poUIFont->loadFromFile("Fonts/Roboto-Light.ttf");

	CUIButton* poNextPageBtn = new CUIButton({ 40.0f, 20.0f }, { 350.0f, 810.0f }, EButtonType::PrevPage, "Prev");
	m_poPageNumberText = new CUIText(14, { 400.0f, 810.0f }, "1/1", sf::Color::White);
	CUIButton* poPrevPageBtn = new CUIButton({ 40.0f, 20.0f }, { 450.0f, 810.0f }, EButtonType::NextPage, "Next");

	CUIButton* poSaveCollageBtn = new CUIButton({ 80.0f, 20.0f }, { 50.0f, 810.0f }, EButtonType::SaveCollage, "Save Image");

	CUIButton* poLoadLargeBtn = new CUIButton({ 80.0f, 20.0f }, { 50.0f, 850.0f }, EButtonType::LoadLarge, "Large List");
	CUIButton* poLoadSmallBtn = new CUIButton({ 80.0f, 20.0f }, { 50.0f, 880.0f }, EButtonType::LoadSmall, "Small List");

	CUIText* poImagesPerPageText = new CUIText(14, { 732.0f, 826.0f }, "Images Per Page:", sf::Color::White);
	CUIButton* poDisplay1Btn = new CUIButton({ 20.0f, 20.0f }, { 690.0f, 850.0f }, EButtonType::Display1, "1");
	CUIButton* poDisplay4Btn = new CUIButton({ 20.0f, 20.0f }, { 720.0f, 850.0f }, EButtonType::Display4, "4");
	CUIButton* poDisplay9Btn = new CUIButton({ 20.0f, 20.0f }, { 750.0f, 850.0f }, EButtonType::Display9, "9");
	CUIButton* poDisplay16Btn = new CUIButton({ 20.0f, 20.0f }, { 780.0f, 850.0f }, EButtonType::Display16, "16");
	CUIButton* poDisplay25Btn = new CUIButton({ 20.0f, 20.0f }, { 690.0f, 880.0f }, EButtonType::Display25, "25");
	CUIButton* poDisplay36Btn = new CUIButton({ 20.0f, 20.0f }, { 720.0f, 880.0f }, EButtonType::Display36, "36");
	CUIButton* poDisplay49Btn = new CUIButton({ 20.0f, 20.0f }, { 750.0f, 880.0f }, EButtonType::Display49, "49");
	CUIButton* poDisplay64Btn = new CUIButton({ 20.0f, 20.0f }, { 780.0f, 880.0f }, EButtonType::Display64, "64");

	CUIButton* poQuitBtn = new CUIButton({ 50.0f, 20.0f }, { 400.0f, 880.0f }, EButtonType::Quit, "Close");

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

	m_oVecTextPtrs[0] = m_poPageNumberText;
	m_oVecTextPtrs[1] = poImagesPerPageText;
}