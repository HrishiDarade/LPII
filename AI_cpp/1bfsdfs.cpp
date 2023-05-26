#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    int a[n][n] = {0};  // Initialize the adjacency matrix with zeros

    cout << "\nEnter the vertices between which edges are present:\n";
    int v1, v2;
    for (int i = 0; i < m; i++) {
        cout << "Vertex: ";
        cin >> v1;
        cout << "Vertex: ";
        cin >> v2;
        cout << "Vertex " << v1 << " <---------> Vertex " << v2 << endl;
        a[v1][v2] = 1;
        a[v2][v1] = 1;
    }

    int root;
    cout << "\nEnter the root vertex: ";
    cin >> root;

    // BFS Traversal
    queue<int> q;
    bool visited[n] = {false};  // Initialize all vertices as unvisited
    q.push(root);
    cout << "\nBFS Traversal:\n";
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (visited[x]) {
            continue;
        }
        cout << x << " ";
        visited[x] = true;
        for (int i = 0; i < n; i++) {
            if (a[x][i] == 1 && !visited[i]) {
                q.push(i);
            }
        }
    }

    // Reset visited array for DFS traversal
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    // DFS Traversal
    stack<int> s;
    s.push(root);
    cout << "\n\nDFS Traversal:\n";
    while (!s.empty()) {
        int x = s.top();
        s.pop();
        if (visited[x]) {
            continue;
        }
        cout << x << " ";
        visited[x] = true;
        for (int i = 0; i < n; i++) {
            if (a[x][i] == 1 && !visited[i]) {
                s.push(i);
            }
        }
    }

    return 0;
}
