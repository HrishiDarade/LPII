#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> graph;

public:
    Graph(int vertices) {
        V = vertices;
        graph = vector<vector<int>>(V, vector<int>(V, 0));
    }

    void add_edge(int u, int v, int weight) {
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    void print_mst(const vector<int>& parent) {
        cout << "Edge\tWeight" << endl;
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
        }
    }

    int min_key(const vector<int>& key, const vector<bool>& mst_set) {
        int min_value = INT_MAX;
        int min_index = -1;
        for (int v = 0; v < V; v++) {
            if (!mst_set[v] && key[v] < min_value) {
                min_value = key[v];
                min_index = v;
            }
        }
        return min_index;
    }

    void prim_mst() {
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> mst_set(V, false);

        key[0] = 0;

        for (int count = 0; count < V - 1; count++) {
            int u = min_key(key, mst_set);

            mst_set[u] = true;

            for (int v = 0; v < V; v++) {
                if (graph[u][v] > 0 && !mst_set[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        print_mst(parent);
    }
};

int main() {
    Graph g(5);  // Create a graph with 5 vertices
    g.add_edge(0, 1, 2);
    g.add_edge(0, 3, 6);
    g.add_edge(1, 2, 3);
    g.add_edge(1, 3, 8);
    g.add_edge(1, 4, 5);
    g.add_edge(2, 4, 7);
    g.add_edge(3, 4, 9);

    // Run Prim's algorithm
    g.prim_mst();

    return 0;
}
