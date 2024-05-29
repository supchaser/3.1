#include "ListGraph.h"

ListGraph::ListGraph(int vertexCount)
{
    assert(vertexCount > 0);
    adjList.resize(vertexCount);
    prevAdjList.resize(vertexCount);
}

ListGraph::ListGraph(const IGraph &graph)
{
    adjList.resize(graph.VerticesCount());
    prevAdjList.resize(graph.VerticesCount());
    for (int i = 0; i < VerticesCount(); ++i)
    {
        adjList[i] = graph.GetNextVertices(i);
        prevAdjList[i] = graph.GetPrevVertices(i);
    }
}

void ListGraph::AddEdge(int from, int to)
{
    assert(from >= 0 && from < adjList.size());
    assert(to >= 0 && to < adjList.size());
    adjList[from].push_back(to);
    prevAdjList[to].push_back(from);
}

int ListGraph::VerticesCount() const
{
    return adjList.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const
{
    assert(vertex >= 0 && vertex < adjList.size());
    return adjList[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const
{
    assert(vertex >= 0 && vertex < adjList.size());
    return prevAdjList[vertex];
}
