
#include <iostream>
#include <thread>
#include <Windows.h>
#include <mutex>
#include <vector>
using namespace std;
mutex mu;
vector<int> a{0,1,2,3,4,5,6,7,8,9};
volatile int k=1;
int num=9;
void task1()
{
	while(num>=0)
	{
		mu.lock(); //同步数据锁
		cout <<"t1 "<<a[num] << endl;
		num--;
		Sleep(5);
		mu.unlock();  //解除锁定
	}
}
void task2()
{
	while(num>=0)
	{
		mu.lock(); //同步数据锁
		cout<<"t2 " << a[num] << endl;
		num--;
		Sleep(1);
		mu.unlock();  //解除锁定
	}
}
/*
void task_1()
{
	while(num>=0&&k==1)
	{
		cout<<"t1 " << a[num] << endl;
		num--;
		k=2;
	}
	
}
void task_2()
{
	while(num>=0&&k==2)
	{
		cout<<"t2 " << a[num] << endl;
		num--;
		k=1;
	}
	
}
*/
int main()
{
	thread task01(task1);
	thread task02(task2);
	task01.join();
	task02.join();
	return 0;
}