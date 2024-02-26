// 多线程条件变量的使用
#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
using namespace std;

mutex mtx;
queue<int> q;
condition_variable cv;

void Producer()
{
    for (int i = 0; i < 50; i++)
    {
        {
            unique_lock<mutex> ul(mtx);
            q.push(i);
            cout << "producer:"
                 << " " << i << endl;
        }
        cv.notify_one();
        this_thread::sleep_for(chrono::microseconds(100));
    }
}

void Consumer()
{
    while (1)
    {
        {
            unique_lock<mutex> ul(mtx);
            cv.wait(ul, []()
                    { return !q.empty(); });
            cout
                << "consumer:"
                << " " << q.front() << endl;
            q.pop();
        }
    }
}

int main()
{
    thread t1(Producer);
    thread t2(Consumer);
    t1.join();
    t2.join();
    cout << "main thread continue" << endl;
    return 0;
}
// 问题：当消费者进入等待状态，互斥量的使用权会转移吗？
// 回答：1.互斥量的使用权会转移，当消费者进入等待状态时，互斥量会释放，生产者会获得互斥量的使用权
//      2.生产者生产完数据后，会通知消费者，消费者会重新获得互斥量的使用权，然后消费数据。