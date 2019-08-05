#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int N=1e5+10;
int a[N];
int main()
{
	int nums;
	cin>>nums;
	while(nums--)
	{
		cout<<nums;
		int n;
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		swap(a[n-1],a[n-2]);
		bool k=true;
		for( int i =0;i<n;i++)
		{
			int pre=(i-1+n)%n;
			int sub=(i+1)%n;
			if(a[pre]+a[sub]<=a[i]) k=false;
		}
	if(k) puts("yes");
	else puts("false");
	}
	return 0;
}