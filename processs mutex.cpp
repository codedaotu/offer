'
多个线程同时对同一变量进行操作的时候，如果不对变量做一些保护处理，有可能导致处理结果异常
1、内核对象互斥体（Mutex）的工作机理，WaitForSingleObject函数的用法，这些可以从MSDN获取详情； 
2、当两个或更多线程需要同时访问一个共享资源时，系统需要使用同步机制来确保一次只有一个线程使用该资源。
Mutex 是同步基元，它只向一个线程授予对共享资源的独占访问权。如果一个线程获取了互斥体，则要获取该互斥体的第二个线程将被挂起，直到第一个线程释放该互斥体。 
#include <iostream>
#include <thread>
#include <Windows.h>
using namespace std;
int totalNum = 100;
void thread01()
{
	while (totalNum > 0)
	{
		cout << totalNum << endl;
		totalNum--;
		Sleep(100);
	}
}
void thread02()
{
	while (totalNum > 0)
	{
		cout << totalNum << endl;
		totalNum--;
		Sleep(100);
	}
}

int main()
{
	thread task01(thread01);
	thread task02(thread02);
	task01.detach();
	task02.detach();
	system("pause");
}
'
#include <iostream>
#include <thread>
#include <Windows.h>
#include <mutex>
using namespace std;
mutex mu;  //线程互斥对象
int totalNum = 100;
void thread01()
{
	while (totalNum > 0)
	{
		mu.lock(); //同步数据锁
		cout << totalNum << endl;
		totalNum--;
		Sleep(100);
		mu.unlock();  //解除锁定
	}
}
void thread02()
{
	while (totalNum > 0)
	{
		mu.lock();
		cout << totalNum << endl;
		totalNum--;
		Sleep(100);
		mu.unlock();
	}
}
int main()
{
	thread task01(thread01);
	thread task02(thread02);
	task01.detach();
	task02.detach();
	system("pause");
}