#include "../../include/common.hpp"

vector<TreeNode *> res;
/*前序遍历*/
void preOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    if (root->val == 7)
        res.push_back(root);
    preOrder(root->left);
    preOrder(root->right);
}

// 打印
template <typename T>
void printVector(vector<T> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << to_string(vec[i]) << " ";
    }
}

/* 将列表反序列化为二叉树：递归 */
TreeNode *vectorToTreeDFS(vector<int> &arr, int i)
{
    if (i < 0 || i >= arr.size() || arr[i] == INT_MAX)
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(arr[i]);
    root->left = vectorToTreeDFS(arr, 2 * i + 1);
    root->right = vectorToTreeDFS(arr, 2 * i + 2);
    return root;
}

/* 将列表反序列化为二叉树 */
TreeNode *vectorToTree(vector<int> arr)
{
    return vectorToTreeDFS(arr, 0);
}

// 形象表达树

struct Trunk
{
    Trunk *prev;
    string str;
    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

void showTrunks(Trunk *p)
{
    if (p == nullptr)
    {
        return;
    }

    showTrunks(p->prev);
    cout << p->str;
}

/* Print a binary tree */
void printTree(TreeNode *root, Trunk *prev, bool isLeft)
{
    if (root == nullptr)
    {
        return;
    }

    string prev_str = "    ";
    Trunk trunk(prev, prev_str);

    printTree(root->right, &trunk, true);

    if (!prev)
    {
        trunk.str = "———";
    }
    else if (isLeft)
    {
        trunk.str = "/———";
        prev_str = "   |";
    }
    else
    {
        trunk.str = "\\———";
        prev->str = prev_str;
    }

    showTrunks(&trunk);
    cout << " " << root->val << endl;

    if (prev)
    {
        prev->str = prev_str;
    }
    trunk.str = "   |";

    printTree(root->left, &trunk, false);
}

/* The interface of the tree printer */
void printTree(TreeNode *root)
{
    printTree(root, nullptr, false);
}

/* Driver Code */
int main()
{
    TreeNode *root = vectorToTree(vector<int>{1, 7, 3, 4, 5, 6, 7});
    cout << "\n初始化二叉树" << endl;
    printTree(root);

    // 前序遍历
    preOrder(root);

    cout << "\n输出所有值为 7 的节点" << endl;
    vector<int> vals;
    for (TreeNode *node : res)
    {
        vals.push_back(node->val);
    }
    printVector(vals);
}