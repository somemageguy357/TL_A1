/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : Task.h
Description : A task that is performed during thread pools.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include "Downloader.h"

#include <iostream>
#include <thread>
#include <vector>

class CTask
{
public:
	CTask() = delete;

	/// <summary>
	/// Creates a task that is used in a threadpool.
	/// </summary>
	/// <param name="_psURL:">The URL of the image to download from.</param>
	/// <param name="_psOutput:">String used to load images from memory.</param>
	CTask(std::string* _psURL, std::string* _psOutput);

	~CTask();

	/// <summary>
	/// Downloads the image using the downloader and outputs the string to load the memory from.
	/// </summary>
	void DoWork()
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