#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

struct Node {
    Node* parent;
    int mat[3][3];
    int x, y;
    int hscore;
    int gscore;
};

void printMatrix(int mat[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
}

Node* newNode(int mat[3][3], int x, int y, int newX, int newY, int gscore, Node* parent) {
    Node* node = new Node;
    node->parent = parent;
    memcpy(node->mat, mat, sizeof(node->mat));
    swap(node->mat[x][y], node->mat[newX][newY]);
    node->hscore = INT_MAX;
    node->gscore = gscore;
    node->x = newX;
    node->y = newY;
    return node;
}

int row[] = {1, 0, -1, 0};
int col[] = {0, -1, 0, 1};

int calculateCost(int initial[3][3], int final[3][3]) {
    int count = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (initial[i][j] && initial[i][j] != final[i][j])
                count++;
    return count;
}

bool isSafe(int x, int y) {
    return (x >= 0 && x < 3 && y >= 0 && y < 3);
}

void printPath(Node* root) {
    if (root == nullptr)
        return;
    printPath(root->parent);
    printMatrix(root->mat);
    cout << "hscore: " << root->hscore << "\ngscore: " << root->gscore << "\nfscore: " << root->hscore + root->gscore << "\n\n";
}

struct comp {
    bool operator()(const Node* lhs, const Node* rhs) const {
        return (lhs->hscore + lhs->gscore) > (rhs->hscore + rhs->gscore);
    }
};

void solve(int initial[3][3], int x, int y, int final[3][3]) {
    priority_queue<Node*, vector<Node*>, comp> pq;
    Node* root = newNode(initial, x, y, x, y, 0, nullptr);
    root->hscore = calculateCost(initial, final);
    pq.push(root);

    while (!pq.empty()) {
        Node* min = pq.top();
        pq.pop();

        if (min->hscore == 0) {
            printPath(min);
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (isSafe(min->x + row[i], min->y + col[i])) {
                Node* child = newNode(min->mat, min->x, min->y, min->x + row[i], min->y + col[i], min->gscore + 1, min);
                child->hscore = calculateCost(child->mat, final);
                pq.push(child);
            }
        }
    }
}

int main() {
    int initial[3][3];
    int x, y;

    cout << "\n\nEnter Initial Block Structure\n\nEnter 0 for blank space:\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Row " << i + 1 << " Column " << j + 1 << " Element = ";
            cin >> initial[i][j];
            if (initial[i][j] == 0) {
                x = i;
                y = j;
            }
        }
    }

    int final[3][3];
    cout << "\n\nEnter Final Block Structure\n\nEnter 0 for blank space:\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Row " << i + 1 << " Column " << j + 1 << " Element = ";
            cin >> final[i][j];
        }
    }

    cout << "\nInitial Structure:\n\n";
    printMatrix(initial);
    cout << "\nFinal Structure:\n\n";
    printMatrix(final);

    cout << "\n\nThis is the solution using A* Algorithm:\n\n";
    solve(initial, x, y, final);

    return 0;
}
