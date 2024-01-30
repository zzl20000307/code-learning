#include "../../include/common.hpp"

/*堆化操作*/
void siftDown(vector<int> &nums, int i, int n)
{
    // 判断节点 i, l, r 中值最大的节点，记为max
    int l = 2 * i + 1, r = 2 * i + 2, max = i;
    if (l < n && nums[l] > nums[max])
        max = l;
    if (r < n && nums[r] > nums[max])
        max = r;
    if (max == i)
        return;
    // 如果max不等于i，则交换
    swap(nums[max], nums[i]);
    i = max;
    // 进行递归操作
    siftDown(nums, i, n);
}
/*堆排序*/
void heapSort(vector<int> &nums)
{
    // 堆化操作，堆化除叶节点以外的其他所有节点
    for (int i = nums.size() / 2 - 1; i >= 0; i--)
    {
        siftDown(nums, i, nums.size());
    }
    // 从堆中提取最大元素，循环n-1轮
    for (int i = nums.size() - 1; i > 0; i--)
    {
        // 交换根节点和最右叶节点（首尾交换）
        swap(nums[0], nums[i]);
        // 以根节点为起点，从顶至底进行堆化
        siftDown(nums, 0, i);
    }
}

template <typename T>
void printVector(vector<T> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << to_string(vec[i]) << " ";
    }
}

int main()
{
    vector<int> nums = {4, 1, 3, 1, 5, 2};
    heapSort(nums);
    cout << "堆排序完成后 nums = ";
    printVector(nums);

    return 0;
}
