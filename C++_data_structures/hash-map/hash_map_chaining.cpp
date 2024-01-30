#include "array_hash_map.cpp"

// 链式地址哈希表
class HashMapChaining
{
private:
    int size;                    // 键值对数量
    int capacity;                // 哈希表容量
    double threshold;            // 阈值
    int extendRatio;             // 扩容倍数
    vector<vector<Pair *>> stus; // 桶数组
    int extend_num = 0;          // 扩容次数

public:
    // 构造函数
    HashMapChaining() : size(0), capacity(3), threshold(2.0 / 3.0), extendRatio(2)
    {
        stus = vector<vector<Pair *>>(capacity);
        stus.resize(capacity);
    }
    // 析构函数
    ~HashMapChaining()
    {
        for (auto x : stus)
        {
            for (auto y : x)
            {
                delete y;
            }
            x.clear();
        }
        stus.clear();
    }
    // 哈希函数
    int hashFunc(int num)
    {
        return num % capacity;
    }
    // 负载因子
    double loadFactor()
    {
        return (double)size / (double)capacity;
    }
    // 查询操作
    string get(int num)
    {
        int index = hashFunc(num);
        for (auto x : stus[index])
        {
            if (x->num == num)
            {
                return x->name;
            }
        }
        return "";
    }
    // 添加操作
    void put(int num, string name)
    {
        if (loadFactor() > threshold)
        {
            extend();
        }
        int index = hashFunc(num);
        // 遍历，如果遇到指定的key，则更新对应al并返回
        for (auto x : stus[index])
        {
            if (num == x->num)
            {
                x->name = name;
                return;
            }
        }
        // 若没有，则将键值对添加到尾部
        stus[index].push_back(new Pair(num, name));
        size++;
    }

    // 扩容哈希表
    void extend()
    {
        // 暂存原来的哈希表
        vector<vector<Pair *>> stus_temp = stus;
        // 初始化扩容后的哈希表
        capacity *= extendRatio;
        stus.clear();
        stus.resize(capacity);
        size = 0;
        // 将键值对从原哈希表搬运到新哈希表
        for (auto stu_temp : stus_temp)
        {
            for (auto x : stu_temp)
            {
                put(x->num, x->name);
                delete x;
            }
        }
        extend_num++;
        cout << "当前已经扩容了" << extend_num << "次" << endl;
    }

    void remove(int num)
    {
        int index = hashFunc(num);
        // 遍历桶，从中删除键值对
        for (auto iter = stus[index].begin(); iter!= stus[index].end(); iter++)
        {
            if((*iter)->num==num)
            {
                auto temp=*iter;
                stus[index].erase(iter);
                delete temp;
                size--;
                return;
            }
        }
    }

    // 打印哈希表
    void print()
    {
        for (auto x : stus)
        {
            cout << "[";
            for (auto y : x)
            {
                cout << y->num << "->" << y->name << ",";
            }
            cout << "]" << endl;
        }
    }
};

int main()
{
    HashMapChaining map = HashMapChaining();
    map.put(11, "1");
    map.put(111,"zzl");
    map.put(2, "2");
    map.put(3, "3");
    map.put(4, "4");
    map.put(4, "5");
    map.print();
    map.remove(3);
    map.print();
    return 0;
}