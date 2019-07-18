#include<iostream>
using namespace std;
#include <string>
#include<vector>
int way1()
{
	string s;
	cin>>s;
	int len=s.length();

	int p1=0,p2=0;
	string temp="";
	int res=0;
	for (int i = 0; i < len; i++)
	{
		if(temp.find(s[i])==-1)
		{
			temp+=s[i];
			cout<<temp<<endl;
		}
			
		else
		{	
			res=res>temp.length()?res:temp.length();
			//p1=s.find_first_of(s[i],p1)+1;
			p2=temp.find(s[i]);
			temp=temp.substr(p2+1)+s[i];
		}
	}
	res=res>temp.length()?res:temp.length();
	cout<<res;
	return 0;
}
int way2()
{
	string s;
	cin>>s;
	int m=0;
	string temp="";
	int p;
	for (int i = 0; i < s.length(); i++)
	{
		if(temp.find(s[i])==-1)
			temp+=s[i];
		else
		{
			p=temp.find(s[i]);
			temp=temp.substr(p+1)+s[i];
		}
		m=max(m,(int)temp.length());
	}
	cout<<m;
	return 0 ;
}
int main()
{
	way2();
	return 0;
}