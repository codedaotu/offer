#include<iostream>
using namespace std;
#define MAX 100
int a[MAX]={};
/*
计数其实就是计数排序
*/
void bucket(int array[],int N )
{
	for (int i = 0; i < N; i++)
	{
		a[array[i]]++;
	}

}
int main ()
{	int N=6;
	int array[N]={20,79,78,50,23,4};
	bucket(array,N);

	for (int i = 0; i < MAX; i++)
	{
		if(a[i]>0)cout<<i<<endl;
	}
}