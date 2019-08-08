#include <iostream>
using namespace std;
#define N 2
#define M 2
int** martix_multiply(int (*a)[3],int (*b)[3],int k)
{
	int **c = new int*[2];
	for(int i=0;i<2;i++)
	{
		c[i] = new int[3];
		for (int j = 0; j < 3; j++)
		{
			c[i][j]=0;
			for (int t = 0; t < k; t++)
			{
				c[i][j]=c[i][j]+a[i][t]*b[t][j];
				cout<<"i,j="<<i<<j<<endl;
			}
		}
	}
	return c;
}
int main()
{
	int a[2][3]={1,1,1,1,1,1};
	int b[3][3]={1,2,3,4,5,6,7,8,9};
	int **c;
	c=martix_multiply(a,b,3);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout<<c[i][j]<<endl;
		}
	}
}

