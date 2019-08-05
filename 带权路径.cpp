#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int main()
{
	int n,t;
	priority_queue <long long,vector<long long>,greater<long long>> q;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		q.push(t);
	}
	long long sum=0;
	long long left=0;
	long long right=0;
	long long w=0;
	while(q.size()!=1)
	{
		left=q.top();
		q.pop();
		right=q.top();
		q.pop();
		w=left+right;
		sum+=w;
		q.push(w);
	}
	cout<<sum;
	return 0;
}