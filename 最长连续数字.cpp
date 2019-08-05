#include<iostream>
using namespace std;
#include<vector>
int longest_1(vector<int> &a)
{
	vector<int> dp(a.size(),1);
	int k=1;
	for (int i = 1; i < a.size(); i++)
	{
		if(a[i]==a[i-1])dp[i]=max(dp[i-1],++k);
		else 
			{
				dp[i]=dp[i-1];
				k=1;
			}
		cout<<dp[i]<<endl;
	}
	cout<<dp[a.size()-1];
	return 0;
}
int main()
{
	vector<int> a={1,2,3,4,1,1,1,0,0,9,9,9,9,9,1,1,1,1};
	//vector<int> a={1,2};
	longest_1(a);
	return 0;
}