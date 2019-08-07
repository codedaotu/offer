#include <string.h> 
#include <stdio.h>
#include <iostream> 
#include <vector>
#include <map>
using namespace std;
int main()
{
	int n;
	cin>>n;
	map<string,string> h;
	for(int i=0;i<n;i++)
	{
		string s1="";
		string s2="";
		cin>>s1>>s2;
		h[s1]=s2;
	}
	map<string, string>::iterator  iter;
	iter = h.find("123");
	if(iter != h.end())
    	cout<<"Find, the value is"<<iter->second<<endl;
	else
   		cout<<"Do not Find"<<endl;
	return 0;
}
