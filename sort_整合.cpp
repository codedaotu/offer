#include<iostream>
using namespace std;
#include <vector>
#include <string>
#define N 100
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void bubble(int a[],int len)
{
	int key=1;
	for(int i=1;i<len&&key==1;i++)
	{	
		key=0;
		for(int j=len-1;j>=i;j--)
		{
			if(a[j]>a[j-1])
			{
				swap(a[j],a[j-1]);
				key=1;
			}

		}
	}
}
int partiton(int a[],int left,int right)
{
	int key = a[right];//key 是尾从头循环，反之亦然
	while(left<right)
	{
		while(left<right&&key>=a[left])
			left++;
		swap(key,a[left]);
		while(left<right&&key<=a[right])
			right--;
		swap(key,a[right]);
	}
	return right;
}

void q_sort(int a[],int left,int right)
{
	if(left<right)
	{
		int mid=partiton(a,left,right);
		q_sort(a,left,mid-1);
		q_sort(a,mid+1,right);
	}p(int a[],int partent,int end)
	
}
void adjust_hea
{
	for (int i = 2*partent+1; i<end; i=i*2+1)
	{
		if(a[i]<a[i+1]&&i+1<end)
			i++;
		if(a[partent]<a[i])
		{
			swap(a[partent],a[i]);
			partent =i;
		}
	}
}
void max_heap(int a[],int len)
{
	for (int i = len/2-1; i >= 0; i--)
	{
		adjust_heap(a,i,len);
	}
	for (int i=len-1;i>=0;i--)
	{
		cout<<a[0]<<endl;
		swap(a[0],a[i]);
		adjust_heap(a,0,i);   
	}

}
void merge(int a[],int left,int mid,int right)
{	
	int k=0,i=left,j=mid+1;
	int start=left;
	int temp[N]={0};
	while(i<=mid&&j<=right)
	{
		if(a[i]<a[j])temp[k++]=a[i++];
		else temp[k++]=a[j++];
	}
	while(i<=mid)temp[k++]=a[i++];
	while(j<=right)temp[k++]=a[j++];
	for (int i = 0; i < k; ++i)
	{
		a[left++]=temp[i];
	}
}
void merge_sort(int a[],int left,int right)
{
	if(left<right)
	{
		int mid = (left+right)/2;
		merge_sort(a,left,mid);
		merge_sort(a,mid+1,right);
		merge(a,left,mid,right);
	}
}
	
int main()
{
	int a[]={110,10,2,1,3,5,4,6,9,8,7,19,16,15,10};
	int len=15;
	// // bubble(a,len);
	// q_sort(a,0,14);
	// max_heap(a,len);
	// merge_sort(a,0,len-1);
	for(int i=0;i<len;i++)
		cout<<a[i]<<endl;
	return 0;
}