#include<iostream>
using namespace std;
#include<string>
#include<stack>
bool isvalid(string s)
{
	if(s=="")return true;
	if(s.lenght()%2!=0) return false;
	stack<char> ss;
	for(auto e:s)
	{
		if(e=='{'||e=='('||e=='[') ss.push(i);
		else
		{
			if(ss.size()==0&&(e=='}'||e==')'||e==']')) return false;
			else if((e == '}' && ss.top() != '{') || (e == ']' && ss.top() != '[') || (e == ')' && ss.top() != '('))
			return false;
			else
				ss.pop(); 
		}
	}
	if(ss.size()!=0) return false;
	return true;
}
int main()
{
	
	return 0;
}