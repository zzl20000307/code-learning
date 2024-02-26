// 单例模式
#include <iostream>
#include <mutex>
#include <thread>
#include <string>
using namespace std;

class Log
{
public:
    // 静态成员函数只能访问静态成员变量
    static Log &getInstance()
    {
        call_once(m_flag, init);
        return *log;
    }

    static void init()
    {
        if (!log)
            log = new Log();
    }

    void print(const string &msg)
    {
        cout << __TIME__ << " " << msg << endl;
    }
    // 析构函数
    ~Log()
    {
        if (log)
            delete log;
    }

private:
    Log(){};                                 // 构造函数私有化，防止外部创建实例
    Log(const Log &log) = delete;            // 禁止拷贝构造函数
    Log &operator=(const Log &log) = delete; // 禁止赋值运算


    // 静态成员变量的声明，一般需要在类外进行定义
    static Log *log; // 定义了一个指针，是一个指向Log类对象的指针
    static once_flag m_flag;
};

// 类外：定义类内成员变量
Log *Log::log = nullptr;
once_flag Log::m_flag;


void printError(const string &msg)
{
    Log::getInstance().print(msg);
}
int main()
{
    thread t1(printError, "t1");
    thread t2(printError, "t2");
    t1.join();
    t2.join();
    cout << "main thread continue" << endl;
    return 0;
}

// 在c++中，类的静态成员变量必须在类外进行定义，否则会报错
// 类的静态成员变量的定义格式：
// 类型 类名::静态成员变量名 = 初始值;
