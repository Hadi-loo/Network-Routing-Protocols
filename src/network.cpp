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
            && graph.edges.count(make_pair(newVertice, i)) > 0
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

void Network::printLsrpOverview(int dist[] , int source, vector<int> &parent){
    cout << CYAN << "Path [s] -> [d] | Min-Cost | Shortest-Path" << RESET << endl;
    for(int i = 1 ; i < graph.vertices.size() + 1 ; i++){
        if (i == source)
            continue;
        cout << source << "->" << i << " | ";
        auto it = graph.vertices.find(i);
        cout << dist[*it] << " | ";
        
        vector<int> path;
            int current = i;
            while (parent[current] != -1) {
                path.push_back(current);
                current = parent[current];
            }
        path.push_back(current);
        for (int i = path.size() - 1; i > 0; i--) {
                cout << path[i] << "->";
        }
        cout << path[0] << endl;
    }
}

void Network::lsrp(int source, double& total_time) {
    if (source == -1) {
        for (auto vertex : graph.vertices) {
            lsrp(vertex, total_time);
        }
    }
    else{
        double time = 0;
        auto start = chrono::high_resolution_clock::now();

        int dist[graph.vertices.size() + 1];                            // Hold the shortest path data
        bool visited[graph.vertices.size() + 1];                        // hold the covered area of the lsrp
        vector<int> parent(graph.vertices.size() + 1, -1);

        for (int i = 0; i < (int)graph.vertices.size() + 1 ; i++){      // initialize arrays
            dist[i] = INT_MAX; visited[i] = false;
        }

        dist[source] = 0;
        visited[source] = true;
        updateNeigborsRoute(source, dist, visited, parent);

        auto end = chrono::high_resolution_clock::now();
        time += chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        cout << MAGENTA << "Routing table for node " << source << RESET << endl;
        printLsrpIterations(0 , dist);

        start = chrono::high_resolution_clock::now();

        for (int i = 0 ; i < (int)graph.vertices.size() + 1 ; i++){     // Run LSRP
            int u = findMinAdjacent(dist, visited);
            if(u == -1)
                break;
            visited[u] = true;
            updateNeigborsRoute(u, dist, visited, parent);

            end = chrono::high_resolution_clock::now();
            time += chrono::duration_cast<chrono::nanoseconds>(end - start).count();

            printLsrpIterations(i , dist);

            start = chrono::high_resolution_clock::now();
        }
        printLsrpOverview(dist, source, parent);
        cout << "Time: " << time << " nanoseconds" << endl;
        total_time += time;
    }
    return;
}

void Network::dvrp(int source, double &total_time) {
    if (source == -1) {
        for (auto vertex : graph.vertices) {
            dvrp(vertex, total_time);
        }
    }
    else {

        double time = 0;
        auto start = chrono::high_resolution_clock::now();

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

        auto end = chrono::high_resolution_clock::now();
        time += chrono::duration_cast<chrono::nanoseconds>(end - start).count();
                
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
        cout << "Time: " << time << " ns" << endl;
        total_time += time;
    }
    return;
}


