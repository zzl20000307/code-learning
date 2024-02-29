#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
// lock_guard是一个互斥锁的封装类，它的作用是在构造时锁住互斥锁，在析构时解锁互斥锁
// 如何使用lock_guard？
// 1.包含头文件<mutex>
// 2.创建std::mutex类型的互斥锁对象
// 3.在访问共享数据之前，使用std::lock_guard<std::mutex>对象对互斥锁进行加锁
// 4.在访问共享数据之后，std::lock_guard<std::mutex>对象析构时，对互斥锁进行解锁
// 5.使用std::lock_guard<std::mutex>对象保护共享数据，可以避免多个线程同时访问共享数据，从而避免数据不一致的问题
// 那什么时候调用析构函数呢，如何知道？
// 1.在std::lock_guard<std::mutex>对象创建时，会自动调用互斥锁的lock()成员函数，对互斥锁进行加锁
// 2.在std::lock_guard<std::mutex>对象销毁时，会自动调用互斥锁的unlock()成员函数，对互斥锁进行解锁
// 3.因此，std::lock_guard<std::mutex>对象的生命周期，就是互斥锁的加锁和解锁的生命周期
mutex mtx;
int m = 0;
void func()
{
    for (int i = 0; i < 50; i++)
    {
        lock_guard<mutex> lg(mtx);
        m++;
    }
}
int main()
{
    thread t1(func);
    thread t2(func);
    t1.join();
    t2.join();
    cout<<"m="<<m<<endl;
    return 0;
}