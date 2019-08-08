#include<iostream>
using namespace std;
#define N 8
int array[N] = {40,2,90,707,0,88,9,1};
int *array2 = new int[N];
void merge(int array[],int begin,int mid,int end)
{	int i = begin,j=mid+1,k=begin;
	while(i<=mid&&j<=end)
	{
		if (array[i]<array[j]) array2[k++]=array[i++];		
		else array2[k++]=array[j++];
	}
	while(i<=mid)array2[k++]=array[i++];
	while(j<=end)array2[k++]=array[j++];
	//将已经排好序的数组将原数组替换掉   
	for(int p=begin;p<=end;p++)
		array[p]=array2[p];
}
void merge_sort(int a[],int begin,int end)
{	
	if (begin<end)
	{
		int mid=(begin+end)/2;
		merge_sort(array,begin,mid);
		merge_sort(array,mid+1,end);
		merge(a,begin,mid,end);
	}

}
void insert(int a[])
{
	for (int j=1;j<N;j++)
	{	
		int i = j-1;
		int key=a[j];
		while(i>=0&&a[i]>key)
		{	
			a[i+1]=a[i];		
			i--;		
		}
		a[i+1]=key;
	}

}
int main ()
{	
	int begin=0,end=N-1;
	merge_sort(array,begin,end);
	for (int i=0;i<N;i++)
		cout<<array2[i]<<endl;
}