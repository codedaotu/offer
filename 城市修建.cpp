#include<iostream>
using namespace std;
#include<algorithm>
long long x[1001]={0};
long long y[1001]={0};
int main()
{
	int nums;
	cin>>nums;
	for(int i=0;i<nums;i++)
	{
		cin>>x[i]>>y[i];
	}
	sort(x,x+nums);
	sort(y,y+nums);
	long long len=y[nums-1]-y[0];
	long long wid=x[nums-1]-x[0];
	int res=max(len,wid);
	cout<<res*res;
	return 0;
}