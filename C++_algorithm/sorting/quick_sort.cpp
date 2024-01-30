#include "../../include/common.hpp"

/*快速排序类*/
class QuickSort
{
private:
    /* 哨兵划分 */
    static int partion(vector<int> &nums, int left, int right)
    {
        // 以nums[left]作为基准数
        int i = left, j = right;
        while (i < j)
        {
            while (i < j && nums[j] >= nums[left])
            {
                j--; // 从右向左查找首个小于基准数的元素
            }
            while (i < j && nums[i] <= nums[left])
            {
                i++; // 从左向右查找首个大于基准数的元素
            }
            // 交换这两个元素
            swap(nums[i], nums[j]);
        }
        // 将基准数交换至两个子数组的分界线
        swap(nums[i], nums[left]);
        return i; // 返回基准数的索引
    }

public:
    static void quickSort(vector<int> &nums, int left, int right)
    {
        // 子数组长度为1时中止递归
        if (left >= right)
            return;

        // 哨兵划分
        int pivot = partion(nums, left, right);

        // 递归左子数组
        quickSort(nums, left, pivot - 1);
        // 递归右子数组
        quickSort(nums, pivot + 1, right);
    }
};

/*快速排序类（中位基准数优化）*/
class QuickSortMedian
{
private:
    static int medianThree(vector<int> &nums, int left, int mid, int right)
    {
        // 此处使用异或运算来简化代码
        // 异或规则为 0 ^ 0 = 1 ^ 1 = 0, 0 ^ 1 = 1 ^ 0 = 1
        if ((nums[left] < nums[mid]) ^ (nums[left] < nums[right]))
            return left;
        else if ((nums[mid] < nums[left]) ^ (nums[mid] < nums[right]))
            return mid;
        else
            return right;
    }

    static int partion(vector<int> &nums, int left, int right)
    {
        int mid = medianThree(nums, left, (left + right) / 2, right);
        swap(nums[left], nums[mid]);
        // 以nums[left]作为基准数
        int i = left, j = right;
        while (i < j)
        {
            while (i < j && nums[j] >= nums[left])
            {
                j--; // 从右向左查找首个小于基准数的元素
            }
            while (i < j && nums[i] <= nums[left])
            {
                i++; // 从左向右查找首个大于基准数的元素
            }
            // 交换这两个元素
            swap(nums[i], nums[j]);
        }
        // 将基准数交换至两个子数组的分界线
        swap(nums[i], nums[left]);
        return i; // 返回基准数的索引
    }

public:
    static void quickSort(vector<int> &nums, int left, int right)
    {
        // 子数组长度为1时中止递归
        if (left >= right)
            return;

        // 哨兵划分
        int pivot = partion(nums, left, right);

        // 递归左子数组
        quickSort(nums, left, pivot - 1);
        // 递归右子数组
        quickSort(nums, pivot + 1, right);
    }
};

// 打印
template <typename T>
void printVector(vector<T> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << to_string(vec[i]) << " ";
    }
}

// 测试
int main()
{
    /* 快速排序 */
    vector<int> nums{2, 4, 1, 0, 3, 5};
    QuickSort::quickSort(nums, 0, nums.size() - 1);
    cout << "快速排序完成后 nums = ";
    printVector(nums);

    /* 快速排序（中位基准数优化） */
    vector<int> nums1 = {2, 4, 1, 0, 3, 5};
    QuickSortMedian::quickSort(nums1, 0, nums1.size() - 1);
    cout << "快速排序（中位基准数优化）完成后 nums = ";
    printVector(nums);
}
