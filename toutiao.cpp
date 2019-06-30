#include<iostream>
using namespace std;
#include<set>
#include<queue>
#include<vector>
#include<math.h>
//给你一个有序整数数组，数组中的数可以是正数、负数、零，请实现一个函数，这个函数返回一个整数：返回这个数组所有数的平方值中有多少种不同的取值。

int array_sqrt(vector<int> &nums)
{
	set<int> value;
	for(auto e:nums)
	{
		if(e<0)
			e=-e;
		value.insert(e);
	}
		
	return value.size();
}

//数组中第K大的程序,
//1基于快排(最快和平均nlogn,最慢n^2)
int part(vector<int> &nums,int left,int right)
{
	int key=nums[right];
	while(left<right)
	{
		while(left<right&&key<nums[left]) left++;
		swap(key,nums[left]);
		while(left<right&&key>nums[right]) right--;
		swap(key,nums[right]);
	}
	return left;
}
int kmax(vector<int> &nums,int k,int left,int right)
{
	if(left<right)
	{
		int mid=part(nums,left,right);
		if(mid>k)
			kmax(nums,k,left,mid-1);
		else if(mid<k)
			kmax(nums,k,mid+1,right);

	}

	return nums[k];
}
//2基于堆排(最快平均最慢nlogn),使用优先队列实现.queue(单端队列只能从队首出)，deque(双端队列)
int k_minheap(vector<int> &nums,int k)
{
	priority_queue <int,vector<int>,greater<int> > q;
	for(int i=0;i<nums.size();i++)
	{
		if(i<k)q.push(nums[i]);

		else if(q.top()<nums[i])
		{
			q.pop();
			q.push(nums[i]);
		}
	}
	return q.top();
}
//二叉树路径长度
class TreeNode
{
public:
	int val;
	TreeNode *left,*right;
	TreeNode(int val)
	{
		this->val=val;
		this->left = this->right = NULL;
	}
};
int tree_high(TreeNode *node)
{
	if (node==NULL)
		return 0;
	int left=tree_high(node->left);
	int right = tree_high(node->right);
	return max(left,right)+1;
}


int main()
{
	vector<int> a={40,2,90,707,0,88,9,1};
	root=TreeNode(5);
	root->left=TreeNode(4);
	root->ri
	//cout<<kmax(a,3,0,7);
	cout<<k_minheap(a,4);
	// cout<<array_sqrt(a);
	return 0;
}