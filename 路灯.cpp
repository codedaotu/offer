#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
int main( )
{
  int nums,len,k;
  cin>>nums>>len;
  vector<int> arr;
  for(int i=0;i<nums;i++)
  {
    	cin>>k;
    	arr.push_back(k);
  }
  sort(arr.begin(),arr.end());
  double m=-1;
  for(int i=0;i<nums-1;i++)
  {
    m=m>arr[i+1]-arr[i]?m:arr[i+1]-arr[i];
  }
  double edge1=arr[0]/1.0;
  double edge2=(len-arr[nums-1])/1.0;
  double edge=edge1>edge2?edge1:edge2;
  m=(m/2)>edge?m/2:edge;
  cout<<fixed<<setprecision(2)<<m;
}