#include <iostream>
#include <thread>
// 使用互斥锁保护共享数据
#include <mutex>
using namespace std;
// unique_lock的使用
timed_mutex mtx;
int shard_data = 0;
void func()
{
    for (int i = 0; i < 20; i++)
    {
        unique_lock<timed_mutex> ul(mtx,defer_lock);
        // 使用try_lock_for()函数尝试加锁，如果加锁成功，返回true，否则返回false
        // 使用秒
        if (ul.try_lock_for(chrono::seconds(2)))
        {

            this_thread::sleep_for(chrono::seconds(1));
            shard_data++;
        }
        else
        { 
            cout << "func加锁失败" << endl;
        }
    }
}

int main()
{
    thread t1(func);
    thread t2(func);
    t1.join();
    t2.join();
    cout << "shard_data=" << shard_data << endl;
    return 0;
}