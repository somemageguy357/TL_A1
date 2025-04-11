/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : Task.cpp
Description : Contains function definitions for Task.h.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#include "Task.h"

CTask::CTask(std::string* _psURL, std::string* _psOutput)
{
	m_psURL = _psURL;
	m_psOutput = _psOutput;
}

CTask::~CTask() {}