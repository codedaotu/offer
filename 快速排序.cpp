#include <iostream>
using namespace std;
#define N 8
int array[N] = {40,2,90,707,0,88,9,1};
void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}
int partition(int a[],int start,int end)
{
	/*
	快排顺序很重要若哨兵是left，则先从右向左（从后向前）遍历。若是right则相反
	否则哨兵left，从左到右，此时start永远为0，死循环。同理相反的话则end永远不减少，不能和start碰在一起，死循环。
	*/
	int key=a[end];
	while(start<end)
	{	/*
		跳跳法，逐渐使得key处在左右数组的分割点
		*/	
		while(start<end&&a[start]<key)//从左到右检测比key大的数跳出
			start++;
		cout<<"s,e"<<a[start]<<" "<<a[end]<<endl;
		swap(a[start],a[end]);//将这个数和末位交换，因为末位是初始的key
		while(start<end&&a[end]>key)//从右到左检测比key小的数跳出
			end--;
		cout<<"s,e"<<a[start]<<" "<<a[end]<<endl;
		swap(a[start],a[end]);//和上一步跳出之后的start交换,比key大的移到数组后部，小的则在前部
	}	
	return start;
}
void q_sort(int a[],int start,int end)
{
	if(start<=end)
	{
		int mid = partition(a,start,end);
		q_sort(a,start,mid-1);
		q_sort(a,mid+1,end);
	}  
}
int main ()
{	
	int begin=0,end=N-1;
	q_sort(array,begin,end);
	for (int i=0;i<N;i++)
		cout<<array[i]<<endl;
}
