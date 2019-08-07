#include <string.h> 
#include <stdio.h>
#include <iostream> 
#include <vector>
using namespace std;
/*
strcmp是比较字符串数组，如果比较string，用s1.compare(s2)
*/
int main()
{
	int n,m;
	cin>>n>>m;
	vector<string> store1;
	vector<string> store2;
	for(int i=0;i<n;i++)
	{
		string s1="";
		string s2="";
		cin>>s1>>s2;
		store1.push_back(s1);
		store2.push_back(s2);
		
	}
	vector<string> ord;
	for(int i=0;i<m;i++)
	{
		string s="";
		cin>>s;
		ord.push_back(s);
	}   
	for(int i=0;i<m;i++)
	{
		int j=0;
		//cout<<store1[i]<<ord[j]<<endl;
		while(ord[i].compare(store1[j])!= 0)
		{
			store1[j];
			j++;
		}
		cout<<store2[j]<<endl;
	}
	return 0;
}