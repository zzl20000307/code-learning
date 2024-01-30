#include "../../include/common.hpp"

vector<TreeNode *> path;
vector<vector<TreeNode *>> res;

void preOrder(TreeNode *root)
{
    // 剪枝
    if (root == nullptr || root->val == 3)
        return;
    // 尝试
    path.push_back(root);
    if (root->val == 7)
        // 记录解
        res.push_back(path);
    preOrder(root->left);
    preOrder(root->right);
    // 回退
    path.pop_back();
}