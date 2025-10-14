// cd algoritmos/c++
// g++ floydWarshall.cpp -o floydWarshall
// ./floydWarshall

#include "graph.hpp"

void Graph::floydWarshall(int dist[]) {
    const int INF = 1e9; // defines infinity
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) { dist[i * n + j] = 0; } 
            else if (getWeight(i, j) != 0) { dist[i * n + j] = getWeight(i, j);} 
            else { dist[i * n + j] = INF;}
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i * n + k] != INF && dist[k * n + j] != INF && dist[i * n + j] > dist[i * n + k] + dist[k * n + j]) {
                    dist[i * n + j] = dist[i * n + k] + dist[k * n + j];
                }
            }
        }
    }
}

// Example usage
int main() {
    int n = 4; // number of vertices
    Graph g(n);
    
    // Adding edges with weights
    g.setEdge(0, 1, 5);
    g.setEdge(0, 3, 10);
    g.setEdge(1, 2, 3);
    g.setEdge(2, 3, 1);
    
    int dist[n * n];
    g.floydWarshall(dist);
    
    // Print shortest path matrix
    std::cout << "Shortest path matrix:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i * n + j] == 1e9) {
                std::cout << "INF ";
            } else {
                std::cout << dist[i * n + j] << " ";
            }
        }
        std::cout << std::endl;
    }
    
    return 0;
}