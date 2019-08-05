#include <iostream>
#include <stdio.h>
using namespace std;
const int MAX=10000;
int a[MAX];
int scores,k;
int bucket[151]={0},pre[151]={0};

int main(int argc, char const *argv[])
{
	cin>>scores;
	cout<<scores;
	printf("%d\n", scores);
	for (int i = 0; i < scores; ++i)
	{
		scanf("%d",a[i]);
		bucket[a[i]]++;
	}
	for (int i = 1; i <= 150; ++i)
	{
		pre[i]=pre[i-1]+bucket[i];	
	}
	cin>>k;
	for (int i = 0; i < k; ++i)
		{
			int x;
			cin>>x;
			double ans=100.0*(pre[a[x]]-1)/scores;
			printf("%6lf\n",ans);
		}	

	return 0;
}