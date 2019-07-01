#include<iostream>
using namespace std;
#include<set>
#include<queue>
#include<vector>
int d[1000][1000]={0};
int dp[1000]={0};
int val[1000],we[1000];
//0-1背包,输入数据前面要补零。容量倒序遍历。
int max(int x,int y)
{
	if (x>y)
		return x;
	else
		return y;
}
int bag_01(int nums,int capacity,int vals[],int weights[])
{	
	for(int i=1;i<=nums;i++)
	{
		for(int j=capacity;j>=weights[i];j--)
		{		
			d[i][j]=max(d[i-1][j],d[i-1][j-weights[i]]+vals[i]);
		}
	}
	return d[nums][capacity];
}

int bag_01_v2(int nums,int capacity,int vals[],int weights[])
{	
	for(int i=1;i<=nums;i++)
	{
		for(int j=capacity;j>=weights[i];j--)
		{		
			dp[j]=max(dp[j],dp[j-weights[i]]+vals[i]);
		}
	}
	return dp[capacity];
}


//完全背包，容量正序遍历
int bag_complete(int nums,int capacity,int vals[],int weights[])
{
	for(int i=1;i<=nums;i++)
	{
		for(int j=weights[i];j<=capacity;j++)
		{		
			dp[j]=max(dp[j],dp[j-weights[i]]+vals[i]);
		}
	}
	return dp[capacity];
}
//多重背包。其实就是拆成0-1背包，0-1是只有一个，1,4,5。多重就是1,1,4，4,5。但是会超时，所以用二进制优化。将原包的数据分别打包，1,2,4，。。。二进制分割。
//添加到新val和weight 列表
int bag_multi(int n,int nums[],int capacity,int vals[],int weights[])
{
	int i=0,j=0,t=0;
	for( i =0;i<n;i++)
	{
		for ( j = 1; j <= nums[i]; j=j*2)
		{
			val[t]=j*vals[i];
			we[t]=j*weights[i];
			nums[i]=nums[i]-j;
			t++;
		}
		//若有剩余。。。。
		if(nums[i]>0)
		{
			val[t]=nums[i]*vals[i];
			we[t]=nums[i]*weights[i];
			t++; 
		}
	}
	for (int i = 0; i < t; ++i)
	{
		for (int j = capacity; j>=we[i]; j--)
		{
			dp[j]=max(dp[j],dp[j-we[i]]+val[i]);
		}
	}
	return dp[capacity];
}
int main()
{
	int weights[]={0,2,2,6,5,4};
	int vals[]={0,6,3,5,4,6};
	int weights2[]={0,1,4,6};
	int vals2[]={0,3,5,8};
	int capacity=10;
	int numslist[]={3,4,5};
	//cout<<bag_01_v2(5,capacity,vals,weights);
	//cout<<bag_complete(3,capacity,vals2,weights2);
	cout<<bag_multi(3,numslist,10,vals2,weights2);
}