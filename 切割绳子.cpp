#include<iostream>
using namespace std;
const int N = 100010;
int n,m;
int a[N];
bool check(double mid)
{
	int num=0;
	for(int i=0;i<n;i++)
	{
		num+=a[i]/mid;
		if(num>=m)
			return true;	
	}
	return false;
}
int main()
{
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	double left=0,right=100000;
	while(right-left>1e-4)
	{
		double mid=(right+left)/2;
		if(check(mid))
			left=mid;
		else
			right=mid;
	}
	cout<<right;
	return 0;
}