#include "SetGraph.h"

SetGraph::SetGraph(int vertexCount)
{
    assert(vertexCount > 0);
    adjSet.resize(vertexCount);
}

SetGraph::SetGraph(const IGraph &graph)
{
    adjSet.resize(graph.VerticesCount());
    for (int i = 0; i < graph.VerticesCount(); ++i)
    {
        for (auto child : graph.GetNextVertices(i))
        {
            adjSet[i].insert(child);
        }
    }
}

void SetGraph::AddEdge(int from, int to)
{
    assert(from >= 0 && from < VerticesCount());
    assert(to >= 0 && to < VerticesCount());
    adjSet[from].insert(to);
}

int SetGraph::VerticesCount() const
{
    return adjSet.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const
{
    assert(vertex >= 0 && vertex < adjSet.size());
    return std::vector<int>(adjSet[vertex].begin(), adjSet[vertex].end());
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const
{
    assert(vertex >= 0 && vertex < adjSet.size());

    std::vector<int> prevVertices;
    for (int i = 0; i < adjSet.size(); ++i)
    {
        if (adjSet[i].find(vertex) != adjSet[i].end())
        {
            prevVertices.push_back(i);
        }
    }
    return prevVertices;
}
