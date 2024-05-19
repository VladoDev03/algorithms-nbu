#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <limits>
#include <type_traits>

using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::pair;
using std::unordered_map;
using std::queue;

template <typename T, typename W = int>
class Graph
{
public:
    Graph(bool directed = false) : directed(directed) {}

    void addEdge(const T& src, const T& dest, const W& weight = W());
    void BFS(const T& start);
    void DFS(const T& start);

private:
    unordered_map<T, list<pair<T, W>>> adjList;
    bool directed;

    void DFSUtil(const T& vertex, unordered_map<T, bool>& visited);
};

int main()
{
    Graph<int> g(false);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "BFS starting from vertex 2:\n";
    g.BFS(2);

    cout << "DFS starting from vertex 2:\n";
    g.DFS(2);

    return 0;
}

template <typename T, typename W>
void Graph<T, W>::addEdge(const T& src, const T& dest, const W& weight)
{
    adjList[src].push_back({dest, weight});

    if (!directed)
    {
        adjList[dest].push_back({src, weight});
    }
}

template <typename T, typename W>
void Graph<T, W>::BFS(const T& start)
{
    unordered_map<T, bool> visited;
    queue<T> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        T vertex = q.front();
        q.pop();
        cout << vertex << " ";

        for (const auto& neighbor : adjList[vertex])
        {
            if (!visited[neighbor.first])
            {
                visited[neighbor.first] = true;
                q.push(neighbor.first);
            }
        }
    }
    cout << endl;
}

template <typename T, typename W>
void Graph<T, W>::DFS(const T& start)
{
    unordered_map<T, bool> visited;
    DFSUtil(start, visited);
    cout << endl;
}

template <typename T, typename W>
void Graph<T, W>::DFSUtil(const T& vertex, unordered_map<T, bool>& visited)
{
    visited[vertex] = true;
    cout << vertex << " ";

    for (const auto& neighbor : adjList[vertex])
    {
        if (!visited[neighbor.first])
        {
            DFSUtil(neighbor.first, visited);
        }
    }
}
