#include <queue>
#include <mutex>

template<typename T>
class CSafeQueue
{
public:
	CSafeQueue() {}
	~CSafeQueue() {}

	void Push(const T& _oValue);
	bool Pop(T& _oValue);

	bool BlockPop(T& _oValue);

	void UnblockAll();

private:
	std::queue<T> m_oQueue;
	std::mutex m_oMutex;
	std::condition_variable m_oCondVar;
	std::atomic_bool m_bEscape;
};

template<typename T>
inline void CSafeQueue<T>::Push(const T& _oValue)
{
	std::lock_guard<std::mutex> oLock(m_oMutex);
	m_oQueue.push(_oValue);
	m_oCondVar.notify_one();
}

template<typename T>
inline bool CSafeQueue<T>::Pop(T& _oValue)
{
	std::lock_guard<std::mutex> oLock(m_oMutex);

	if (m_oQueue.empty() == true)
	{
		return false;
	}

	_oValue = m_oQueue.front();
	m_oQueue.pop();

	return true;
}

template<typename T>
inline bool CSafeQueue<T>::BlockPop(T& _oValue)
{
	std::unique_lock<std::mutex> oLock(m_oMutex);

	m_oCondVar.wait(oLock, [this] { return (m_oQueue.empty() == false || m_bEscape == true); });

	if (m_bEscape == false)
	{
		_oValue = std::move(m_oQueue.front());
		m_oQueue.pop();
	}

	return !m_bEscape;
}

template<typename T>
inline void CSafeQueue<T>::UnblockAll()
{
	m_bEscape = true;
	m_oCondVar.notify_all();
}