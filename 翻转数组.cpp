#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int main()
{
	int n,k;
	cin>>n;
	vector<int> arr1;
	vector<int> arr2;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		arr1.push_back(k);
	}
	arr2.assign(arr1.begin(),arr1.end());
	sort(arr1,arr1+n);
	int end=n-1;
	int start=0;
	while(start<n&&arr1[start]==arr2[start])start++;
	while(end>=0&&arr1[end]==arr2[end])end--;
	bool p=true;
	while(start<end)
	{
		if(arr1[start]!=arr2[end])
		{
			p=false;
			break;
		}
		start++,end--;
	}
	if(p)
		cout<<"yes"<<endl;
	else  cout<<"no"<<endl;
	return 0;
}