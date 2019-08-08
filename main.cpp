#include<iostream>
using namespace std;
#include<string.h>
int recursion(int a)
{
	if (a == 0)
		return 0;
	else
		return 2 * recursion(a - 1) + a*a;
}
int get(int *p,int i,int j)
{ if(NULL==p||i<0||i>3||j>=4||j<0) return(0);
	return *(p+i*4+j);

}
int main()
{ 	int *t[10];
	int(*q)[10];//10个指针数组，指向数组的指针。[]高于*p,所以添加括号
	int a[2][3] = {(1,2),(3,4),(5,7)};//相当于{2,4,6}
	int a1,a2,b=2,c=7,d=5,*p,i=0;
	a1=(++b,c--,d+3);//d+3
	a2= ++b,c--,d+3;//++b,赋值运算高于逗号
	// cout<<a1<<a2;
	p = &a[0][0];//p是指向数组的第一个数的指针,a[x][y]=b[x*列+y] 
	for (i = 0; i < 6; i++)
	{
		p[i] = i+1;
	}
	// cout<<a[1][2];
	// cout<<get(p,2,3);
	cout<<strcmp("43","52");
}
