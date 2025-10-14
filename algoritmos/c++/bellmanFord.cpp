// cd algoritmos/c++
// g++ bellmanFord.cpp -o bellmanFord
// ./bellmanFord

#include "graph.hpp"

void Graph::bellmanFord(int start, int dist[]) {
    const int INF = 1e9; // Defines infinity 
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    for (int k = 0; k < n - 1; k++) {
        for (int i = 0; i < n; i++) {
            int j = first(i);
            while (j < n) {
                if (dist[j] > dist[i] + getWeight(i, j)) {
                    dist[j] = dist[i] + getWeight(i, j);
                }
                j = next(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int j = first(i);
        while (j < n) {
            if (dist[j] > dist[i] + getWeight(i,j)) {
                // Negative weight cycle detected
                throw std::runtime_error("Graph contains a negative weight cycle");
            }
            j = next(i, j);
        }
    }
}

int main() {
    Graph g(5);
    g.setEdge(0, 1, -1);
    g.setEdge(0, 2, 4);
    g.setEdge(1, 2, 3);
    g.setEdge(1, 3, 2);
    g.setEdge(1, 4, 2);
    g.setEdge(3, 2, 5);
    g.setEdge(3, 1, 1);
    g.setEdge(4, 3, -3);

    int dist[5];
    try {
        g.bellmanFord(0, dist);
        std::cout << "Vertex Distance from Source (0):" << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << "Vertex " << i << ": " << dist[i] << std::endl;
        }
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}