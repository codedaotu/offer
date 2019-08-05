#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int nums,times;
	cin>>nums>>times;
	int dp[31][31]={0};
	dp[1][1]=1;
	dp[1][nums-1]=1;
	for (int i = 2; i <= nums; ++i)
	{
		for (int j = 0; i < times; ++j)
		{
			dp[i][j]=dp[i-1][(n-1-j)%n]+dp[i-1][(n+1-j)%n];
		}
	}
	cout<<dp[nums][0];
	return 0;
}