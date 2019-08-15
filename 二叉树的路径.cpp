#include<iostream>
using namespace std ;
struct treenode
{
	int val;
	treenode *left;
	treenode *right;
	treenode(int x):val(x),left(NULL),right(NULL){}
} ;
typedef struct treenode tree;
//定义的是指针用->,定义的是变量用.
int main(int argc, char const *argv[])
{
	tree a(1);
	tree b(2);
	a.left=&b;
	tree *root=&a;
	tree *root2 = (tree*)malloc(sizeof(tree));
	root2->val=2;
	cout<<a.left->val<<endl;
	cout<<root->left->val<<endl;
	cout<<root2->val<<endl;
	return 0;
}