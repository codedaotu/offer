#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> arr(n+1,0);
	for(int i=2;i<=n;i++)
		arr[i]=(arr[i-1]+m)%i;
	cout<<arr[n];
	return 0;
}