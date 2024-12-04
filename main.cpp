#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

struct Edge {
    int src, dest, weight;
};

void bellmanFord(int V, int E, const std::vector<Edge>& edges, int src) {
    std::vector<int> dist(V, INF);
    std::vector<int> parent(V, -1);
    dist[src] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.src] != INF && dist[edge.src] + edge.weight < dist[edge.dest]) {
                dist[edge.dest] = dist[edge.src] + edge.weight;
                parent[edge.dest] = edge.src;
            }
        }
    }

    // Проверка на наличие отрицательных циклов
    for (const auto& edge : edges) {
        if (dist[edge.src] != INF && dist[edge.src] + edge.weight < dist[edge.dest]) {
            std::cout << "Graph contains negative weight cycle" << std::endl;
            return;
        }
    }

    // Вывод кратчайших путей
    std::cout << "Vertex Distance from Source" << std::endl;
    for (int i = 0; i < V; ++i) {
        std::cout << i << "\t\t" << dist[i] << "\t\t";
        std::vector<int> path;
        for (int at = i; at != -1; at = parent[at]) {
            path.push_back(at);
        }
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int V = 5; // Количество вершин
    int E = 8; // Количество ребер
    std::vector<Edge> edges = {
            {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
            {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    bellmanFord(V, E, edges, 0);

    return 0;
}
