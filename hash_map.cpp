#include "common.hpp"

template <typename key, typename value>
void printHashMap(unordered_map<key, value> map);

int main()
{
    // 添加操作
    unordered_map<int, string> map;
    map[1] = "z";
    map[2] = "z";
    map[3] = "l";
    cout << "哈希表" << endl;
    cout << "key->value:" << endl;
    printHashMap(map);
    // 查询操作
    string name = map[1];
    cout << "输入学号1，名字为：" << name << endl;
    // 删除操作
    map.erase(1);
    cout << "删除后的哈希表" << endl;
    cout << "key->value:" << endl;
    printHashMap(map);
    // 遍历哈希表
    cout << "\n遍历键值对 key->value：" << endl;
    for (auto x : map)
    {
        cout << x.first << "->" << x.second << endl;
    }
    cout << "\n使用迭代器遍历 key->value：" << endl;
    for(auto iter=map.begin();iter!=map.end();iter++)
    {
        cout<<iter->first<<"->"<<iter->second<<endl;
    }

}

template <typename key, typename value>
void printHashMap(unordered_map<key, value> map)
{
    for (auto x : map)
    {
        cout << x.first << " -> " << x.second << endl;
    }
}