#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int len;
		cin>>len;
		int *rate=new int[len];
		for(int i=0;i<len;i++)
			cin>>rate[i];
		vector <int> nums(len,1);
		for(int i=1;i<len;i++)
		{
			if(rate[i]>rate[i-1])
				nums[i]=nums[i-1]+1;
		}
		for(int i=len-1;i>=0;i--)
		{
			if(rate[(i+1)%len]<rate[i])//
				nums[i]=max(nums[i],nums[(i+1)%len]+1);
		}
		int sum=0;
		for (int i = 0; i < len; ++i)
		{
			sum+=nums[i];
		}
		cout<<sum<<endl;
		delete []rate;
	}
	return 0;
}

