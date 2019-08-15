#include<iostream>
using namespace std;
struct List_node
{
	int val;
	List_node *next;
	List_node(int x):val(x),next(NULL){}
};
typedef struct List_node list;

list *merge(list *root,list*root1)
{
	if(root==NULL)
		return root1;
	if (root1==NULL)
		return root;
	list *res=NULL;
	if(root->val<root1->val)
	{
		res=root;
		res->next=merge(root->next,root1);
	}
	else 
	{
		res=root1;
		res->next=merge(root,root1->next);
	}
	return res;
}
int main()
{
	list a(1);
	list b(3);
	list c(5);
	list d(2);
	list e(4);
	list f(6);
	a.next=&b;
	b.next=&c;
	d.next=&e;
	e.next=&f;
	list *root1=&d;
	list *root=&a;
	list *res=  merge(root1,root);
	while(res)
	{
		cout<<res->val<<endl;
		res=res->next;
	}
	return 0;
}