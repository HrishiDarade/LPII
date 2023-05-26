#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> graph;

public:
    Graph(int vertices) {
        V = vertices;
    }

    void add_edge(int u, int v, int weight) {
        graph.push_back({u, v, weight});
    }

    int find_parent(vector<int>& parent, int i) {
        if (parent[i] == i)
            return i;
        return find_parent(parent, parent[i]);
    }

    void union_sets(vector<int>& parent, vector<int>& rank, int x, int y) {
        int root_x = find_parent(parent, x);
        int root_y = find_parent(parent, y);

        if (rank[root_x] < rank[root_y])
            parent[root_x] = root_y;
        else if (rank[root_x] > rank[root_y])
            parent[root_y] = root_x;
        else {
            parent[root_y] = root_x;
            rank[root_x]++;
        }
    }

    void kruskal_mst() {
        vector<vector<int>> result;
        int i = 0;
        int e = 0;
        sort(graph.begin(), graph.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        vector<int> parent(V);
        vector<int> rank(V);

        for (int node = 0; node < V; node++) {
            parent[node] = node;
            rank[node] = 0;
        }

        while (e < V - 1) {
            int u = graph[i][0];
            int v = graph[i][1];
            int weight = graph[i][2];
            i++;

            int x = find_parent(parent, u);
            int y = find_parent(parent, v);

            if (x != y) {
                e++;
                result.push_back({u, v, weight});
                union_sets(parent, rank, x, y);
            }
        }

        cout << "Edge\tWeight" << endl;
        for (const vector<int>& edge : result) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            cout << u << " - " << v << "\t" << weight << endl;
        }
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

    // Run Kruskal's algorithm
    g.kruskal_mst();

    return 0;
}
