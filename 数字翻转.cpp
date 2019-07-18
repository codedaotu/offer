#include<iostream>
using namespace std;
#define MAX -2147483647
#define MIN 2147483647
int main()
{
	int n;
	cin>>n;
	long long res=0;
	while(n)
	{
		res=res*10+n%10;
		n=n/10;
	}
	if(res>=MAX||res<=MIN)
		return 0;
	cout<<(int)res;
	return 0;
}