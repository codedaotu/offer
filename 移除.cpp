#include<iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstdint>
#include <bits/stdc++.h>
int main()
{
	unsigned long long end,head,num;
	cin>>num;
	head=0;
	end=63;
	while(head<=end)
	{
		int mid=(head+end)/2;
		if(num>(1<<mid))head=mid+1;
		else if (num<(1<<mid))end=mid-1;
		else if(num==(1<<mid))
		{	
			cout<<mid;
			return mid;
		}	
	 }
	return 0;

}