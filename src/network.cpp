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
    if (source == -1) {
        for (auto vertex : graph.vertices) {
            dvrp(vertex);
        }
    }
    else {
        vector<int> distance(graph.vertices.size() + 1, INT_MAX);
        vector<int> parent(graph.vertices.size() + 1, -1);
        distance[source] = 0;
        bool updated;
        do {
            updated = false;
            for (auto edge : graph.edges) {
                pair<int, int> vertices = edge.first;
                int v1 = vertices.first;
                int v2 = vertices.second;
                int weight = edge.second;
                if ((distance[v1] != INT_MAX) && (distance[v2] > distance[v1] + weight)) {
                    distance[v2] = distance[v1] + weight;
                    parent[v2] = v1;
                    updated = true;
                }
            }
        } while (updated);
                
        cout << MAGENTA << "Routing table for node " << source << RESET << endl;
        cout << CYAN << "Destination\tNext Hop\tDistance\tShortest Path" << RESET << endl;

        for (auto vertex : graph.vertices) {
            if (vertex == source) {
                continue;
            }

            cout << CYAN << vertex << RESET << "\t\t";
            
            vector<int> path;
            int current = vertex;
            while (parent[current] != -1) {
                path.push_back(current);
                current = parent[current];
            }
            path.push_back(current);

            cout << path[path.size() - 2] << "\t\t";
            cout << distance[vertex] << "\t\t";
            for (int i = path.size() - 1; i > 0; i--) {
                cout << path[i] << "->";
            }
            cout << path[0] << endl;
        }
    }
    return;
}


