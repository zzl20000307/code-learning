#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int *data;    // 指向动态数组的指针
    int size;     // 数组的大小
    int capacity; // 数组的容量

    // 扩容函数，将容量翻倍
    void resize()
    {
        capacity *= 2;                    // 容量翻倍
        int *newData = new int[capacity]; // 分配新的内存空间
        for (int i = 0; i < size; i++)
        { // 复制原数组的元素
            newData[i] = data[i];
        }
        delete[] data;  // 释放原数组的内存空间
        data = newData; // 更新指针
    }

public:
    // 构造函数，接受一个初始容量参数，默认为10
    DynamicArray(int cap = 10)
    {
        data = new int[cap]; // 分配初始容量的内存空间
        size = 0;            // 初始大小为0
        capacity = cap;      // 记录容量
    }

    // 析构函数，释放动态数组的内存空间
    ~DynamicArray()
    {
        delete[] data; // 释放内存空间
    }

    // 拷贝构造函数，实现深拷贝
    DynamicArray(const DynamicArray &arr)
    {
        data = new int[arr.capacity]; // 分配和原数组相同容量的内存空间
        size = arr.size;              // 复制原数组的大小
        capacity = arr.capacity;      // 复制原数组的容量
        for (int i = 0; i < size; i++)
        { // 复制原数组的元素
            data[i] = arr.data[i];
        }
    }

    // 赋值运算符，实现深拷贝
    // 注意：返回类型为引用，参数为常量引用
    DynamicArray &operator=(const DynamicArray &arr)
    {
        if (this != &arr)
        {                                 // 避免自赋值
            delete[] data;                // 释放原数组的内存空间
            data = new int[arr.capacity]; // 分配和原数组相同容量的内存空间
            size = arr.size;              // 复制原数组的大小
            capacity = arr.capacity;      // 复制原数组的容量
            for (int i = 0; i < size; i++)
            { // 复制原数组的元素
                data[i] = arr.data[i];
            }
        }
        return *this; // 返回自身的引用
    }
    // 下标运算符，实现通过下标访问和修改元素
    int &operator[](int index)
    {
        if (index < 0 || index >= size)
        { // 检查下标是否越界
            cout << "Index out of range!" << endl;
            exit(1); // 退出程序
        }
        return data[index]; // 返回对应元素的引用
    }
    // 大小函数，返回数组的大小
    int getSize()
    {
        return size;
    }

    // 容量函数，返回数组的容量
    int getCapacity()
    {
        return capacity;
    }

    // 插入函数，向数组的末尾插入一个元素
    void insert(int value)
    {
        if (size == capacity)
        { // 如果数组已满，就扩容
            resize();
        }
        data[size] = value; // 在末尾插入元素
        size++;             // 更新大小
    }

    // 删除函数，从数组的末尾删除一个元素，并返回它
    int remove()
    {
        if (size == 0)
        { // 如果数组为空，就返回-1
            return -1;
        }
        int value = data[size - 1]; // 记录末尾元素的值
        size--;                     // 更新大小
        return value;               // 返回被删除的元素
    }

    // 打印函数，打印数组的所有元素
    void print()
    {
        cout << "Size: " << size << ", Capacity: " << capacity << endl; // 打印大小和容量
        cout << "[";
        for (int i = 0; i < size; i++)
        {                    // 遍历数组元素
            cout << data[i]; // 打印元素
            if (i != size - 1)
            { // 如果不是最后一个元素，就打印逗号和空格
                cout << ", ";
            }
        }
        cout << "]" << endl; // 打印右括号和换行
    }
};

int main()
{
    DynamicArray arr;                 // 创建一个动态数组对象
    arr.insert(10);                   // 插入元素10
    arr.insert(20);                   // 插入元素20
    arr.insert(30);                   // 插入元素30
    arr.print();                      // 打印数组
    arr[1] = 40;                      // 修改第二个元素为40
    arr.print();                      // 打印数组
    int x = arr.remove();             // 删除末尾元素并赋值给x
    cout << "Removed: " << x << endl; // 打印被删除的元素
    arr.print();                      // 打印数组
    return 0;
}
