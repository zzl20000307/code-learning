#include <iostream>
// Lambda函数的按值捕获和按引用捕获
int main()
{
    int a = 5;
    int b = 10;
    auto lambda_by_value = [a, &b]()
    {
        // a 是按值捕获，Lambda函数内部使用的是捕获时的 a 的值
        // b 是按引用捕获，Lambda函数内部使用的是捕获时的 b 的地址
        std::cout << "Inside lambda: " << a << " " << b << std::endl;
    };

    a = 10;
    b = 60;
    
    // 调用Lambda函数
    lambda_by_value(); // 输出 5、60
    return 0;
}
