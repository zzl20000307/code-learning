#include "common.hpp"

struct Pair
{
public:
    int num;
    string name;

    Pair(int num, string name)
    {
        this->num = num;
        this->name = name;
    }
};

// 基于数组简易实现哈希表
class ArrayHashMap
{
private:
    vector<Pair *> stu;

public:
    ArrayHashMap()
    {
        stu = vector<Pair *>(10);
    }
    ~ArrayHashMap()
    {
        for (auto x : stu)
        {
            delete x;
        }
        stu.clear();
    }
    // 哈希函数
    int hashFunc(int num)
    {
        return num % 100;
    }
    // 查询操作
    string get(int num)
    {
        int index = hashFunc(num);
        Pair *pair = stu[index];
        if (pair != nullptr)
        {
            return pair->name;
        }
        return "";
    }
    // 添加操作
    void put(int num, string name)
    {
        Pair *p = new Pair(num, name);
        int index = hashFunc(num);
        stu[index] = p;
    }
    // 删除操作
    void remove(int num)
    {
        int index = hashFunc(num);
        Pair *p = stu[index];
        if (p != nullptr)
        {
            delete stu[num];
            stu[num] = nullptr;
        }
    }
    // 获取所有键值对
    vector<Pair *> getPair()
    {
        vector<Pair *> p;
        for (auto x : stu)
        {
            if (x != nullptr)
            {
                p.push_back(x);
            }
        }
        return p;
    }
    // 打印哈希表
    void print()
    {
        for (auto x : getPair())
        {
            cout << x->num << "->" << x->name << endl;
        }
    }
};

// int main()
// {
//     ArrayHashMap map = ArrayHashMap();
//     map.put(1, "z");
//     map.put(2, "l");
//     map.put(3, "l");
//     cout << "哈希表：" << endl;
//     cout << "num->name" << endl;
//     map.print();
//     map.remove(2);
//     map.print();
// }
