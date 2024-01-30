#include "../../include/common.hpp"

/*基于邻接矩阵实现的无向图类*/
class GraphAdjMat
{
private:
    vector<int> vertices;       // 列表元素，元素代表“顶点值”，索引代表“顶点索引”
    vector<vector<int>> adjMat; // 邻接矩阵，行列索引对应“顶点索引”
public:
    // 构造方法
    GraphAdjMat(const vector<int> &vertices, const vector<vector<int>> &edges)
    {
        // 添加顶点
        for (auto val : vertices)
        {
            addVertex(val);
        }
        // 添加边
        // edges代表顶点索引
        for (const vector<int> &edge : edges)
        {
            addEdge(edge[0], edge[1]);
        }
    }

    // 获取顶点数量
    int size()
    {
        return vertices.size();
    }
    // 添加顶点
    void addVertex(int val)
    {
        int n = size();
        // 向顶点列表中添加新顶点的值
        vertices.push_back(val);
        // 向邻接矩阵中添加一行
        adjMat.emplace_back(vector<int>(n, 0));
        // 向邻接矩阵中添加一列
        for (auto &row : adjMat)
        {
            row.push_back(0);
        }
    }

    // 删除顶点
    void removeVertex(int index)
    {
        if (index >= size())
            throw out_of_range("顶点不存在");
        // 在顶点列表中删除移除索引index顶点
        vertices.erase(vertices.begin() + index);
        // 在邻接矩阵中删除索引index的行
        adjMat.erase(adjMat.begin() + index);
        // 在邻接矩阵中删除索引index的列
        for (auto &row : adjMat)
        {
            row.erase(row.begin() + index);
        }
    }

    // 添加表
    // 参数i，j为元素对应的索引
    void addEdge(int i, int j)
    {
        // 索引越界与相等处理
        if (i < 0 || j < 0 || i >= size() || j >= size() || i == j)
            throw out_of_range("顶点不存在");
        // 无向图，这两个元素是一样的
        adjMat[i][j] = 1;
        adjMat[j][i] = 1;
    }

    // 删除边
    // 参数i，j为元素对应的索引
    void removeEdge(int i, int j)
    {
        // 索引越界与相等处理
        if (i < 0 || j < 0 || i >= size() || j >= size() || i == j)
            throw out_of_range("顶点不存在");
        // 无向图，这两个元素是一样的
        adjMat[i][j] = 0;
        adjMat[j][i] = 0;
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
    // 打印矩阵
    template <typename T>
    void printVectorMatrix(vector<vector<T>> vec)
    {
        for (auto x : vec)
        {
            for (auto y : x)
                cout << "'" << to_string(y) << "'"
                     << " ";
            cout << "\n";
        }
    }

    /* 打印邻接矩阵 */
    void print()
    {
        cout << " 顶点列表 = ";
        printVector(vertices);
        cout << " 邻接矩阵 =" << endl;
        printVectorMatrix(adjMat);
    }
};

int main()
{
    /* 初始化无向图 */
    // 请注意，edges 元素代表顶点索引，即对应 vertices 元素索引
    vector<int> vertices = {1, 3, 2, 5, 4};
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {1, 2}, {2, 3}, {2, 4}, {3, 4}};
    GraphAdjMat graph(vertices, edges);
    cout << "\n初始化后，图为" << endl;
    graph.print();

    /* 添加边 */
    // 顶点 1, 2 的索引分别为 0, 2
    graph.addEdge(0, 2);
    cout << "\n添加边 1-2 后，图为" << endl;
    graph.print();

    /* 删除边 */
    // 顶点 1, 3 的索引分别为 0, 1
    graph.removeEdge(0, 1);
    cout << "\n删除边 1-3 后，图为" << endl;
    graph.print();

    /* 添加顶点 */
    graph.addVertex(6);
    cout << "\n添加顶点 6 后，图为" << endl;
    graph.print();

    /* 删除顶点 */
    // 顶点 3 的索引为 1
    graph.removeVertex(1);
    cout << "\n删除顶点 3 后，图为" << endl;
    graph.print();

    return 0;
}