#include "../include/common.hpp"

vector<int> levelOrder(TreeNode *root)
{
    queue<TreeNode *> queue; // 先进先出
    queue.push(root);
    vector<int> vec;
    while (!queue.empty())
    {
        TreeNode *node = queue.front(); // 返回队头元素，但不会移除
        queue.pop();                    // 移除队头元素
        vec.push_back(node->val);
        if (node->left != nullptr)
        {
            queue.push(node->left); // 元素入队
        }
        if (node->right != nullptr)
        {
            queue.push(node->right);
        }
    }
    return vec;
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
    vector<int> vec=levelOrder(n1);
    cout<<"层序遍历的节点打印序列=："<<endl;
    for(auto x:vec)
    {
        cout<<"'"<<x<<"'"<<" ";
    }
}