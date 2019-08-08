#include <iostream>
using namespace std;
int start_point=0,end_point=0;
int find_max_cross_array(int *a,int begin,int mid,int end)
{
	int liftsum=a[mid-1],rightsum=a[mid+1],cross_sum=0,sum=a[mid];
	for(int i=mid-1;i>=begin;i--)
	{
		sum=sum+a[i];
		if (liftsum<sum)
		{	
			start_point=i;
			liftsum=sum;
		}
	}
	sum=a[mid+1];
	for(int j=mid+2;j<=end;j++)
	{	
		sum=sum+a[j];
		if (rightsum<sum)
		{	
			end_point=j;
			rightsum=sum;	
		}	
	}
	return rightsum+liftsum;

}
int find_max_array(int a[],int begin,int end)
{	
	int liftmax,rightmax,midmax,a1,a2,a3,a4,a5,a6;
	if (begin==end)
		return a[begin];
	else
	{
		int mid = (begin+end)/2;
		liftmax=find_max_array(a,begin,mid);
		a1=start_point,a2=end_point;
		rightmax=find_max_array(a,mid+1,end);
		a3=start_point,a4=end_point;
		midmax=find_max_cross_array(a,begin,mid,end);
		a5=start_point,a6=end_point;
	}
	if(liftmax>=rightmax&&liftmax>=midmax)
		{start_point=a1,end_point=a2;
		return liftmax;}
	else if (rightmax>=liftmax&&rightmax>=midmax)
		{start_point=a3,end_point=a4;
		return rightmax;}
	else
		{start_point=a5,end_point=a6;
		return midmax;}
}
int main ()
{	
	int a[] = { -90, -6, -70, -1, -8,-20, 500, -3, -4, -1000, -2 };
	int begin=0,end=10;
	cout<<find_max_array(a,begin,end)<<endl;
	cout<<start_point<<' '<<end_point<<endl;
}