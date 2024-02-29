#include <iostream>
#include <thread>
using namespace std;
/*
void foo(int &x)
{
    x++;
}

int main()
{
    thread t(foo, 10);// 传递临时变量
    t.join();
    return 0;
}
*/
// 存在的问题：将foo函数以及一个临时变量10作为参数传递给线程t，但是foo函数的参数是一个引用，而临时变量10是一个右值，在线程函数执行时就会被销毁，无法直接传递给引用类型的参数。从而导致未定义的问题。
// 什么是右值？右值是指表达式结束时就会消失的值，例如临时变量、常量等。右值引用是C++11新增的特性，可以绑定到右值上，用于解决右值的传递问题。

// 解决办法：使用std::ref()函数将临时变量转换为引用类型，从而解决传递右值的问题。
/*
void foo(int &x)
{
    x++;
}
int main()
{
    int x = 10;
    thread t(foo, ref(x)); // 传递引用
    t.join();
    cout << x << endl; // 输出11
    return 0;
}
*/

// 2.类成员函数作为入口函数
/*
class MyClass
{
public:
    void func()
    {
        cout << "thread start" << endl;
    }
};
int main()
{
    MyClass obj;

    thread t(&MyClass::func, &obj);
    // obj 被提前销毁了，会导致未定义的行为
    t.join();
    return 0;
}
*/
// 使用std::shard_ptr智能指针来管理类对象的生命周期，这样，在线程执行期间，即使类对象的所有者被释放，std::shard_ptr仍然会保持对象的生命周期，直到线程结束。
#include <memory>

class MyClass
{
public:
    void func()
    {
        cout << "thread start" << endl;
    }
};

int main()
{
    shared_ptr<MyClass>obj=make_shared<MyClass>();
    thread t(&MyClass::func,obj);
    t.join();
    cout<<"main thread continue"<<endl;
    return 0;

}
