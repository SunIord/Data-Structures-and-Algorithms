// cd algoritos/c++
// g++ dijkstra.cpp -o dijkstra
// ./dijkstra

#include <../algoritmos/c++/graph.hpp>

void Graph::dijkstra(int start, int dist[]) {
    const int INF = 1e9; // defines infinity
    int prev[n];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
        setMark(i, 0);
    }
    dist[start] = 0;
    prev[start] = start;
    for (int i = 0; i < n; i++) {
        int value = -1;
        int minDist = INF;
        for (int j = 0; j < n; j++) {
            if (getMark(j) == 0 && dist[j] < minDist) {
                minDist = dist[j];
                value = j;
            }
        }
        if (value == -1) { return; }
        setMark(value, 1);
        int weight = first(value);
        while (weight < n) {
            if (getMark(weight) == 0) {
                int newDist = dist[value] + getWeight(value, weight);
                if (newDist < dist[weight]) {
                    dist[weight] = newDist;
                    prev[weight] = value;
                }
            }
            weight = next(value, weight);
        }
    }
}

int main() {
    int n = 5; // number of vertices
    Graph g(n);
    
    // Adding edges with weights
    g.setEdge(0, 1, 10);
    g.setEdge(0, 2, 3);
    g.setEdge(1, 2, 1);
    g.setEdge(1, 3, 2);
    g.setEdge(2, 1, 4);
    g.setEdge(2, 3, 8);
    g.setEdge(2, 4, 2);
    g.setEdge(3, 4, 7);
    g.setEdge(4, 3, 9);
    
    int dist[n];
    g.dijkstra(0, dist);
    
    // Print shortest distances from source
    std::cout << "Vertex Distance from Source (0):" << std::endl;
    for (int i = 0; i < n; i++) {
        if (dist[i] == 1e9) {
            std::cout << i << "\t\t" << "INF" << std::endl;
        } else {
            std::cout << i << "\t\t" << dist[i] << std::endl;
        }
    }
    
    return 0;
}