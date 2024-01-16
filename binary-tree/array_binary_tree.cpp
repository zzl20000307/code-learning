#include "../include/common.hpp"

/*适用于任意二叉树*/

// 数组表示下的二叉树类

class ArrayBinaryTree
{
public:
    // 构造函数
    ArrayBinaryTree(vector<int> arr)
    {
        tree = arr;
    }
    // 节点数量
    int size()
    {
        return tree.size();
    }
    // 获取索引值为i的值
    int val(int i)
    {
        // 若索引值越界，则返回INT_MAX，代表空位
        if (i < 0 || i >= size())
        {
            return INT_MAX;
        }
        return tree[i];
    }

    // 获得索引为i节点的左子节点的索引
    int left(int i)
    {
        return 2 * i + 1;
    }

    // 右子节点的索引
    int right(int i)
    {
        return 2 * i + 2;
    }
    // 父节点的索引
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    // 层序遍历
    vector<int> levelOrder()
    {
        vector<int> res;
        for (int i = 0; i < size(); i++)
        {
            if (tree[i] != INT_MAX)
                res.push_back(tree[i]);
        }
        return res;
    }
    // 前序遍历
    vector<int> preOrder()
    {
        vector<int> res;
        dfs(0, "pre", res);
        return res;
    }
    // 中序遍历
    vector<int> inOrder()
    {
        vector<int> res;
        dfs(0, "in", res);
        return res;
    }
    // 后序遍历
    vector<int> postOrder()
    {
        vector<int> res;
        dfs(0, "post", res);
        return res;
    }

private:
    vector<int> tree;
    void dfs(int i, string order, vector<int> &res)
    {
        // 如果为空位，则返回
        if (val(i) == INT_MAX)
            return;
        // 前序遍历
        if (order == "pre")
            res.push_back(val(i));
        dfs(left(i), order, res);
        // 中序遍历
        if (order == "in")
            res.push_back(val(i));
        dfs(right(i), order, res);
        // 后序遍历
        if (order == "post")
            res.push_back(val(i));
    }
};

template <typename T>
void printVector(vector<T> vec)
{
    for (auto x : vec)
        cout << "'" << to_string(x) << "'"
             << " ";
    cout << "\n";
}

int main()
{
    // 初始化二叉树
    // 二叉树的数组表示
    vector<int> arr = {1, 2, 3, 4, INT_MAX, 6, 7, 8, 9, INT_MAX, INT_MAX, 12, INT_MAX, INT_MAX, 15};
    ArrayBinaryTree abt(arr);
    // 遍历树
    vector<int> res = abt.levelOrder();
    cout << "层序遍历：" << endl;
    printVector(res);
    res = abt.preOrder();
    cout << "前序遍历：" << endl;
    printVector(res);
    res = abt.inOrder();
    cout << "中序遍历：" << endl;
    printVector(res);
    res = abt.postOrder();
    cout << "后序遍历：" << endl;
    printVector(res);
}