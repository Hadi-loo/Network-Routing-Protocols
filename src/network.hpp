#ifndef __NETWORK_HPP__
#define __NETWORK_HPP__

#include "graph.hpp"
#include <vector>
#include <climits>
#include <iostream>

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
    int findMinAdjacent(int dist[] , bool visited[]);
    void updateNeigborsRoute(int newVertice, int dist[] , bool visited[], vector<int> &parent);
    void printLsrpIterations(int iterNum, int dist[]);
    void printLsrpOverview(int dist[] , int source, vector<int> &parent);
};

#endif // __NETWORK_HPP__
