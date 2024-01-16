#include "../include/common.hpp"

vector<int> vec;
// 前序遍历
void preOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    // 访问优先级：根节点 左子数 右子数
    vec.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}

// 中序遍历
void inOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    // 访问优先级：左子树 根节点 右子树
    inOrder(root->left);
    vec.push_back(root->val);
    inOrder(root->right);
}

// 后序遍历
void postOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    // 访问优先级：左子树 右子树 根节点
    postOrder(root->left);
    postOrder(root->right);
    vec.push_back(root->val);
}

int main()
{
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    preOrder(n1);
    cout<<"\n";
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
}