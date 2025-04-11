#include "Task.h"

CTask::CTask(std::string* _psURL, std::string* _psOutput)
{
	m_psURL = _psURL;
	m_psOutput = _psOutput;
}

CTask::~CTask() {}