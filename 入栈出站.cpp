#include<iostream>
#include<vector>
#include<stack>
using namespace std;
bool stack_sequence(vector<int>& pushed, vector<int>& popped)
{
	stack<int> a;
	int j,i=0;
	while(i<pushed.size())
	{
		a.push(pushed[i++]);
		while(!a.empty()&&a.top()==popped[j])//先判断是否为空，若为空就没有top，如果先判断top会报错。
		{
			j++;
			a.pop();
		}
	}
	return a.empty();
}
int main()
{
	return 0；
}