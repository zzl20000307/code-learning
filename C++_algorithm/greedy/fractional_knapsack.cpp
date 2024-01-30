#include "../../include/common.hpp"

/* 物品 */
class Item
{
public:
    int w;
    int v;
    Item(int w, int v) : w(w), v(v)
    {
    }
};

/* 分数背包：贪心 */

double fractionalKnapsack(vector<int> &wgt, vector<int> &val, int cap)
{
    // 创建物品列表，包含两个属性：重量、价值
    vector<Item> items;
    for (int i = 0; i < wgt.size(); i++)
    {
        items.push_back(Item(wgt[i], val[i]));
    }
    // 按照单位价值 item.v / item.w 从高到低进行排序
    sort(items.begin(), items.end(), [](Item &a, Item &b)
         { return (double)a.v / a.w > (double)b.v / b.w; });

    // 循环贪心选择
    double res = 0;
    for (auto &item : items)
    {
        if (item.v <= cap)
        {
            // 若剩余容量充足，则将当前物品整个装进背包
            res += item.v;
            cap -= item.w;
        }
        else
        {
            // 若剩余容量不足，则将当前物品的一部分装进背包
            res += (double)cap * item.v / item.w;
            // 已无剩余容量，因此跳出循环
            break;
        }
    }
    return res;
}

/* Driver Code */
int main()
{
    vector<int> wgt = {10, 20, 30, 40, 50};
    vector<int> val = {50, 120, 150, 210, 240};
    int cap = 50;

    // 贪心算法
    double res = fractionalKnapsack(wgt, val, cap);
    cout << "不超过背包容量的最大物品价值为 " << res << endl;

    return 0;
}