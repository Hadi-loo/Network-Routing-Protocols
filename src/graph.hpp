#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include "consts.hpp"
#include <map> 
#include <set>

using namespace std;
class Graph {
private:
    int numVertices;
    int numEdges;
    set <int> vertices;
    map <pair<int, int>, int> edges;

public:
    Graph();
    ~Graph();
    void addEdge(int v1, int v2, int weight);
    void modifyEdge(int v1, int v2, int weight);
    void removeEdge(int v1, int v2);
    void showAdjacencyMatrix();
    
};

#endif // __GRAPH_HPP__
