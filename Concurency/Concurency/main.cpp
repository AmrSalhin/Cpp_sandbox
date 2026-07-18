#include <iostream>
#include <thread>
#include <future>
#include <list>
#include <windows.h>


const long long FILE_SIZE = 1000000000;

long long Accumelate(int size)
{
std::cout << "[Accumelate] Start Accumulating..." << std::endl;
long long sum = 0;
for (long long i = 0; i < size; i++)
{
	sum += i;
}
std::cout << "[Accumelate] Accumulation Finished" << std::endl;
return sum;
}

std::list<int> myList;
std::mutex mtx;

void AddToList1(void)
{
	for (int i = 0; i < 10000; i++)
	{
		/*lock guard destructor will unlock the mutex RAII*/
		std::lock_guard<std::mutex> lock(mtx);
		myList.push_back(i);
	}
}

void AddToList2(void)
{
	for (int i = 0; i < 10000; i++)
	{
		/*lock guard destructor will unlock the mutex RAII*/
		std::lock_guard<std::mutex> lock(mtx);
		myList.push_back(i);
	}
}

void DownloadFile(void)
{
	std::cout << "[DownloadFile] Start Downloading..." << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << ".";
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
	std::cout << "[DownloadFile] Download Finished" << std::endl;
}

int main()
{
#pragma region Multithreading
	//  std::cout << "[Main] Start Accumulating..." << std::endl;
	//  std::packaged_task<long long(long long)> task(Accumelate);
	//  auto future = task.get_future();
	//  std::thread accumelateThread(std::move(task), FILE_SIZE);
	//  /*set name to the thread*/
	//  SetThreadDescription(accumelateThread.native_handle(), L"Accumelate Thread");
	//  std::cout << "[Main] Do Other Work..." << std::endl;
	//  std::cout << "optimum number of threads: " << std::thread::hardware_concurrency() << std::endl;
	//  std::cout << "The result is: " << future.get() << std::endl;
	//  accumelateThread.join();
#pragma endregion
	
#pragma region mutex

	/*std::thread t1(AddToList1);
	std::thread t2(AddToList2);
	t1.join();
	t2.join();
	std::cout << "List Size: " << myList.size() << std::endl;*/
#pragma endregion
	
#pragma region Task
	/*launch policy async*/
	std::future<void> downloadFuture = std::async(std::launch::async, DownloadFile);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "[Main] Do Other Work..." << std::endl;
	if(downloadFuture.valid())
	{
		downloadFuture.get();
	}

	/*launch policy deferred which means the function will be called when get() is invoked*/
	std::future<void> downloadFuture2 = std::async(std::launch::deferred, DownloadFile);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "[Main] Do Other Work..." << std::endl;
	if(downloadFuture2.valid())
	{
		downloadFuture2.get();
	}

#pragma endregion

	return 0;
}