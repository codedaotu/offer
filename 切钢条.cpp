#include<iostream>
#include<string.h>
using namespace std;
int v[11] = {0,1,5,8,9,10,17,17,20,24,30},r[101];//问题规模最大为100 
/*
自上而下的求解，将大问题一步一步分解为小问题
*/
int cut_rod1(int n)//左端最优解为p，右端钢板剩余长度n，对右端继续切割 
{
	if(n==0)return 0;//一个都不切，收入0
	if(r[n]!=-1)return r[n];//不为初始值则说明存在切分最优 
	int q = -1;
	for(int i=1;i<=n;i++)
		q = max(q,v[i]+cut_rod1(n-i));//cut_rod(n)返回长度为n的钢棒，所能获得的最大价值 
	r[n] = q;		//将最优的存入数组，记录下
	return q;
}
/*
自下而上的求解，先求解子问题，将子问题的结果拼凑起来解决大问题
*/
int cut_rod2(int n)
{	/*
	先把基础解写出来，根据基础解算最优解
	*/
	r[0]=0;
	r[1]=1;
	r[2]=5;
	r[3]=8;
	if (n<4)
		return r[n];
	for(int i = 4;i<=n;i++)
	{
		int q = -1;
		for(int j=1;j<=i;j++)
		{
			q=max(q,r[i-j]+v[j]);
		}
		r[i] = q;
	}
	return r[n];	
}


int main()

{
	int p = 0;
	//for(int k=1;k<=10;k++)
	memset(r,-1,sizeof(r));//给数组赋值-1
	cout<<cut_rod1(10)<<endl;
}
