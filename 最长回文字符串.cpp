#include<iostream>
using namespace std;
#include <string>
//中心法
int check(string s,int left,int right)
{
		while(left>=0&&right<s.length()&&s[left]==s[right])
		{
			left--;
			right++;
		}
	return right-left-1;
}
int main()
{
	string s;
	cin>>s;
	if(s.length()<=1)
		return 0;
	int left=0,right=0;
	int len=0;
	for(int i=0;i<s.length();i++)
	{
		int len1=check(s,i,i);
		int len2=check(s,i,i+1);
		len=max(max(len1,len2),len);
		cout<<"len1 "<<len1<<endl;
		cout<<"len2 "<<len2<<endl;
		if(len>right-left+1)
		{
			left=i-(len-1)/2;
			right= i+len/2;
		}
	}
	cout<<left<<" "<<len<<endl;
	cout<<s.substr(left,len);
	return 0;
}