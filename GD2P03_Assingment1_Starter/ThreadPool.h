#include "Task.h"
#include "SafeQueue.h"

#include <thread>
#include <vector>
#include <atomic>

class CThreadPool
{
public:
	CThreadPool();
	~CThreadPool();

	void Submit(CTask _oTask);
	void Stop();

	int GetTaskProcessed();

private:
	std::vector<std::thread> m_oVecThreads;
	CSafeQueue<CTask> m_oTaskQueue;

	std::atomic_bool m_bFinished;
	std::atomic_int m_iTasksProcessed;
	unsigned int m_uiThreadCount;

	void WorkerThread();
};