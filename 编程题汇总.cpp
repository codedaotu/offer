#include<iostream>
using namespace std;
#include<set>
#include<queue>
#include<vector>
#include<cmath>
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
//2基于堆排(最快平均最慢nlogn),使用优先队列实现queue(单端队列只能从队首出)，deque(双端队列)
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
//列表翻转
 struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int d):val(d),next(NULL){}
} ;

ListNode* reverse_list(ListNode* head)
{
	ListNode* ptemp = NULL;
	ListNode* pnew = NULL;
	while(head)
	{
		ptemp=head->next;
		head->next=pnew;
		pnew=head;
		head=ptemp;
	}
	return pnew;
}
//牛顿法开根号；
//y 是输入
//f(x)=x^m-y
//更具泰勒展开式f(x)=f(x0)+(x-x0)*f'(x0)
//x=x0-f(x0)/f'(x0)迭代这一步如x^m,导数为m*x^(m-1).带入即可
//python 可运行下列代码
double newton(double y,int m)
{
	double x=y/2;
	while(abs(pow(x,m)-y)>0.00000001)
		x=1.0/m*(x-1)+y/(m*pow(x,m-1));
	return x;
}
//二分法
float test_sqrt(float y)
{
	float low=0.0,high=y;
	float mid = (low+high)/2;
	while(high-low>0.00000001)
	{
		if(mid*mid<y)low=mid;
		else if(mid*mid>y)high=mid;
		else
			return mid; 
	}
	return mid;
}
//(0,1)的均匀分布生成正态分布的随机数.v1,v2都是服从(0,1)的随机数
//int boxmuller(int v1,int v2)
//{
//	int y=sqrt(-2*log(v1))*cos(2*pi*v2);
//}

int main()
{
	vector<int> a={40,2,90,707,0,88,9,1};
	//cout<<kmax(a,3,0,7);
	//cout<<k_minheap(a,4);
	// cout<<array_sqrt(a);
	cout<<test_sqrt(2.0);
	return 0;
}