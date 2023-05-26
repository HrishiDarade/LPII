import copy

class Node:
    def __init__(self, mat, x, y, newX, newY, gscore, parent):
        self.parent = parent
        self.mat = copy.deepcopy(mat)
        self.mat[x][y], self.mat[newX][newY] = self.mat[newX][newY], self.mat[x][y]
        self.hscore = float('inf')
        self.gscore = gscore
        self.x = newX
        self.y = newY

def printMatrix(mat):
    for i in range(3):
        for j in range(3):
            print(mat[i][j], end=" ")
        print()

def calculateCost(initial, final):
    count = 0
    for i in range(3):
        for j in range(3):
            if initial[i][j] and initial[i][j] != final[i][j]:
                count += 1
    return count

def isSafe(x, y):
    return 0 <= x < 3 and 0 <= y < 3

def printPath(root):
    if root is None:
        return
    printPath(root.parent)
    printMatrix(root.mat)
    print("hscore:", root.hscore)
    print("gscore:", root.gscore)
    print("fscore:", root.hscore + root.gscore, "\n")

def solve(initial, x, y, final):
    pq = []
    root = Node(initial, x, y, x, y, 0, None)
    root.hscore = calculateCost(initial, final)
    pq.append((root.hscore + root.gscore, root))
    while pq:
        pq.sort(key=lambda x: x[0])
        _, min_node = pq.pop(0)
        if min_node.hscore == 0:
            printPath(min_node)
            return
        for i in range(4):
            if isSafe(min_node.x + row[i], min_node.y + col[i]):
                child = Node(min_node.mat, min_node.x, min_node.y, min_node.x + row[i],
                             min_node.y + col[i], min_node.gscore + 1, min_node)
                child.hscore = calculateCost(child.mat, final)
                pq.append((child.hscore + child.gscore, child))

row = [1, 0, -1, 0]
col = [0, -1, 0, 1]

initial = [[0] * 3 for _ in range(3)]
x, y = 0, 0

print("Enter Initial Block Structure")
print("Enter 0 for blank space:")
for i in range(3):
    for j in range(3):
        initial[i][j] = int(input(f"Row {i + 1} Column {j + 1} Element = "))
        if initial[i][j] == 0:
            x, y = i, j

final = [[0] * 3 for _ in range(3)]
print("\nEnter Final Block Structure")
print("Enter 0 for blank space:")
for i in range(3):
    for j in range(3):
        final[i][j] = int(input(f"Row {i + 1} Column {j + 1} Element = "))

print("\nInitial Structure:")
printMatrix(initial)
print("\nFinal Structure:")
printMatrix(final)
print("\nThis is the solution using A* Algorithm:\n")
solve(initial, x, y, final)
