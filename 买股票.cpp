#include<iostream>
using namespace std;
#include<vector>
'''
如果你最多只允许完成一笔交易（即买入和卖出一支股票）
 dp0表示手上没有股票。初始为0。dp1表示手上有，dp[-1][1] = -infinity
解释：还没开始的时候，是不可能持有股票的，用负无穷表示这种不可能。
'''
int stock1(vector<int> &prices)
{

	int dp0=0,dp1=-100000000;
	for (int i = 0; i < prices.size(); ++i)
	{
		dp0=max(dp0,dp1+prices[i]);//（昨天就没有：昨天有，卖掉了）
        dp1=max(dp1,-prices[i]);
    //（昨天有：昨天没有，今天刚买的所以减去,因为只能买卖一次，
    //所当手里没股票时，就说明之前没有买，所以积累的是0元）
	}
	return dp0;
}
int stock_inf(vector<int> &prices)
'''
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）

'''
{
	int dp0=0,dp1=-100000000;
	for (int i = 0; i < prices.size(); ++i)
	{
		int t=dp0;
		dp0=max(dp0,dp1+prices[i]);//（昨天就没有：昨天有，卖掉了）
        dp1=max(dp1,t-prices[i]);
//（昨天有：昨天没有，今天刚买的所以减去，由于只能在没持有股票的情况下购买，所以是dp0）
 //不同于第一题是因为可以买卖多次，所以即便是手里没股票还有之前盈利的。而买卖一次时，手里没股票就意味着还么有买，也就是0。
	}
	return dp0;

}
int stock_freeze(vector<int> &prices)
'''
你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
dp0 不变。但是dp1是两天前买的，不是昨天买的

'''
{
	int dp0=0,dp1=-100000000,dpt=0;
	for (int i = 0; i < prices.size(); ++i)
	{
		int t=dp0;
		dp0=max(dp0,dp1+prices[i]);
        dp1=max(dp1,dpt-prices[i]);
        dpt=t;
	}
	return dp0;
}

int stock_freeze_fee(vector<int> &prices,int fee)
'''
你可以无限次地完成交易，但是你每次交易都需要付手续费。
如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

'''
{
	int dp0=0,dp1=-100000000,dpt=0;
	for (int i = 0; i < prices.size(); ++i)
	{
		int t=dp0;
		dp0=max(dp0,dp1+prices[i]);
        dp1=max(dp1,t-prices[i]-fee);
	}
	return dp0;
}
