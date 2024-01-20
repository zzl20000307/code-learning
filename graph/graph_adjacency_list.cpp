#include "../include/common.hpp"

// 顶点类
struct Vertex
{
    int val;
    Vertex(int x) : val(x)
    {
    }
};

/* 基于邻接表实现的无向图类 */
class GraphAdjList
{
public:
    // 邻接表，key: 顶点，value：该顶点的所有邻接顶点
    unordered_map<Vertex *, vector<Vertex *>> adjList;

    // 在 vector 中删除指定节点
    void remove(vector<Vertex *> &vec, Vertex *vet)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == vet)
            {
                vec.erase(vec.begin() + i);
                break;
            }
        }
    }

    // 构造方法
    GraphAdjList(const vector<vector<Vertex *>> &edges)
    {
        // 添加所有的节点和边
        for (const auto &edge : edges)
        {
            addVertex(edge[0]);
            addVertex(edge[1]);
            addEdge(edge[0], edge[1]);
        }
    }

    // 添加边
    void addEdge(Vertex *vet1, Vertex *vet2)
    {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
            throw invalid_argument(" 不存在顶点 ");
        // 添加 1 2
        adjList[vet1].push_back(vet2);
        adjList[vet2].push_back(vet1);
    }

    // 删除边
    void removeEdge(Vertex *vet1, Vertex *vet2)
    {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
            throw invalid_argument(" 不存在顶点 ");
        // 删除 1 2
        remove(adjList[vet1], vet2);
        remove(adjList[vet2], vet1);
    }

    // 添加顶点
    void addVertex(Vertex *vet)
    {
        // 判断是否已经存在
        if (adjList.count(vet))
        {
            return;
        }
        // 在邻接表中添加一个新链表
        adjList[vet] = vector<Vertex *>();
    }

    // 删除顶点
    void removeVertex(Vertex *vet)
    {
        if (!adjList.count(vet))
        {
            throw invalid_argument("不存在顶点");
        }
        // 在邻接表删除顶点vet对应的链表
        adjList.erase(vet);
        // 遍历其他顶点的链表，删除所有包含vet的边
        for (auto &adj : adjList)
        {
            remove(adj.second, vet);
        }
    }

    // 获取顶点数量
    int size()
    {
        return adjList.size();
    }

    // 输入顶点列表 vets ，返回值列表 vals
    vector<int> vetsToVals(vector<Vertex *> vets)
    {
        vector<int> vals;
        for (Vertex *vet : vets)
        {
            vals.push_back(vet->val);
        }
        return vals;
    }

    // 打印数组
    template <typename T>
    void printVector(vector<T> vec)
    {
        for (auto x : vec)
            cout << "'" << to_string(x) << "'"
                 << " ";
        cout << "\n";
    }

    /* 打印邻接表 */
    void print()
    {
        cout << " 邻接表 =" << endl;
        for (auto &adj : adjList)
        {
            const auto &key = adj.first;
            const auto &vec = adj.second;
            cout << key->val << ": ";
            printVector(vetsToVals(vec));
        }
    }
};

/* 输入值列表 vals ，返回顶点列表 vets */
vector<Vertex *> valsToVets(vector<int> vals)
{
    vector<Vertex *> vets;
    for (int val : vals)
    {
        vets.push_back(new Vertex(val));
    }
    return vets;
}
int main()
{
    /* 初始化无向图 */
    vector<Vertex *> v = valsToVets(vector<int>{1, 3, 2, 5, 4});
    vector<vector<Vertex *>> edges = {{v[0], v[1]}, {v[0], v[3]}, {v[1], v[2]}, {v[2], v[3]}, {v[2], v[4]}, {v[3], v[4]}};
    GraphAdjList graph(edges);
    cout << "\n初始化后，图为" << endl;
    graph.print();

    /* 添加边 */
    // 顶点 1, 2 即 v[0], v[2]
    graph.addEdge(v[0], v[2]);
    cout << "\n添加边 1-2 后，图为" << endl;
    graph.print();

    /* 删除边 */
    // 顶点 1, 3 即 v[0], v[1]
    graph.removeEdge(v[0], v[1]);
    cout << "\n删除边 1-3 后，图为" << endl;
    graph.print();

    /* 添加顶点 */
    Vertex *v5 = new Vertex(6);
    graph.addVertex(v5);
    cout << "\n添加顶点 6 后，图为" << endl;
    graph.print();

    /* 删除顶点 */
    // 顶点 3 即 v[1]
    graph.removeVertex(v[1]);
    cout << "\n删除顶点 3 后，图为" << endl;
    graph.print();

    // 释放内存
    for (Vertex *vet : v)
    {
        delete vet;
    }

    return 0;
}