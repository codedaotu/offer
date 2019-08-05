#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> two_stack(vector<int> numbers)
{
	int size=numbers.size();
	stack<int> s;
	stack<int> tmp;
	vector<int> res;
	for(int i=0;i<numbers.size();i++) s.push(numbers[i]);
	while(!s.empty())
	{
		int top = s.top();
		s.pop();
		if(tmp.empty()||top<tmp.top())
			tmp.push(top);
		else
		{
			while(!tmp.empty()&&top>tmp.top())
			{
				s.push(tmp.top());
				tmp.pop();
			}
			tmp.push(top);
		}
	}
	while(!tmp.empty())
	{
		s.push(tmp.top())
		tmp.pop();
	}
	while(!s.empty())
	{
		res.push_back(s.top());
		s.pop();
	}
	return res;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}