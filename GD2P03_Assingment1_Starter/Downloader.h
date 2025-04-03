#pragma once

#define CURL_STATICLIB //removing this will give link warnings
#include <curl/curl.h>

#include <string.h>
#include <iostream>

/*This is a class which uses libcurl to download data from a url to string.
	The init function should be called before downloading. 
	A unique instance should be used per thread. m_curl is your handle and you must never share the handle across threads. 
	Read more on libcurl thread safety here: https://curl.se/libcurl/c/threadsafe.html

	Feel free to modify this class for expanding functionality.
*/
class CDownloader
{
public:
	CDownloader();
	~CDownloader();
	void Init();

	/// <summary>
	/// A blocking function which downloads data from a url.
	/// </summary>
	/// <param name="_url">The url to download from</param>
	/// <param name="_outputStr">The data that was downloaded</param>
	/// <returns>Returns true for a successful download.</returns>
	bool Download(const char * _pkcURL, std::string& _sOutput);

private:
	CURL* m_oCURL = nullptr; //handle
	static bool m_bGlobalInit;

	/// <summary>
	/// This function is used by Download() for writing data.
	/// </summary>
	static size_t WriteData(void* _funcBuffer, size_t _iSize, size_t _iNmemb, void* _funcParam);

};