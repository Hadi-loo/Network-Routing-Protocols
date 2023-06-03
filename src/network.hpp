#ifndef __NETWORK_HPP__
#define __NETWORK_HPP__

#include "graph.hpp"

class Network {
private:
    Graph graph;

public:
    Network();
    ~Network();
    void addEdge(int v1, int v2, int weight);
    void modifyEdge(int v1, int v2, int weight);
    void removeEdge(int v1, int v2);
    void showAdjacencyMatrix();
    void lsrp(int source);
    void dvrp(int source);
};

#endif // __NETWORK_HPP__
