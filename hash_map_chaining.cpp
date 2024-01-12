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

public:
    // 构造函数
    HashMapChaining() : size(0), capacity(4), threshold(2.0 / 3.0), extendRatio(2)
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
};