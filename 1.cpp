#include "ArcGraph.cpp"

void BFS(const IGraph &graph, int vertex, void (*visit)(int))
{
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::queue<int> bfsQ;
    bfsQ.push(vertex);
    visited[vertex] = true;
    while (bfsQ.size() > 0)
    {
        int current = bfsQ.front();
        bfsQ.pop();
        visit(current);
        std::vector<int> adjList = graph.GetNextVertices(current);
        for (int i = 0; i < adjList.size(); ++i)
        {
            if (!visited[adjList[i]])
            {
                bfsQ.push(adjList[i]);
                visited[adjList[i]] = true;
            }
        }
    }
}

int main()
{
    ArcGraph graph(8);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 4);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 5);
    graph.AddEdge(3, 0);
    graph.AddEdge(3, 4);
    graph.AddEdge(3, 2);
    graph.AddEdge(4, 6);
    graph.AddEdge(5, 3);
    graph.AddEdge(6, 3);
    graph.AddEdge(6, 5);
    graph.AddEdge(6, 7);
    graph.AddEdge(7, 5);
    BFS(graph, 0, [](int vertex)
        { std::cout << vertex << " "; });

    return 0;
}
