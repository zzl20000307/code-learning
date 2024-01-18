#include "../include/common.hpp"

/*冒泡排序*/
void bubbleSort(vector<int> &nums)
{
    // 外循环：未排序区间为[0,i]
    for (int i = nums.size(); i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        // 内循环：将未排序区间[0，i]中的最大元素交换至该区间的最有端
        {
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
        }
    }
}

/*效率优化
如果某轮“冒泡”中没有执行任何交换操作，说明数组已经完成排序，可直接返回结果。因此，可以增加一个标志位 flag 来监测这种情况，一旦出现就立即返回。
*/

void bubbleSortWithFlag(vector<int> &nums)
{
    // 外循环：未排序区间为[0,i]
    for (int i = nums.size(); i > 0; i--)
    {
        bool flag = true;
        for (int j = 0; j < i; j++)
        // 内循环：将未排序区间[0，i]中的最大元素交换至该区间的最有端
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                flag = false;
            }
        }
        if (flag)
            break;
    }
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

int main()
{
    vector<int> nums = {4, 1, 3, 1, 5, 2};
    bubbleSort(nums);
    cout << "冒泡排序完成后 nums = ";
    printVector(nums);

    vector<int> nums1 = {4, 1, 3, 1, 5, 2};
    bubbleSortWithFlag(nums1);
    cout << "冒泡排序完成后 nums1 = ";
    printVector(nums1);

    return 0;
}
