#include "../../include/common.hpp"

/*移动一个圆盘*/
void move(vector<int> &src, vector<int> &tar)
{
    // 从顶部拿走一个圆盘
    int back = src.back();
    src.pop_back();
    // 将圆盘放入tar顶部
    tar.push_back(back);
}

/*求解汉诺塔问题*/
void dfs(int i, vector<int> &src, vector<int> &buf, vector<int> &tar)
{
    // 若src只剩下一个圆盘，直接将其移到tar
    if (i == 1)
    {
        move(src, tar);
        return;
    }
    // 子问题f(i-1)，将src顶部i-1个圆盘借助tar移到buf
    dfs(i - 1, src, tar, buf);
    move(src, tar);
    // 子问题 f(i-1) ：将 buf 顶部 i-1 个圆盘借助 src 移到 tar
    dfs(i - 1, buf, src, tar);
}

/* 求解汉诺塔 */

void solveHanota(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int n = A.size();
    // 将 A 顶部 n 个圆盘借助 B 移到 C
    dfs(n, A, B, C);
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

/* Driver Code */
int main()
{
    // 列表尾部是柱子顶部
    vector<int> A = {5, 4, 3, 2, 1};
    vector<int> B = {};
    vector<int> C = {};

    cout << "初始状态下：\n";
    cout << "A =";
    printVector(A);
    cout << "B =";
    printVector(B);
    cout << "C =";
    printVector(C);

    solveHanota(A, B, C);

    cout << "圆盘移动完成后：\n";
    cout << "A =";
    printVector(A);
    cout << "B =";
    printVector(B);
    cout << "C =";
    printVector(C);

    return 0;
}