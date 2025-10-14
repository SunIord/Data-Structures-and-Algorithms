#ifndef GRAPH_HPP
#define GRAPH_HPP

// cd algoritmos/c++
// g++ graph.cpp -o graph
// ./graph

// hpp file for Graph class

#include <iostream>
#include <queue>

class Graph {
private:
    int** matrix;
    int numEdges;
    int* mark;
    int n;

public: 
    Graph(int n) {
        this->n = n;
        mark = new int[n];
        matrix = new int*[n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new int[n];
        }
        numEdges = 0;
    }

    ~Graph() {
        delete[] mark;
        for (int i = 0; i < n; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    int first(int value) {
        for (int i = 0; i < n; i++) {
            if (matrix[value][i] != 0) {
                return i;
            }
        }
        return n;
    }

    int next(int value, int curr) {
        for (int i = curr + 1; i < n; i++) {
            if (matrix[value][i] != 0) {
                return i;
            }
        }
        return n;
    }

    void setEdge(int i, int j, int weight) {
        if (weight == 0) { return; }
        if (matrix[i][j] == 0) { numEdges++; }
        matrix[i][j] = weight;
    }

    void delEdge(int i, int j) {
        if (matrix[i][j] != 0) { numEdges--; }
        matrix[i][j] = 0;
    }

    // Funções auxiliares
    bool isEdge(int i, int j) { return matrix[i][j] != 0; }
    int getWeight(int i, int j) { return matrix[i][j]; }
    void setMark(int v, int val) { mark[v] = val; }
    int getMark(int v) { return mark[v];}
    void preVisit(int value) {}
    void postVisit(int value) {}  

    // Função de travessia
    void graphTraverse() {
        for (int value = 0; value < n; value++) { setMark(value, 0); } // 0 = unvisited    
        for (int value = 0; value < n; value++) {
            if (getMark(value) == 0) {
                //dfs(value); ou
                bfs(value);
            }
        }
    }  

    void dfs(int value) {
        preVisit(value);
        setMark(value, 1); // 1 = visited
        int weight = first(value);
        while (weight < n) {
            if (getMark(weight) == 0) {
                dfs(weight);
            }
            weight = next(value, weight);
        }
        postVisit(value);
    }

    void bfs(int start) {
        std::queue<int> Q;
        Q.push(start);
        setMark(start, 1); 
        while (!Q.empty()) {
            int value = Q.front();
            Q.pop();
            preVisit(value);
            int weight = first(value);
            while (weight < n) {
                if (getMark(weight) == 0) {
                    setMark(weight, 1);
                    Q.push(weight);
                }
                weight = next(value, weight);
            }
            postVisit(value);
        }
    }

    // shortest path algorithms
    void dijkstra(int start, int dist[]);
    void floydWarshall(int dist[]);
    void bellmanFord(int start, int dist[]);
};

#endif