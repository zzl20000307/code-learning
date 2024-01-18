#include "../include/common.hpp"

/*桶排序*/

void bucketSort(vector<float> &nums)
{
    // 初始化k=n/2个桶，预期向每个桶分配两个元素
    int k = nums.size() / 2;
    vector<vector<float>> buckets(k);
    // 将数组元素分配到各个桶中
    for (auto num : nums)
    {
        // 输入数据范围 [0, 1) ，使用 num * k 映射到索引范围 [0, k-1]
        int i = num * k;
        // 将num添加进桶bucket_idx
        buckets[i].push_back(num);
    }
    // 堆各个桶进行排序
    for (auto &bucket : buckets)
    {
        // 使用内置排序函数，也可以替换成其他排序算法
        sort(bucket.begin(), bucket.end());
    }
    int i = 0;
    for (vector<float> &bucket : buckets)
    {
        for (float num : bucket)
        {
            nums[i++] = num;
        }
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
    // 设输入数据为浮点数，范围为 [0, 1)
    vector<float> nums = {0.49f, 0.96f, 0.82f, 0.09f, 0.57f, 0.43f, 0.91f, 0.75f, 0.15f, 0.37f};
    bucketSort(nums);
    cout << "桶排序完成后 nums = ";
    printVector(nums);

    return 0;
}