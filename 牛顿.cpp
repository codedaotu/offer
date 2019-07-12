#include<iostream>
using namespace std;
int main()
{
	float num;
	float x=num/2;
	cin>>num;
	while(abs(x*x-num)>0.0000001)
	{
		x=x/2+num/(2*x);
	}
	cout<<x;
	return 0;
}