using namespace std;
#include<vector>
#include <iostream>
#include <math.h>
int climb[1000];
int jump[1000];
int MOD = 99997867;
int tower  ()
{
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		climb[i]=min(climb[i-1],jump[i-1])+m;
		jump[i]=min(climb[i-1],climb[i-2]);

	}
	cout<<min(climb[n],jump[n]);
	return 0;
}

int arrest()
{
	int n,d,temp;
	vector<int> p;
	cin>>n>>d;

	for(int i=0;i<n;i++)
	{	
		cin>>temp;
		p.push_back(temp);
	}
	int count=0;
	for(int i=0;i<n;i++)
	{
		int further=p[i]+d;
		int low = i+1;
		int high=n-1;
		int k;

		while(low<=high)
		{
			int mid =(low+high)/2;
			if(p[mid]>further)
				high=mid-1;
			else
				low=mid+1;
		}
		k=high;
		
		int a,b;
		if(k-i-1>0)
		{
			a=(k-i)%MOD;
			b=(k-i-1)%MOD;
			count+=a*b/2;
		}
		return count;
	}
	return count;
}

void reverse_add(int a, int b)
{
	int a1=0,a2=0;
	while(a!=0)
	{
		a1=a%10+a1*10;
		a=a/10;
		// cout<<a1<<endl;
	}
	while(b!=0)
	{
		a2=b%10+a2*10;
		b=b/10;
	}
	cout<<a1+a2<<endl;
}

int main ()
{
	// arrest();
	reverse_add(400,105);
	return 0;
}