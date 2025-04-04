class CPageManager
{
public:
	static CPageManager* GetInstance()
	{
		if (m_poInstance == nullptr)
		{
			m_poInstance = new CPageManager();
		}

		return m_poInstance;
	}

	void SetMaxPages(unsigned int _uiMaxPages);
	
	unsigned int GetMaxPages();

	void SetCurrentPage(unsigned int _uiCurrentPage);

	unsigned int GetCurrentPage();

	void IncrementCurrentPage();

	void DecrementCurrentPage();

private:
	static CPageManager* m_poInstance;

	unsigned int m_uiCurrentPage = 1;
	unsigned int m_uiMaxPages = 1;

	CPageManager();
	~CPageManager();
};