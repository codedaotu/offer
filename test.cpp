#include<iostream>
#include<string>
#include<vector>
//#include <ctype.h>
#include<iomanip>
using namespace std;
int main()
{
	string s1="";
  	string s2="";
  	string s3="";
  	cin>>s1>>s2;
  	float len=s2.size(),sum=0;
  	for(char a:s1)
    {
      if(isdigit(a)||isalpha(a))
        	s3+='1';
      else
        	s3+='0';
    }
  for(int i=0;i<len;i++)
  {
    if(s2[i]==s3[i])
      	sum++;
  }
  double res=sum/len*100;
  cout<<fixed<<setprecision(2)<<res<<'%';
  return 0;
}