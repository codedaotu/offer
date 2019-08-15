#include <iostream>
#include <thread>
#include <Windows.h>
using namespace std;
int main()
{
	int a=1;
	int &b=a;
	int *c=&a;
	cout<<"a="<<&a<<" b="<<&b<<" c="<<c;
	return 0;
}