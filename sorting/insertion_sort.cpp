#include "../include/common.hpp"

/*插入排序*/
void insertionSort(vector<int> &nums)
{
    // 外循环：已排序元素数量为1、2、3..n
    for (int i = 1; i < nums.size(); i++)
    {
        // 暂存需要插入的元素
        int base = nums[i];
        int j = i - 1;
        // 把base插入到已排序部分的正确位置
        while (i >= 0 && nums[j] > base)
        {
            nums[j + 1] = nums[j]; // 将nums[j]向右移动一位
            j--;
        }
        nums[j + 1] = base; // 将base赋值到正确位置
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
    insertionSort(nums);
    cout << "插入排序完成后 nums = ";
    printVector(nums);

    return 0;
}