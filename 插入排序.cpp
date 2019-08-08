#include <iostream>
#include<algorithm>
using namespace std;
const int N =8;
int array[N]={2,7,4,6,0,5,88,9};
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
int main()
{
   int key,j;
   for (int i=1;i<=N;i++)
   {
   		key=array[i];
   		j=i-1;
   		while(j>=0&&array[j]>key)
   		{
   			array[j+1]=array[j];
   			j--;
   		}
   		array[j+1]=key;
   }
   for (int k=0;k<N;k++)
   {
   	cout<<array[k];
   }
   
}