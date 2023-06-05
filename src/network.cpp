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

int Network::findMinAdjacent(int dist[] , bool visited[]){
    int min_index = -1;
    int min_vertice = INT_MAX;

    for(int i = 0 ; i < (int)graph.vertices.size() + 1 ; i++){
        if(visited[i] == false && dist[i] < min_vertice){
            min_vertice = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

void Network::updateNeigborsRoute(int newVertice, int dist[] , bool visited[], vector<int> &parent){

    for (int i = 0 ; i < (int)graph.vertices.size() + 1; i++){
        if(visited[i] == false && dist[newVertice] != INT_MAX
            && graph.edges[make_pair(newVertice, i)] != 0
            && dist[newVertice] + graph.edges[make_pair(newVertice, i)] < dist[i]){
                dist[i] = dist[newVertice] + graph.edges[make_pair(newVertice, i)];
                parent[i] = newVertice;
        }
    }

}

void Network::printLsrpIterations(int iterNum, int dist[]){
    cout << "Iter " << iterNum << ":" << endl;
    cout << "Dest ";
    for(int i = 1 ; i <= (int)graph.vertices.size() ; i++)
        cout << i << " | ";
    cout << "\nCost ";
    for(int i = 1; i <= (int)graph.vertices.size() ; i++){
        auto it = graph.vertices.find(i);
        if (dist[*it] == INT_MAX)
            cout << "-1" << " | ";
        else
            cout << dist[*it] << " | ";
    }
    cout << "\n------------------------\n";
}

// void Network:printLsrpOverview(){

// }

void Network::lsrp(int source) {
    if (source == -1) {
        for (auto vertex : graph.vertices) {
            cout << vertex << endl;
            lsrp(vertex);
        // cout << "------------node: " << vertex << "-------------\n";
        }
    }
    else{
        int dist[graph.vertices.size() + 1];                            // Hold the shortest path data
        bool visited[graph.vertices.size() + 1];                        // hold the covered area of the lsrp
        vector<int> parent(graph.vertices.size() + 1, -1);

        for (int i = 0; i < (int)graph.vertices.size() + 1 ; i++){      // initialize arrays
            dist[i] = INT_MAX; visited[i] = false;
        }
        dist[source] = 0;
        visited[source] = true;
        updateNeigborsRoute(source, dist, visited, parent);
        cout << MAGENTA << "Routing table for node " << source << RESET << endl;
        printLsrpIterations(0 , dist);

        for (int i = 0 ; i < (int)graph.vertices.size() + 1 ; i++){     // Run LSRP
            int u = findMinAdjacent(dist, visited);
            if(u == -1)
                break;
            visited[u] = true;
            // cout << "new v:" << u << endl;
            updateNeigborsRoute(u, dist, visited, parent);
            printLsrpIterations(i , dist);
        }
    }
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


