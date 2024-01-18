#include "../include/common.hpp"

/*选择排序*/

void selectionSort(vector<int> &nums)
{
    int n = nums.size();
    // 外循环，未排序区间为[i,n-1]
    for (int i = 0; i < n - 1; i++)
    {
        int k = i;
        // 内循环：找到未排序区间的最小元素
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[k])
                k = j; // 记录下最小元素的索引
        }
        // 将该最小元素与未排序区间的首元素交换
        swap(nums[k], nums[i]);
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
    selectionSort(nums);
    cout << "选择排序完成后 nums = ";
    printVector(nums);
    return 0;
}