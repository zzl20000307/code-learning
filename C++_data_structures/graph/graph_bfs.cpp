#include "../../include/common.hpp"
#include "./graph_adjacency_list.cpp"

/* 广度优先遍历 BFS */
// 使用邻接表来表示图，以便获取指定顶点的所有邻接顶点

vector<Vertex *> graphBFS(GraphAdjList &graph, Vertex *startVet)
{
    // 顶点遍历序列
    vector<Vertex *> res;
    // 哈希表，用于记录已经被访问过的顶点
    // unordered_set用于存储不重复的元素的容器
    unordered_set<Vertex *> visited = {startVet};
    // 队列用于实现BFS
    queue<Vertex *> que;
    que.push(startVet);
    // 以顶点vet为起点，循环直至访问完所有顶点
    while (!que.empty())
    {
        Vertex *vet = que.front();
        que.pop(); // 顶点出列
        res.push_back(vet);
        // 遍历该顶点的所有邻接顶点
        for (auto x : graph.adjList[vet])
        {
            if (visited.count(x))
                continue;
            que.push(x);
            visited.emplace(x);
        }
    }
    // 返回顶点遍历序列
    return res;
}

/* 输入顶点列表 vets ，返回值列表 vals */
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

int main()
{
    /* 初始化无向图 */
    vector<Vertex *> v = valsToVets({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    vector<vector<Vertex *>> edges = {{v[0], v[1]}, {v[0], v[3]}, {v[1], v[2]}, {v[1], v[4]}, {v[2], v[5]}, {v[3], v[4]}, {v[3], v[6]}, {v[4], v[5]}, {v[4], v[7]}, {v[5], v[8]}, {v[6], v[7]}, {v[7], v[8]}};
    GraphAdjList graph(edges);
    cout << "\n初始化后，图为\\n";
    graph.print();

    /* 广度优先遍历 BFS */
    vector<Vertex *> res = graphBFS(graph, v[0]);
    cout << "\n广度优先遍历（BFS）顶点序列为" << endl;
    printVector(vetsToVals(res));

    // 释放内存
    for (Vertex *vet : v)
    {
        delete vet;
    }

    return 0;
}