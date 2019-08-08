#include <iostream>
using namespace std;
#define N 8
int array[N] = {40,2,90,707,0,88,9,1};
int partiton(int a[],int start,int end)
{
	int k=a[end];
	while(start<end)
	{
		while(start<end&&a[start]<k)
			start++;
		swap(a[start],k);//start记录的是前面比k大的，交换后移到后面去了。
		while(start<end&&k<a[end])
			end--;
		swap(k,a[end]);//由于最后一位已经是比k大的，所以这是从后向前检测比k小的，此时k储存在start的位置上，交换之后start的位置是比k小的数，而
	}
	return start;
}
void qsort(int a[],int start,int end)
{
	if(start<=end)
	{
		int mid =  partiton(a,start,end);
		qsort(a,start,mid-1);
		qsort(a,mid+1,end);
	}
	
}
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

int main()
{
	qsort(array,0,7);
	for (int i=0;i<N;i++)
		cout<<array[i]<<endl;
}