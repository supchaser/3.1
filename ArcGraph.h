#include "IGraph.h"

class ArcGraph : public IGraph
{
public:
    ArcGraph(int vertexCount_);
    ArcGraph(const IGraph &graph);
    // IGraph
    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;
    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int vertexCount;
    std::vector<std::pair<int, int>> adjArc;
};
