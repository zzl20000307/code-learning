#include "../../include/common.hpp"
/*二叉搜索树*/
// 释放二叉树
void freeBinaryTree(TreeNode *root)
{
    if (root == nullptr)
        return;
    freeBinaryTree(root->left);
    freeBinaryTree(root->right);
    delete root;
}

class BinarySearchTree
{
private:
    TreeNode *root;

public:
    BinarySearchTree()
    {
        // 初始化空树
        root = nullptr;
    }
    ~BinarySearchTree()
    {
        freeBinaryTree(root);
    }
    // 查找节点
    TreeNode *search(int num)
    {
        TreeNode *cur = root;
        while (cur != nullptr)
        {
            if (num > cur->val)
            {
                // 插入位置在cur的右子树
                cur = cur->right;
            }
            else if (num < cur->val)
            {
                // 插入位置在cur的左子树
                cur = cur->left;
            }
            else
                // 找到重复节点直接返回
                break;
        }
        return cur;
    }

    // 获取二叉树的根节点
    TreeNode *getRoot()
    {
        return root;
    }

    // 插入节点
    void insert(int num)
    {
        if (root == nullptr)
        {
            root = new TreeNode(num);
            return;
        }
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        while (cur != nullptr)
        {
            pre = cur;
            if (num > cur->val)
                cur = cur->right;
            else if (num < cur->val)
                cur = cur->left;
            else
                return;
        }
        // 插入节点
        if (num > pre->val)
            pre->right = new TreeNode(num);
        else
            pre->left = new TreeNode(num);
    }

    // 删除节点
    void remove(int num)
    {
        if (root == nullptr)
            return;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        while (cur != nullptr)
        {
            // 如果找到了直接返回
            if (num == cur->val)
                break;
            pre = cur;
            if (num > cur->val)
                cur = cur->right;
            else
                cur = cur->left;
        }
        // 如果没有找到，直接返回
        if (cur == nullptr)
            return;
        // 节点的度为0或1的情况
        if (cur->left == nullptr || cur->right == nullptr)
        {
            // 将当前节点不为空的子节点存在来
            TreeNode *child = cur->left != nullptr ? cur->left : cur->right;
            // 若删除的节点为根节点，则重新指定跟节点
            if (cur == root)
            {
                root = child;
            }
            // 删除节点cur
            else
            {
                if (pre->left == cur)
                    pre->left = child;
                else
                    pre->right = child;
            }
            delete cur;
        }
        // 节点的度为2的情况
        else
        {
            // 获取中序遍历中 cur 的下一个节点
            TreeNode *temp = cur->right;
            while (temp->left != nullptr)

            {
                temp = temp->left;
            }
            int tempVal = temp->val;
            // 递归删除节点 tmp
            remove(tempVal);
            cur->val = tempVal;
        }
    }
};

// 前序遍历
void preOrder(TreeNode *root, vector<int> &vec)
{
    if (root == nullptr)
        return;
    // 访问优先级：根节点 左子数 右子数
    vec.push_back(root->val);
    preOrder(root->left, vec);
    preOrder(root->right, vec);
}

void print(TreeNode *root, vector<int> &vec)
{
    preOrder(root, vec);
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "'" << vec[i] << "'"
             << " ";
    }
}

int main()
{
    /* 初始化二叉搜索树 */
    BinarySearchTree *bst = new BinarySearchTree();
    // 请注意，不同的插入顺序会生成不同的二叉树，该序列可以生成一个完美二叉树
    vector<int> nums = {8, 0, 4, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};

    for (auto num : nums)
    {
        bst->insert(num);
    }
    TreeNode *node = bst->search(1);
    cout << "\t"
         << "查找到的节点对象为：" << node << "，节点值=" << node->val << endl;

    /* 删除节点 */
    vector<int> vec;
    bst->remove(1);
    cout << endl;
    cout << "删除节点 1 后，二叉树为\n";
    print(bst->getRoot(), vec);
    // vector<int>().swap(vec);
    // cout<<endl;
    vector<int> vec1;
    bst->remove(4);
    cout << endl;
    cout << "删除节点 4 后，二叉树为\n";
    print(bst->getRoot(), vec1);

    vector<int> vec2;
    bst->remove(15);
    cout << endl;
    cout << "删除节点 4 后，二叉树为\n";
    print(bst->getRoot(), vec2);
}