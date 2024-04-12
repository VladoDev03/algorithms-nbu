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
            adjList[edge.dest].push_back(edge.src);
        }
    }
};

bool DFS(const Graph &graph, int v, vector<bool> discovered, vector<int> color)
{
    for (int u : graph.adjList[v])
    {
        if (!discovered[u])
        {
            discovered[u] = true;
            color[u] = !color[v];

            if (!DFS(graph, u, discovered, color))
            {
                return false;
            }
        }
        else if (color[v] == color[u])
        {
            return false;
        }
    }

    return true;
}

bool isBipartite(Graph &graph)
{
    vector<bool> discovered(graph.n);
    vector<int> color(graph.n);

    int src = 0;
    discovered[src] = true;
    color[src] = 0;

    return DFS(graph, src, discovered, color);
}

int main()
{
    vector<Edge> edges =
    {
        { 0, 1 }, { 1, 2 }, { 1, 7 },
        { 2, 3 }, { 3, 5 }, { 4, 6 },
        { 4, 8 }, { 7, 8 }, { 1, 3 }
    };

    int n = 9;

    Graph graph(edges, n);

    if (isBipartite(graph))
    {
        cout << "Graph is bipartite!" << endl;
    }
    else
    {
        cout << "Graph is not bipartite!" << endl;
    }

    return 0;
}
