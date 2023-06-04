#include "graph.hpp"
#include <iostream>

Graph::Graph() {

    this->numVertices = 0;
    this->numEdges = 0;
    this->vertices = set<int>();
    this->edges = map<pair<int, int>, int>();

}

Graph::~Graph() {



}

void Graph::addEdge(int v1, int v2, int weight) {

    if (v1 == v2) {
        // TODO: handle error 
        return;
    }

    vertices.insert(v1);
    vertices.insert(v2);
    edges[make_pair(v1, v2)] = weight;
    edges[make_pair(v2, v1)] = weight;  // graph is undirected
    numVertices = vertices.size();
    numEdges = edges.size() / 2;

    return;

}

void Graph::modifyEdge(int v1, int v2, int weight) {

    if (v1 == v2) {
        // TODO: handle error 
        return;
    }

    vertices.insert(v1);
    vertices.insert(v2);
    edges[make_pair(v1, v2)] = weight;
    edges[make_pair(v2, v1)] = weight;
    numVertices = vertices.size();
    numEdges = edges.size() / 2;

    return;

}

void Graph::removeEdge(int v1, int v2) {

    auto edge = edges.find(make_pair(v1, v2));
    if (edge != edges.end()) {
        edges.erase(edge);
        edge = edges.find(make_pair(v2, v1));
        edges.erase(edge);
    }
    else {
        // TODO: handle error

    }

    return;
}

void Graph::showAdjacencyMatrix() {
    
        cout << "Adjacency Matrix:" << endl;

        cout << "   " << MAGENTA;
        for (auto vertex : vertices) {
            if (vertex < 10) {
                cout << "  " << vertex << " ";
            }
            else { 
                cout << " " << vertex << " ";    
            }        
        }
        cout << RESET << endl;

        for (auto vertex : vertices) {
            if (vertex < 10) {
                cout << MAGENTA << vertex << RESET << "  ";
            }
            else {
                cout << MAGENTA << vertex << RESET << " ";
            }
            for (auto vertex2 : vertices) {
                if (vertex == vertex2) {
                    cout << "  0 ";
                    continue;
                }
                auto edge = edges.find(make_pair(vertex, vertex2));
                if (edge != edges.end()) {
                    if (edge->second < 10) {
                        cout << "  " << edge->second << " ";
                    }                    
                    else {
                        cout << " " << edge->second << " ";
                    }
                }
                else {
                    cout << " -1 ";
                }
            }
            cout << endl;
        }
    
        return;
}
    


