#include "Downloader.h"

bool CDownloader::m_globalInit = false;

CDownloader::CDownloader()
{
}

CDownloader::~CDownloader()
{
	curl_easy_cleanup(m_curl);
}

void CDownloader::Init()
{
	if (CDownloader::m_globalInit == false)
	{
		curl_global_init(CURL_GLOBAL_DEFAULT);
		CDownloader::m_globalInit = true;
	}
}

bool CDownloader::Download(const char* _url, std::string& _outputStr)
{
	//This is the curl handle, each thread should have its own handle.
	m_curl = curl_easy_init();
	if (m_curl)
	{
		CURLcode res;
		curl_easy_setopt(m_curl, CURLOPT_URL, _url);
		curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, CDownloader::WriteData);
		curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, &_outputStr);
		curl_easy_setopt(m_curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
		//curl_easy_setopt(m_curl, CURLOPT_VERBOSE, 1L); //uncomment for verbose messages, good for debug
		res = curl_easy_perform(m_curl);
		if (res != CURLE_OK)
		{
			std::cerr << " CURL error: " << res << "\n";
		}
		curl_easy_cleanup(m_curl);
		return res == CURLE_OK;
	}
	return false;
}

size_t CDownloader::WriteData(void* _buffer, size_t _size, size_t _nmemb, void* _param)
{
	std::string& text = *static_cast<std::string*>(_param);
	size_t totalsize = _size * _nmemb;
	text.append(static_cast<char*>(_buffer), totalsize);
	return totalsize;
}
