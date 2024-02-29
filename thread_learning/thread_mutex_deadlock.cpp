#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
// 当一个锁被一个线程锁住后，其他线程如果再次尝试锁这个锁，会被阻塞，直到锁被解锁
mutex mtx1, mtx2;

/*
void func_1()
{
    for (int i = 0; i < 5000; i++)
    {
        mtx1.lock();
        mtx2.lock();
        cout << "func_1" << endl;
        mtx1.unlock();
        mtx2.unlock();
    }
}

void func_2()
{
    for (int i = 0; i < 5000; i++)
    {
        mtx2.lock();
        mtx1.lock();
        cout << "func_2" << endl;
        mtx2.unlock();
        mtx1.unlock();
    }
}
*/


// 如何解决上述问题？
// 改变一下顺序
int m=0;
void func_1()
{
    for (int i = 0; i < 50; i++)
    {
        mtx1.lock();
        mtx2.lock();
        cout << "func_1" << endl;
        m++;
        mtx1.unlock();
        mtx2.unlock();
    }
}

void func_2()
{
    for (int i = 0; i < 50; i++)
    {
        mtx1.lock();
        mtx2.lock();
        cout << "func_2" << endl;
        m++;
        mtx1.unlock();
        mtx2.unlock();
    }
}

int main()
{
    thread t1(func_1);
    thread t2(func_2);
    t1.join();
    t2.join();
    cout<<"m="<<m<<endl;
    cout << "over" << endl;
}