#include "../../include/common.hpp"
#include "./graph_adjacency_list.cpp"

/* 深度优先遍历 DFS */

/*深度优先遍历 DFS 辅助函数*/
void dfs(GraphAdjList &graph, unordered_set<Vertex *> &visited, vector<Vertex *> &res, Vertex *vet)
{
    res.push_back(vet);   // 记录访问顶点
    visited.emplace(vet); // 标记该顶点已经被访问
    // 遍历该顶点的所有邻接顶点
    for (Vertex *x : graph.adjList[vet])
    {
        if (visited.count(x))
            continue; // 跳过已经访问过的顶点
        // 递归访问邻接顶点
        dfs(graph, visited, res, x);
    }
}

/*深度优先遍历 DFS*/
// 使用邻接表来表示图，以便获取指定顶点的所有邻接顶点

vector<Vertex *> graphDFS(GraphAdjList &graph, Vertex *startVet)
{
    // 顶点遍历序列
    vector<Vertex *> res;
    // 哈希表，用于记录已经访问过的元素
    unordered_set<Vertex *> visited;
    dfs(graph, visited, res, startVet);
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




int main() {
    /* 初始化无向图 */
    vector<Vertex *> v = valsToVets(vector<int>{0, 1, 2, 3, 4, 5, 6});
    vector<vector<Vertex *>> edges = {{v[0], v[1]}, {v[0], v[3]}, {v[1], v[2]},
                                      {v[2], v[5]}, {v[4], v[5]}, {v[5], v[6]}};
    GraphAdjList graph(edges);
    cout << "\n初始化后，图为" << endl;
    graph.print();

    /* 深度优先遍历 DFS */
    vector<Vertex *> res = graphDFS(graph, v[0]);
    cout << "\n深度优先遍历（DFS）顶点序列为" << endl;
    printVector(vetsToVals(res));

    // 释放内存
    for (Vertex *vet : v) {
        delete vet;
    }

    return 0;
}