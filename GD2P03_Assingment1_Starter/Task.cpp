#include "Task.h"

CTask::CTask(CDownloader* _poDownloader, std::string* _psURL, std::string* _psOutput)
{
	m_poDownloader = _poDownloader;
	m_psURL = _psURL;
	m_psOutput = _psOutput;
}

CTask::~CTask() {}