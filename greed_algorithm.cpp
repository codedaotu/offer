#include <iostream>
#include<algorithm>
using namespace std;
//找零问题
const int N = 7;
int Count[N]={99,99,99,99,99,99,99};
int Value[N]={1,2,5,10,20,50,100};
int greed_algorithm(int money)
{
	int num=0;
	
	for(int i=N-1;i>=0;i--) 
	{
		int c=min(money/Value[i],Count[i]);
		Count[i]=Count[i]-c;		
		money=money-c*Value[i];
		num+=c;
		cout<<Count[i]<<endl;
	}
	if(money>0)
		num=-1;
	return num;
}
int main() 
{
	int money;
	cin>>money;
	int res=greed_algorithm(money);
	if(res!=-1) cout<<res<<endl;
	else cout<<"NO"<<endl;
}