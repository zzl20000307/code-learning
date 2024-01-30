#include "../../include/common.hpp"

/* 计数排序 */
// 简单实现，无法用于排序对象

void countingSortNaive(vector<int> &nums)
{
    int m = 0;
    // 统计最大的数
    for (auto num : nums)
    {
        m = max(m, num);
    }
    // 统计各个数字出现的次数
    vector<int> counter(m + 1, 0);
    for (auto num : nums)
    {
        counter[num]++;
    }
    // 遍历counter，将各元素填入原数组nums
    int i = 0;
    for (int num = 0; num < m + 1; num++)
    {
        for (int j = 0; j < counter[num]; j++, i++)
            nums[i] = num;
    }
}

/* 计数排序 */
// 完整实现，可排序对象，并且是稳定排序
void countingSort(vector<int> &nums)
{
    int m = 0;
    // 统计最大的数
    for (auto num : nums)
    {
        m = max(m, num);
    }
    // 统计各个数字出现的次数
    vector<int> counter(m + 1, 0);
    for (auto num : nums)
    {
        counter[num]++;
    }
    // 求counter的前缀和，将出现次数转化为尾索引
    // 即counter[num]-1是num在res中最后一次出现的索引
    for (int i = 0; i < m; i++)
    {
        counter[i + 1] += counter[i];
    }
    // 倒序遍历nums，将各元素填入结果数组res
    // 初始化数组res用于记录结果
    int n = nums.size();
    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int num = nums[i];
        res[counter[num] - 1] = num;
        counter[num]--;
    }
    nums=res;
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
    vector<int> nums = {1, 0, 1, 2, 0, 4, 0, 2, 2, 4};
    countingSortNaive(nums);
    cout << "计数排序（无法排序对象）完成后 nums = ";
    printVector(nums);

    vector<int> nums1 = {1, 0, 1, 2, 0, 4, 0, 2, 2, 4};
    countingSort(nums1);
    cout << "计数排序完成后 nums1 = ";
    printVector(nums1);

    return 0;
}
