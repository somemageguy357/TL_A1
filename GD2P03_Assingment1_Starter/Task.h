#include "Downloader.h"

#include <iostream>
#include <thread>
#include <vector>

class CTask
{
public:
	CTask() = delete;
	CTask(std::string* _psURL, std::string* _psOutput);
	~CTask();

	virtual void DoWork()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		CDownloader oDownloader;
		oDownloader.Init();
		oDownloader.Download(m_psURL->c_str(), *m_psOutput);
	}

private:
	std::string* m_psURL = nullptr;
	std::string* m_psOutput = nullptr;
};