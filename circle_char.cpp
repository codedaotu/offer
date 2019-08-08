#include <iostream>
#include<algorithm>
#include <string>
using namespace std;
string shift(string str,int steps)//左移n=右移len-n
{	int len = str.size();
	steps = steps%len;
	str+=str;
	return str.substr(steps,len);}  
int main()
{	char str[]="abcde";
	cout<<shift("abcde",3)<<endl;
	reverse(&str[2],&str[5]);//两者之间是要翻转字符串
	cout<<str<<endl;
	return 0;
}
