#include "../../include/common.hpp"

/* 爬楼梯最小代价：动态规划 */

int minCostClimbingStairsDP(vector<int> &cost)
{
    int n = cost.size() - 1;
    if (n == 1 || n == 2)
        return cost[n];
    // 初始化 dp 表，用于存储子问题的解
    vector<int> dp(n + 1);
    dp[1] = cost[1];
    dp[2] = cost[2];
    // 状态转移：从较小子问题逐步求解较大子问题
    for (int i = 3; i <= n; i++)
    {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    return dp[n];
}

/* 爬楼梯最小代价：空间优化后的动态规划 */
int minCostClimbingStairsDPComp(vector<int> &cost)
{
    int n = cost.size() - 1;
    if (n == 1 || n == 2)
        return cost[n];
    int a = cost[1];
    int b = cost[2];
    for (int i = 3; i <= n; i++)
    {
        int temp = b;
        b = min(a, temp) + cost[i];
        a = temp;
    }
    return b;
}

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
    vector<int> cost = {0, 1, 10, 1, 1, 1, 10, 1, 1, 10, 1};
    cout << "输入楼梯的代价列表为 ";
    printVector(cost);

    int res = minCostClimbingStairsDP(cost);
    cout << "爬完楼梯的最低代价为 " << res << endl;

    res = minCostClimbingStairsDPComp(cost);
    cout << "爬完楼梯的最低代价为 " << res << endl;

    return 0;
}
