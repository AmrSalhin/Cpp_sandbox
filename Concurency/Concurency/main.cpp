#include <iostream>
#include <thread>
#include <future>
#include <list>
#include <windows.h>
#include <chrono>


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

int Counter(std::promise<int> & promise)
{
	try
	{
		std::cout << "[Counter] Start Counting..." << std::endl;
		/*if exception occurs in the future, it will be propagated here and go to catch block*/
		auto size = promise.get_future().get();
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
			std::cout << ".";
			sum += i;
		}
		throw std::runtime_error("An error occurred in the Task thread");
		std::cout << "[Counter] Counting Finished" << std::endl;
		return sum;
	}
	catch(const std::exception& e)
	{
		std::cout << "[Task Thread] Exception: " << e.what() << std::endl;
		/*propagate the exception to the main thread*/
		throw;
	}
	
	
}

int main()
{
#pragma region Multithreading
	std::cout << "==================== Multithreading ====================" << std::endl;
	std::cout << "[Main] Start Accumulating..." << std::endl;
	std::packaged_task<long long(long long)> task(Accumelate);
	auto future = task.get_future();
	std::thread accumelateThread(std::move(task), FILE_SIZE);
	/*set name to the thread*/
	SetThreadDescription(accumelateThread.native_handle(), L"Accumelate Thread");
	std::cout << "[Main] Do Other Work..." << std::endl;
	std::cout << "optimum number of threads: " << std::thread::hardware_concurrency() << std::endl;
	std::cout << "The result is: " << future.get() << std::endl;
	accumelateThread.join();
	std::cout << "=========================================================" << std::endl;
#pragma endregion
	
#pragma region mutex

	std::cout << "==================== Mutex ====================" << std::endl;
	std::thread t1(AddToList1);
	std::thread t2(AddToList2);
	t1.join();
	t2.join();
	std::cout << "List Size: " << myList.size() << std::endl;
	std::cout << "=========================================================" << std::endl;
#pragma endregion
	
#pragma region Task
	/*launch policy async*/
	/*std::cout << "==================== Async Task ====================" << std::endl;
	std::future<void> downloadFuture = std::async(std::launch::async, DownloadFile);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "[Main] Do Other Work..." << std::endl;*/
	//if(downloadFuture.valid())
	//{
	//	downloadFuture.get();
	//}

	///*launch policy deferred which means the function will be called when get() is invoked*/
	//std::future<void> downloadFuture2 = std::async(std::launch::deferred, DownloadFile);
	//std::this_thread::sleep_for(std::chrono::seconds(1));
	//std::cout << "[Main] Do Other Work..." << std::endl;
	//if(downloadFuture2.valid())
	//{
	//	downloadFuture2.get();
	//}
	//std::cout << "=========================================================" << std::endl;
#pragma endregion

#pragma region Future functions
	// std::cout << "==================== Future Functions ====================" << std::endl;
	// std::future<void> downloadFuture3 = std::async(std::launch::async, DownloadFile);
	// std::this_thread::sleep_for(std::chrono::seconds(1));
	// std::cout << "[Main] Do Other Work..." << std::endl;
	// if(downloadFuture3.valid())
	// {
	// 	// wait for the download to finish
	// 	// std::cout << "Waiting for the download to finish..." << std::endl;
	// 	// downloadFuture3.wait(); 
	// 	/*wait for time and check the status*/
	// 	// switch(downloadFuture3.wait_for(std::chrono::seconds(3)))
	// 	// {
	// 		// case std::future_status::ready:
	// 		// 		std::cout << "Download finished!" << std::endl;
	// 		// 		break;
	// 		// 	case std::future_status::timeout:
	// 		// 		std::cout << "Download not finished yet!" << std::endl;
	// 		// 		break;
	// 		// 	case std::future_status::deferred:
	// 		// 		std::cout << "Download deferred!" << std::endl;
	// 		// 		downloadFuture3.get();
	// 		// 		break;
	// 		// }
	// 		/*wait until a specific time*/
	// 	auto timePoint = std::chrono::system_clock::now() + std::chrono::seconds(1);
	// 	switch(downloadFuture3.wait_until(timePoint))
	// 	{
	// 	case std::future_status::ready:
	// 			std::cout << "Download finished!" << std::endl;
	// 			break;
	// 		case std::future_status::timeout:
	// 			std::cout << "Download not finished yet!" << std::endl;
	// 			break;
	// 		case std::future_status::deferred:
	// 			std::cout << "Download deferred!" << std::endl;
	// 			downloadFuture3.get();
	// 			break;
	// 	}
	// }

	// std::cout << "=========================================================" << std::endl;	
#pragma endregion

#pragma region Promise
	std::cout << "==================== Promise ====================" << std::endl;
	std::promise<int> data;
	std::future<int> futureResult = std::async(std::launch::async, Counter, std::ref(data));
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "[Main] do work..." << std::endl;
	/*Task wait for promise to be set*/
	// data.set_value(10);

	/*Exception propagation*/
	try
	{
		/*throw an exception*/
		// throw std::runtime_error("An error occurred in the main thread");
		data.set_value(10);
		futureResult.get();
	}
	catch (const std::exception& e)
	{
		/*propagate the exception to the task that have the promise*/
		data.set_exception(std::make_exception_ptr(e));
		std::cout << "[Main] Exception: " << e.what() << std::endl;
	}
	std::cout << "=========================================================" << std::endl;
#pragma endregion
	return 0;
}