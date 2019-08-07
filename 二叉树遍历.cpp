#include <iostream>
#include <stdio.h>
using namespace std;
int sum=0;
struct ttree
{
	int val;
	ttree *left=NULL;
	ttree *right=NULL;
};
void tree_node(ttree *root)
{
	if(!root)return;
	printf("%d\n",root->val);
	sum+=root->val;
	tree_node(root->left);
	tree_node(root->right);
}
int main()
{

	struct ttree *root;
	struct ttree *root1;
	struct ttree *root2;
	root->val=1;
	root2->val=2;
	root1->val=3;
	root->left=root2;
	root->right=root1;
	tree_node(root);
	return 0;
}