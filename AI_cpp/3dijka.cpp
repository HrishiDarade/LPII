#include <iostream>
#include <climits>
using namespace std;

class Graph {
private:
    int V;
    int** graph;

public:
    Graph(int vertices) {
        V = vertices;
        graph = new int*[V];
        for (int i = 0; i < V; i++) {
            graph[i] = new int[V];
            for (int j = 0; j < V; j++) {
                graph[i][j] = 0;
            }
        }
    }

    void add_edge(int u, int v, int weight) {
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    int min_distance(int dist[], bool mst_set[]) {
        int min_dist = INT_MAX;
        int min_index = -1;
        for (int v = 0; v < V; v++) {
            if (!mst_set[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    void dijkstra_mst(int src) {
        int* dist = new int[V];
        bool* mst_set = new bool[V];

        for (int v = 0; v < V; v++) {
            dist[v] = INT_MAX;
            mst_set[v] = false;
        }

        dist[src] = 0;

        for (int count = 0; count < V - 1; count++) {
            int u = min_distance(dist, mst_set);
            mst_set[u] = true;

            for (int v = 0; v < V; v++) {
                if (graph[u][v] && !mst_set[v] && dist[u] != INT_MAX && dist[v] > dist[u] + graph[u][v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        cout << "Shortest distances from source vertex " << src << " to all other vertices:" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": " << dist[i] << endl;
        }

        delete[] dist;
        delete[] mst_set;
    }
};

int main() {
    Graph g(9);  // Create a graph with 9 vertices
    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 8, 2);
    g.add_edge(2, 5, 4);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);

    // Run Dijkstra's algorithm
    int source = 0;
    g.dijkstra_mst(source);

    return 0;
}
