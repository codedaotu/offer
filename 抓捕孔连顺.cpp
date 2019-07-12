#include<iostream>
using namespace std;
#include<set>
#include<queue>
#include<vector>
long long C(long long n)
{
    return (n-1) * n / 2;
}
int main()
{
	long long nums,farest;
	cin>>nums>>farest;
	vector <long long> street(nums);
	if(nums<3)
		return 0;
	int count;
	for(int i=0,j=0;i<nums;i++)
	{
		cin>>street[i];
		while(i>=2&&(street[i]-street[j])>farest)
		{
			j++;
		}
		count+=	C(i-j);
	}
	cout<<count%99997867;
	return 0;
}