#include "network.hpp"

Network::Network() {
    this->graph = Graph();
}

Network::~Network() {

}

void Network::addEdge(int v1, int v2, int weight) {
    graph.addEdge(v1, v2, weight);
    return;
}

void Network::modifyEdge(int v1, int v2, int weight) {
    graph.modifyEdge(v1, v2, weight);
    return;
}

void Network::removeEdge(int v1, int v2) {
    graph.removeEdge(v1, v2);
    return;
}

void Network::showAdjacencyMatrix() {
    graph.showAdjacencyMatrix();
    return;
}

void Network::lsrp(int source) {
    // TODO: Implement this function
    return;
}

void Network::dvrp(int source) {
    // TODO: Implement this function
    return;
}


