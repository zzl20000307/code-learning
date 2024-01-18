#include "../include/common.hpp"

void merge(vector<int> &nums, int left, int mid, int right)
{
    // 创建一个临时数组temp，用于存放合并后的结果
    vector<int> temp(right - left + 1);
    // 初始化左子数组和右子数组的起始索引
    int i = left, j = mid + 1, k = 0;
    // 当左右子树还都有元素的时候，将比较小的元素复制到临时数组中
    while (i <= mid && j <= right)
    {
        if (nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }
    // 讲左子树和右子树剩余元素复制到临时数组
    while (i <= mid)
        temp[k++] = nums[i++];
    while (j <= right)
        temp[k++] = nums[j++];
    // 将临时数组的元素复制回原数组对应的区间
    for (k = 0; k < temp.size(); k++)
        nums[left + k] = temp[k];
}

void mergeSort(vector<int> &nums, int left, int right)
{
    // 终止条件
    if (left >= right)
        return;
    int mid = (right + left) / 2;    // 计算中点
    mergeSort(nums, left, mid);      // 递归左子数组
    mergeSort(nums, mid + 1, right); // 递归右子数组
    merge(nums, left, mid, right);   // 合并阶段
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
    /* 归并排序 */
    vector<int> nums = {7, 3, 2, 6, 0, 1, 5, 4};
    mergeSort(nums, 0, nums.size() - 1);
    cout << "归并排序完成后 nums = ";
    printVector(nums);

    return 0;
}
