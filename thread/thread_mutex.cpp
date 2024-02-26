#include <iostream>
#include <thread>
// 使用互斥锁保护共享数据
#include <mutex>
using namespace std;
int a = 0;
mutex mtx;
void func()
{
    // 线程执行100000次，每次对共享变量a加1
    for (int i = 0; i < 100000; i++)
    {
        // 解决的问题：多个线程同时访问共享数据a，可能会导致数据不一致的问题，因此需要使用互斥锁保护共享数据。
        mtx.lock();
        a++;
        mtx.unlock();
    }
}


int main()
{
    thread t1(func);
    thread t2(func);
    t1.join();
    t2.join();
    cout << "a=" << a << endl;
    return 0;
}

// 互斥锁的使用步骤：
// 1.包含头文件<mutex>
// 2.创建std::mutex类型的互斥锁对象
// 3.在访问共享数据之前，调用互斥锁对象的lock()成员函数，对共享数据进行加锁
// 4.在访问共享数据之后，调用互斥锁对象的unlock()成员函数，对共享数据进行解锁
// 5.使用互斥锁保护共享数据，可以避免多个线程同时访问共享数据，从而避免数据不一致的问题
// 6.互斥锁的lock()和unlock()成员函数必须成对出现，否则会导致死锁问题
// 7.互斥锁的lock()和unlock()成员函数调用之间的代码，称为临界区，是一个临界资源，需要保护起来

// 总结一下这段代码：
// 1.定义了一个全局变量a，初始值为0
// 2.定义了一个互斥锁对象mtx
// 3.定义了一个线程函数func，线程执行100000次，每次对共享变量a加1
// 4.在主函数main中，创建两个线程t1和t2，分别执行func函数
// 5.主线程等待两个子线程执行完毕，然后输出共享变量a的值

