#include <iostream>
#include <thread>
using namespace std;

// 输入n，打印从1到n的所有整数
void printNumber(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << endl;
    }
}

int main()
{
    // 创建一个子线程，打印从1到1000的所有整数
    thread thread1(printNumber, 1000);
    // 判断子线程是否joinable
    bool isJoin = thread1.joinable();
    if (isJoin)
    {
        // 阻塞主线程，等待子线程执行完毕
        thread1.join();
    }
    // 用英文打印主线程继续执行
    cout << "Main thread continue" << endl;
    return 0;
}