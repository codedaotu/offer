#include <iostream>
#include<algorithm>
using namespace std;
int Fbi1(int i)//自顶向下的动态规划
{
	if (i <=2 )
		return i == 0 ? 0:1;
	return Fbi1(i-1)+Fbi1(i-2);
}
int Fbi2(int n)//自下向上的动态规划
{	int t[n],i=2;
	t[0] =1, t[1] = 1;
	for (i = 2; i <= n-1 ; i++)
	{
		t[i] = t[i-1]+t[i-2];
	}
	// cout<<"t:"<<t[n-1];
	return t[n-1];
}

int main()
{ 	int n,*p;
	cout<<sizeof(*p);
	cout<<"输入数字:";
	cin>>n;
	cout<<Fbi2(n)<<endl;
	return 0;
}
