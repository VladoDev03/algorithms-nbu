#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    int src, dest;
};

class Graph
{
public:
    int n;
    vector<vector<int>> adjList;

    Graph(const vector<Edge> &edges, int n)
    {
        this->n = n;
        adjList.resize(n);

        for (auto &edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
        }
    }
};

int DFS(const Graph &graph, int v, vector<bool> &discovered, vector<int> &arrival, bool &isSC, int &time)
{
    if (!isSC)
    {
        return 0;
    }

    arrival[v] = ++time;
    discovered[v] = true;
    int arr = arrival[v];

    for (int u : graph.adjList[v])
    {
        if (!discovered[u])
        {
            arr = min(arr, DFS(graph, u, discovered, arrival, isSC, time));
        }
        else
        {
            arr = min(arr, arrival[u]);
        }
    }

    if (v != 0 && arr == arrival[v])
    {
        isSC = false;
    }

    return arr;
}

bool isStronglyConnected(Graph &graph)
{
    vector<bool> discovered(graph.n);
    vector<int> arrival(graph.n);

    bool isSC = true;
    int time = -1;

    DFS(graph, 0, discovered, arrival, isSC, time);

    for (int i = 0; i < graph.n; i++)
    {
        if (!discovered[i])
        {
            isSC = false;
        }
    }

    return isSC;
}

int main()
{
    vector<Edge> edges1 =
    {
        { 0, 1 }, { 1, 2 }, { 1, 7 },
        { 2, 3 }, { 3, 5 }, { 4, 6 },
        { 4, 8 }, { 7, 8 }, { 1, 3 }
    };

    vector<Edge> edges =
    {
        { 0, 4 }, { 4, 3 }, { 3, 2 },
        { 3, 1 }, { 1, 2 }, { 1, 0 },
        { 2, 4 }, { 2, 1 }
    };

    int n = 5;

    Graph graph(edges, n);

    if (isStronglyConnected(graph))
    {
        cout << "Graph is strongly connected!" << endl;
    }
    else
    {
        cout << "Graph is not strongly connected!" << endl;
    }

    return 0;
}
