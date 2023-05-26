from queue import Queue
from queue import LifoQueue

n = int(input("Enter the number of vertices: "))
m = int(input("Enter the number of edges: "))

a = [[0] * n for _ in range(n)]  # Initialize the adjacency matrix with zeros

print("\nEnter the vertices between which edges are present:")
for _ in range(m):
    v1 = int(input("Vertex: "))
    v2 = int(input("Vertex: "))
    print(f"Vertex {v1} <---------> Vertex {v2}")
    a[v1][v2] = 1
    a[v2][v1] = 1

root = int(input("\nEnter the root vertex: "))

# BFS Traversal
q = Queue()
visited = [False] * n  # Initialize all vertices as unvisited
q.put(root)
print("\nBFS Traversal:")
while not q.empty():
    x = q.get()
    if visited[x]:
        continue
    print(x, end=" ")
    visited[x] = True
    for i in range(n):
        if a[x][i] == 1 and not visited[i]:
            q.put(i)

# Reset visited array for DFS traversal
visited = [False] * n

# DFS Traversal
s = LifoQueue()
s.put(root)
print("\n\nDFS Traversal:")
while not s.empty():
    x = s.get()
    if visited[x]:
        continue
    print(x, end=" ")
    visited[x] = True
    for i in range(n):
        if a[x][i] == 1 and not visited[i]:
            s.put(i)
