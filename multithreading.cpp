#include <iostream>
#include <thread>
#include <Windows.h>
using namespace std;
void thread01()
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Thread 01 is working ！" << endl;
		Sleep(100);
	}
}
void thread02()
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Thread 02 is working ！" << endl;
		Sleep(200);
	}
}
int main()
{
	thread task01(thread01);
	thread task02(thread02);
	//join函数会阻塞主流程，所以子线程都执行完成之后才继续执行主线程。可以使用detach将子线程从主流程中分离，独立运行，不会阻塞主线程。

	task01.join();
	task02.join();

	for (int i = 0; i < 5; i++)
	{
		cout << "Main thread is working ！" << endl;
		Sleep(200);
	}
	system("pause");
}
