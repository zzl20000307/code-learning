#include "../include/common.hpp"

vector<int> vec;
// 前序算法
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