#include<iostream>
using namespace std;
#include<vector>
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x),left(NULL),right(NULL){}
};
bool mirr(TreeNode* p,TreeNode* q)
{
    if(q==p&&p==NULL)
        return true;
    if(q==NULL||p==NULL)
        return false;
    if(p->val==q->val)
        return mirr(p->left,q->right)&&mirr(p->right,q->left);
    return false;
}
bool isSymmetric(TreeNode* root) {
        return mirr(root,root);
    }

int main(int argc, char const *argv[])
{
	return 0;
}