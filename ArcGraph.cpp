#include "ArcGraph.h"

ArcGraph::ArcGraph(int vertexCount_)
{
    assert(vertexCount_ > 0);
    vertexCount = vertexCount_;
    adjArc.resize(vertexCount);
}

ArcGraph::ArcGraph(const IGraph &graph)
{
    vertexCount = graph.VerticesCount();
    adjArc.resize(vertexCount);
    for (int i = 0; i < vertexCount; ++i)
    {
        for (auto child : graph.GetNextVertices(i))
        {
            adjArc.push_back(std::make_pair(i, child));
        }
    }
}

void ArcGraph::AddEdge(int from, int to)
{
    assert(from >= 0 && from < VerticesCount());
    assert(to >= 0 && to < VerticesCount());
    adjArc.push_back(std::make_pair(from, to));
}

int ArcGraph::VerticesCount() const
{
    return adjArc.size();
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const
{
    assert(vertex >= 0 && vertex < VerticesCount());
    std::vector<int> nextVertices;
    for (auto i : adjArc)
    {
        if (i.first == vertex)
        {
            nextVertices.push_back(i.second);
        }
    }

    return nextVertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const
{
    assert(vertex >= 0 && vertex < VerticesCount());
    std::vector<int> prevVertices;
    for (auto i : adjArc)
    {
        if (i.second == vertex)
        {
            prevVertices.push_back(i.first);
        }
    }

    return prevVertices;
}
