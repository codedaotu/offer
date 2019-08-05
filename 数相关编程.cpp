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


/*
检测子树
*/
bool same(TreeNode *s,TreeNode *t)
{
    if(t==NULL&&s==NULL) return true;
    else if(s==NULL||t==NULL) return false;
    if(s->val!=t->val) return false;
    return same(s->left,t->left)&&same(s->right,t->right);
}
bool subtree(TreeNode *s,TreeNode *t)
{
    if(t==NULL) return true;
    if(s==NULL) return false;
    if(same(s,t)) return true;
    return subtree(s->left,t)||subtree(s->right,t);
}
/*
镜像树
*/
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


/*
二叉树层次遍历
*/
void pre(TreeNode *root, int depth, vector<vector<int>> &ans)
{
    if(!root)return;
    if(depth>=ans.size())
        ans.push_back(vector<int>{});
    ans[depth].push_back(root->val);
    pre(root->left,depth+1,ans);
    pre(root->right,depth+1,ans);
}
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    pre(root, 0, ans);
    return ans;
}
int main(int argc, char const *argv[])
{
	return 0;
}