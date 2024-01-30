#include "../../include/common.hpp"

/* 二分查找插入点（有重复元素）*/

int binarySearchInsertion(vector<int> &nums, int target)
{
    int i = 0, j = nums.size() - 1; // 初始化双闭区间 [0, n-1]
    while (i <= j)
    {
        int m = i + (j - i) / 2; // 计算中点索引 m
        if (nums[m] < target)
        {
            i = m + 1; // target 在区间 [m+1, j] 中
        }
        else if (nums[m] > target)
        {
            j = m - 1; // target 在区间 [i, m-1] 中
        }
        else
        {
            j = m - 1; // 首个小于 target 的元素在区间 [i, m-1] 中
        }
    }
    // 返回插入点 i
    return i;
}

/* 二分查找最左一个 target */
int binarySearchLeftEdge(vector<int> &nums, int target)
{
    int i = binarySearchInsertion(nums, target);
    // 未找到target，返回-1
    if (i == nums.size() || nums[i] != target)
        return -1;
    // 找到target，返回索引i
    return i;
}

/* 二分查找最右一个 target */
int binarySearchRightEdge(vector<int> &nums, int target)
{
    // 转化为查找最左一个target+1
    int i = binarySearchInsertion(nums, target + 1);
    // j 指向最右一个 target ，i 指向首个大于 target 的元素
    int j = i - 1;
    // 未找到target，返回-1
    if (j == -1 || nums[j] != target)
        return -1;
    // 找到target，返回索引j
    return j;
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
    // 包含重复元素的数组
    vector<int> nums = {1, 3, 6, 6, 6, 6, 6, 10, 12, 15};
    cout << "\n数组 nums = ";
    printVector(nums);

    // 二分查找左边界和右边界
    for (int target : {6, 7})
    {
        int index = binarySearchLeftEdge(nums, target);
        cout << "最左一个元素 " << target << " 的索引为 " << index << endl;
        index = binarySearchRightEdge(nums, target);
        cout << "最右一个元素 " << target << " 的索引为 " << index << endl;
    }

    return 0;
}
