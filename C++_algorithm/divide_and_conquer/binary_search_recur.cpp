#include "../../include/common.hpp"

/* 二分查找：问题 f(i, j) */
int dfs(vector<int> &nums, int target, int i, int j)
{
    // 若区间为空，代表无目标元素，则返回 -1
    if (i > j)
        return -1;
    // 计算中点索引
    int m = (i + j) / 2;
    if (target > nums[m])
        // 若区间为空，代表无目标元素，则返回 -1
        return dfs(nums, target, m + 1, j);
    else if (target < nums[m])
        // 递归子问题 f(i, m-1)
        return dfs(nums, target, i, m - 1);
    else
        // 找到目标元素，返回其索引
        return m;
}

/*二分查找*/

int binarySearch(vector<int> &nums, int target)
{
    int n = nums.size();
    // 求解问题
    return dfs(nums, target, 0, n - 1);
}

/* Driver Code */
int main()
{
    int target = 6;
    vector<int> nums = {1, 3, 6, 8, 12, 15, 23, 26, 31, 35};

    // 二分查找（双闭区间）
    int index = binarySearch(nums, target);
    cout << "目标元素 6 的索引 = " << index << endl;

    return 0;
}
