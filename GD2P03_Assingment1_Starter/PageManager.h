/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : PageManager.h
Description : Manages the page variables that are used to display different sets of images to the window.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

class CPageManager
{
public:
	/// <summary>
	/// Gets the singleton instance of CPageManager.
	/// </summary>
	/// <returns>A pointer to the CPageManager singleton.</returns>
	static CPageManager* GetInstance()
	{
		if (m_poInstance == nullptr)
		{
			m_poInstance = new CPageManager();
		}

		return m_poInstance;
	}

	/// <summary>
	/// Sets the max number of pages.
	/// </summary>
	/// <param name="_uiMaxPages:">The max number of pages.</param>
	void SetMaxPages(unsigned int _uiMaxPages);
	
	/// <summary>
	/// Gets the max number of pages.
	/// </summary>
	/// <returns>The max number of pages.</returns>
	unsigned int GetMaxPages();

	/// <summary>
	/// Sets the current page.
	/// </summary>
	/// <param name="_uiCurrentPage:">The current page.</param>
	void SetCurrentPage(unsigned int _uiCurrentPage);

	/// <summary>
	/// Gets the current page.
	/// </summary>
	/// <returns>The current page.</returns>
	unsigned int GetCurrentPage();

	/// <summary>
	/// Increments the current page if it is not currently equal to the max page number.
	/// </summary>
	void IncrementCurrentPage();

	/// <summary>
	/// Decrements the current page if it is not currently equal to 1.
	/// </summary>
	void DecrementCurrentPage();

private:
	static CPageManager* m_poInstance;

	unsigned int m_uiCurrentPage = 1;
	unsigned int m_uiMaxPages = 1;

	CPageManager();
	~CPageManager();
};