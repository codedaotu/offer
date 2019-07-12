using namespace std;
#include<vector>
#include <iostream>
#include <queue>
//优先队列的方法empty()size()front()push()pop()
//greater 顺序排序 top是最小的。less 的倒叙排序 top是倒叙
int main()
{
	priority_queue <int,vector<int>,greater<int> > min_heap;
	priority_queue <int,vector<int>,less<int> > max_heap;
	for(int i=0;i<100;i++)
	{
		min_heap.push(rand()%100);
		max_heap.push(rand()%100);
	}
	cout<<"min:";
	for (int i = 0; i < 100; ++i)
	{
		cout<<min_heap.top()<<' ';
		min_heap.pop();
	}
	cout<<'\r'<<"max";
	for (int i = 0; i < 100; ++i)
	{
		cout<<max_heap.top()<<' ';
		min_heap.pop();
	}
	return 0;
}
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *faptr = head;
        ListNode *slptr = head;
        while(faptr != nullptr && faptr -> next != nullptr)
        {
            faptr = faptr -> next -> next;
            slptr = slptr -> next;
            if(faptr == slptr)
                return true;
        }
        return false;
    }
};

