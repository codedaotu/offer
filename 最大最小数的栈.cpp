#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
class max_minstack
 {
 public:
 	stack<int> init;
	stack<int> smax;
	stack<int> smin;
	void push(int v)
	{
		init.push(v);
		if(smin.size()==0||smin.top()>v)
			smin.push(v);
		if(smax.size()==0||smax.top()<v)
			smax.push(v);
	}

	int top()
	{
		return init.top();
	}
	int max()
	{
		return smax.top();
	}
	int min()
	{
		return smin.top();
	}
	void pop()
	{
		if(init.top()==smin.top())
		{
			smin.pop();
			init.pop();
		}
			
		else if(init.top()==smax.top())
		{
			smax.pop();
			init.pop();
		}
		else 
			init.pop();
	}

 	
 }; 
int main()
{
  max_minstack s1;
  for (int i = 0; i < 5; ++i)
  {
  	s1.push(i);
  	cout<<"min"<<s1.min()<<endl;
  	cout<<"max"<<s1.max()<<endl;
  }
return 0;
}