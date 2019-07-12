#include<iostream>
using namespace std;
const int N=1e6+10;
char str[N];
int main(){
	int num;
	cin>>num;
	while(num--)
	{
		cin>>str;
		int k=0;
		for(int i=0;str[i];i++)
		{
			str[k++]=str[i];
			if(k>=3&&str[k-1]==str[k-2]&&str[k-2]==str[k-3]) k--;
			if(k>=4&&str[k-1]==str[k-2]&&str[k-3]==str[k-4]) k--;
		}
		str[k]='\0';
		cout<<str<<endl;
	}
	
}
 
