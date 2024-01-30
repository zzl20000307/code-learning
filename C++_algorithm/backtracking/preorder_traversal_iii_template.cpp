

#include "../../include/common.hpp"

/* 判断当前状态是否为解 */
bool isSolution(vector<TreeNode *> &state)
{
    return !state.empty() && state.back()->val == 7;
}
/* 记录解 */
void recordSolution(vector<TreeNode *> &state, vector<vector<TreeNode *>> &res)
{
    res.push_back(state);
}
/* 判断在当前状态下，该选择是否合法 */
bool isValid(TreeNode *choice, vector<TreeNode *> state)
{
    return choice != nullptr && choice->val != 3;
}
/* 更新状态 */
void makeChoice(vector<TreeNode *> &state, TreeNode *choice)
{
    state.push_back(choice);
}
/* 恢复状态 */
void undoChoice(vector<TreeNode *> &state, TreeNode *choice)
{
    state.pop_back();
}
/* 回溯算法：*/

void backtrack(vector<TreeNode *> &state, vector<TreeNode *> &choices, vector<vector<TreeNode *>> &res)
{
    // 检查是否为解
    if (isSolution(state))
    {
        recordSolution(state, res);
    }
    // 遍历所有选择
    for (TreeNode *choice : choices)
    {
        // 剪枝：检查选择是否合法
        if (isValid(choice, state))
        {
            // 尝试：做出选择，更新状态
            makeChoice(state, choice);
            // 进行下一轮选择
            vector<TreeNode *> nextChoices{choice->left, choice->right};
            backtrack(state, nextChoices, res);
            // 回退：撤销选择，恢复到之前的状态
            undoChoice(state, choice);
        }
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

// 打印
template <typename T>
void printVector(vector<T> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << to_string(vec[i]) << " ";
    }
}

/* Driver Code */
int main()
{
    TreeNode *root = vectorToTree(vector<int>{1, 7, 3, 4, 5, 6, 7});
    cout << "\n初始化二叉树" << endl;
    printTree(root);

    // 回溯算法
    vector<TreeNode *> state;
    vector<TreeNode *> choices = {root};
    vector<vector<TreeNode *>> res;
    backtrack(state, choices, res);

    cout << "\n输出所有根节点到节点 7 的路径，要求路径中不包含值为 3 的节点" << endl;
    for (vector<TreeNode *> &path : res)
    {
        vector<int> vals;
        for (TreeNode *node : path)
        {
            vals.push_back(node->val);
        }
        printVector(vals);
    }
}
