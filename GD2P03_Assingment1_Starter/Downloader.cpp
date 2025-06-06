#include "Downloader.h"

bool CDownloader::m_bGlobalInit = false;

CDownloader::CDownloader() {}

CDownloader::~CDownloader()
{
	curl_easy_cleanup(m_poCURL);
}

void CDownloader::Init()
{
	if (CDownloader::m_bGlobalInit == false)
	{
		curl_global_init(CURL_GLOBAL_DEFAULT);
		CDownloader::m_bGlobalInit = true;
	}
}

bool CDownloader::Download(const char* _pkcURL, std::string& _sOutput)
{
	//This is the curl handle, each thread should have its own handle.
	CURL* m_poCURL = curl_easy_init();

	if (m_poCURL)
	{
		CURLcode oRes;
		curl_easy_setopt(m_poCURL, CURLOPT_URL, _pkcURL);
		curl_easy_setopt(m_poCURL, CURLOPT_WRITEFUNCTION, CDownloader::WriteData);
		curl_easy_setopt(m_poCURL, CURLOPT_WRITEDATA, &_sOutput);
		curl_easy_setopt(m_poCURL, CURLOPT_USERAGENT, "libcurl-agent/1.0");
		//curl_easy_setopt(poCURL, CURLOPT_VERBOSE, 1L); //uncomment for verbose messages, good for debug
		oRes = curl_easy_perform(m_poCURL);

		if (oRes != CURLE_OK)
		{
			std::cerr << " CURL error: " << oRes << "\n";
		}

		curl_easy_cleanup(m_poCURL);

		return oRes == CURLE_OK;
	}
	return false;
}

size_t CDownloader::WriteData(void* _funcBuffer, size_t _iSize, size_t _iNmemb, void* _funcParam)
{
	std::string& text = *static_cast<std::string*>(_funcParam);
	size_t totalsize = _iSize * _iNmemb;
	text.append(static_cast<char*>(_funcBuffer), totalsize);
	return totalsize;
}
