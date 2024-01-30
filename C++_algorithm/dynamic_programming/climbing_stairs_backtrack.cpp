#include "../../include/common.hpp"

/*回溯*/
void backtrack(vector<int> &choices, int state, int n, vector<int> &res)
{
    // 当爬到第n阶时，方案数量加1
    if (state == n)
    {
        res[0]++;
    }
    // 遍历所有选择
    for (auto choice : choices)
    {
        // 剪枝：不允许越过第n阶
        if (state + choice > n)
            break;
        // 尝试：作出选择，更新状态
        backtrack(choices, state + choice, n, res);
        // 回退
    }
}

/*爬楼梯：回溯*/
int climbingStairsBacktrack(int n)
{
    vector<int> choices = {1, 2}; // 可选择向上爬 1 或 2 阶
    int state = 0;                // 从第0阶开始向上爬
    vector<int> res = {0};        // 使用res[0]记录方案数量
    backtrack(choices, state, n, res);
    return res[0];
}

/* Driver Code */
int main()
{
    int n = 9;
    int res = climbingStairsBacktrack(n);
    cout << "爬 " << n << " 阶楼梯共有 " << res << " 种方案" << endl;
    return 0;
}