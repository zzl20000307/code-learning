#include "../../include/common.hpp"

class MaxHeap
{
private:
    // 使用动态数组这样无须考虑扩容问题
    vector<int> maxHeap;
    // 获取左子节点索引
    int left(int i)
    {
        return 2 * i + 1;
    }
    // 获取右子节点索引
    int right(int i)
    {
        return 2 * i + 2;
    }
    // 获取父节点索引
    int parent(int i)
    {
        return (i - 1) / 2; // 向下取整
    }

    void siftUp(int i)
    {
        int p = parent(i);
        // 当越过根节点或节点无法修复时，结束堆化
        if (p < 0 || maxHeap[p] >= maxHeap[i])
            return;
        swap(maxHeap[i], maxHeap[p]);
        i = p;
        siftUp(i);
    }
    void siftDown(int i)
    {
        // 判断节点 i, l, r 中值最大的节点，记为max
        int l = left(i), r = right(i), max = i;
        if (l < size() && maxHeap[l] > maxHeap[max])
            max = l;
        if (r < size() && maxHeap[r] > maxHeap[max])
            max = r;
        if (max == i)
            return;
        // 如果max不等于i，则交换
        swap(maxHeap[max], maxHeap[i]);
        i = max;
        // 进行递归操作
        siftDown(i);
    }

public:
    // 构造方法
    MaxHeap(vector<int> nums)
    {
        maxHeap = nums;
        // 堆化除叶节点以外的所有节点
        for (int i = parent(size() - 1); i >= 0; i--)
        {
            siftDown(i);
        }
    }
    // 获取堆大小
    int size()
    {
        return maxHeap.size();
    }

    // 判断堆是否为空
    bool isEmpty()
    {
        return size() == 0;
    }

    // 访问堆顶元素
    int peek()
    {
        return maxHeap[0];
    }
    // 元素入堆
    void push(int val)
    {
        maxHeap.push_back(val);
        siftUp(size() - 1);
    }

    void pop()
    {
        if (isEmpty())
        {
            throw out_of_range("堆为空");
        }
        // 交换首元素和尾元素
        swap(maxHeap[0], maxHeap[size() - 1]);
        // 删除尾节点
        maxHeap.pop_back();
        // 从顶至底堆化
        siftDown(0);
    }
    // 打印堆
    int val(int i)
    {
        // 若索引值越界，则返回INT_MAX，代表空位
        if (i < 0 || i >= size())
        {
            return INT_MAX;
        }
        return maxHeap[i];
    }
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
    vector<int> preOrder()
    {
        vector<int> res;
        dfs(0, "pre", res);
        return res;
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
    /* 初始化大顶堆 */
    vector<int> vec{9, 8, 6, 6, 7, 5, 2, 1, 4, 3, 6, 2};
    MaxHeap maxHeap(vec);
    cout << "\n输入列表并建堆后" << endl;
    vector<int> vec_temp;
    vec_temp = maxHeap.preOrder();
    printVector(vec_temp);

    // 获取堆顶元素
    int peek = maxHeap.peek();
    cout << "\n堆顶元素为 " << peek << endl;

    // 元素入堆
    int val = 7;
    maxHeap.push(val);
    cout << "\n元素 " << val << " 入堆后" << endl;
    vector<int> vec1;
    vec1 = maxHeap.preOrder();
    printVector(vec1);

    // 堆顶元素出堆
    peek = maxHeap.peek();
    maxHeap.pop();
    cout << "\n堆顶元素 " << peek << " 出堆后" << endl;
    vector<int> vec2;
    vec2 = maxHeap.preOrder();
    printVector(vec2);

    // 获取堆大小
    int size = maxHeap.size();
    cout << "\n堆元素数量为 " << size << endl;

    return 0;
}
