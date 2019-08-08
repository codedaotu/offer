using namespace std;
#include <iostream>
#include <math.h>
#include <array>
#include <algorithm>
#include <cstring>
#include <vector>
#include <deque>
#include <set>
// void trans(int nums[],int head,int tail)
//     {
        
//         int t;
//         for(int i=head;i<--tail;i++)
//         {
//             t=nums[i];
//             nums[i]=nums[tail];
//             nums[tail]=t;
//         }
//     }
//     void rotate(int nums[], int k) {
        
//         trans(nums,0,nums.size());
//         trans(nums,0,k);
//         trans(nums,k+1,nums.size());
        
//     }

void std_array ()
{	//静态的，长度不能变

	array<int,2> a1={1,3};
	array<int,2> a2={9,5};
	array<char,100> a3;
	for(int e:a1)
		cout<<e;
	strcpy(a3.data(),"fuck");
	sort(a2.begin(),a2.end());
	a1= move(a2);
	cout<<a1[1]<<a3.data();
}
void std_vector()
{
	//动态的长度可变
	vector<int> v;
	v.push_back(2);
	v.pop_back();
	// v.insert(0,2,3);
	v.front();
	v.back();
}
void std_deque()
{
	deque <int> d;
	d.push_back(2);
	d.push_front(3);
	d.pop_back();
	d.pop_front();
}
//查找并集
void  intersection(vector<int>& nums1, vector<int>& nums2)
{
		map<int,int> num_c;
        vector<int> inter_sec;
        for(int i=0;i<nums1.size();i++)
        {
            if(num_c.find(nums1[i])==num_c.end())
                num_c.insert(make_pair(nums1[i],1)) ;
            else
                num_c[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(num_c.find(nums2[i])!=num_c.end())
            {
                if(num_c[nums2[i]]>0)
                {
                    num_c[nums2[i]]--;
                    inter_sec.push_back(nums2[i]);
                }
            }
        }
        return inter_sec;
        
}
void std_set()
{
	multiset<int,less<int>> s;
	s.insert({0,2,3,4,5,3,2,2,1});
	s.insert(0);

	for(int elem:s)
		cout<<elem;
}
int findk(vector<int>& nums, int k,int left,int right)
    {   
        int start=left,end=right;
        int t=nums[right];
        while(left<right)
        {
            while(left<right&&nums[left]>t)
                left++;
            swap(nums[left],t);
            while(left<right&&nums[right]<t)
                right--;
            swap(nums[right],t);
        }
        if(left==k-1)
            return t;
        else if(left>k-1)
            return findk(nums,k,start,left-1);
        else
            return findk(nums,k,left+1,end);
int main()
{
	// std_set();
	std_array();
}