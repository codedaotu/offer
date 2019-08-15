#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int main()
{
	union w
	{
		int a;
		char b;
	}c;
	c.a=1;
	cout<<(c.b==1);
	/* code */
	return 0;
}