#include "../../include/common.hpp"

/* 零钱兑换：贪心 */

int coinChangeGreedy(vector<int> &coins, int amt)
{
    // 假设coins列表有序
    int i = coins.size() - 1;
    int count = 0;
    // 循环贪心选择，直至没有剩余金币
    while (amt > 0)
    {
        // 找到小于且最接近剩余金额的硬币
        while (coins[i] > amt && i > 0)
            i--;
        // 选择coins[i]
        amt -= coins[i];
        count++;
    }
    // 若未找到可行方案，则返回 -1
    return amt == 0 ? count : -1;
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
    // 贪心：能够保证找到全局最优解
    vector<int> coins = {1, 5, 10, 20, 50, 100};
    int amt = 186;
    int res = coinChangeGreedy(coins, amt);
    cout << "\ncoins = ";
    printVector(coins);
    cout << "amt = " << amt << endl;
    cout << "凑到 " << amt << " 所需的最少硬币数量为 " << res << endl;
} 