#include <iostream>
using namespace std;
#include<algorithm>
#include<stack>
#include<cstring>
void lsc(int a[],int b[],int len_a,int len_b)
{
	int m = len_a;
	int n = len_b;
	int **c = new int*[m+1]; //共有length1+1行
	for(int i = 0; i < m+1; i++)
		c[i] = new int[n+1];//共有length2+1列
	for(int i = 0; i < n+1; i++)
		c[i][0]=0;        //第0列都初始化为0
	for(int j = 0; j < n+1; j++)
		c[0][j]=0;        //第0行都初始化为0
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; i <= n; j++)
		{	
			cout<<"c="<<c[m][n]<<endl;
			if (a[i-1]==b[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				
			}			
			else
			{
				c[i][j]=max(c[i][j-1],c[i-1][j]);
				
			}
		}
	}
	
}
int main()
{
	int a[]={1,3,4,5,6,7,7,8};
	int b[]={3,5,7,4,8,6,7,8,2};
	lsc(a,b,8,9);
}