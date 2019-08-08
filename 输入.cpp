#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <map>
int main()
{
	
	int a,pos;
	
	string c;
	vector <int> sub_c1;
	string temp;
	vector <int> sub_c2;
	getline(cin,c);
	int i=0,j=0;
	while(c[i]!=' ')
	{
		i++;
	}
	for(int t=0;t<=i;t++)
	{
		if(c[t]!='.'&&c[t]!=' ')
		{
			temp+=c[t];
		}
		else
		{	
			cout<<temp<<endl;
			int num=stoi(temp,0,10);		
			sub_c1.push_back(num);
			temp="";
		}
	}
	temp="";
	for(int t=i+1;t<=c.size();t++)
	{
		
		if(c[t]!='.'&&c[t]!='\0')
		{
			temp+=c[t];
		}
		else
		{	
			cout<<temp<<endl;
			int num=stoi(temp,0,10);		
			sub_c2.push_back(num);
			temp="";
		}
	}
	int len1=sub_c1.size();
	int len2=sub_c2.size();
	int p=0;
	while(p<len1&&p<len2)
	{
		if(sub_c1[p]>sub_c2[p])
		{
			cout<<1;
			return 0;
		}
		if(sub_c1[p]<sub_c2[p])
		{
			cout<<-1;
			return 0;
		}
		p++;
	}
	if(len1<len2)
		cout<<-1;
	if(len1==len2)
		cout<<0;
	if(len1>len2)
		cout<<1;
	return 0 ;
}
