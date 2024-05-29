#include "MatrixGraph.h"

// создаем матрицу смежности
MatrixGraph::MatrixGraph(int vertexCount)
{
    assert(vertexCount > 0);
    this->vertexCount = vertexCount;
    adjMatrix.resize(vertexCount);
    for (int i = 0; i < vertexCount; ++i)
    {
        adjMatrix[i].resize(vertexCount);
    }
}

// конструктор копирования
MatrixGraph::MatrixGraph(const IGraph &graph)
{
    this->vertexCount = graph.VerticesCount();
    adjMatrix.resize(vertexCount);
    for (int i = 0; i < vertexCount; ++i)
    {
        adjMatrix[i].resize(vertexCount);
    }
    // устанавливаем для каждой вершин 1, если есть ребро
    for (int i = 0; i < vertexCount; ++i)
    {
        std::vector<int> nextVertices = graph.GetNextVertices(i);
        for (int j = 0; j < nextVertices.size(); ++j)
        {
            adjMatrix[i][nextVertices[j]] = true;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to)
{
    assert(from >= 0 && from < vertexCount);
    assert(to >= 0 && to < vertexCount);
    adjMatrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const
{
    return vertexCount;
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const
{
    assert(vertex >= 0 && vertex < vertexCount);
    std::vector<int> nextVertices;
    for (int i = 0; i < vertexCount; ++i)
    {
        if (adjMatrix[vertex][i])
        {
            nextVertices.push_back(i);
        }
    }
    return nextVertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const
{
    assert(vertex >= 0 && vertex < vertexCount);
    std::vector<int> prevVertices;
    for (int i = 0; i < vertexCount; ++i)
    {
        if (adjMatrix[i][vertex])
        {
            prevVertices.push_back(i);
        }
    }
    return prevVertices;
}
