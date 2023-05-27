class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.graph = [[0 for _ in range(vertices)] for _ in range(vertices)]

    def is_safe(self, v, color, c):
        for i in range(self.vertices):
            if self.graph[v][i] == 1 and color[i] == c:
                return False
        return True

    def graph_coloring(self, m):
        color = [-1] * self.vertices
        found_solution = self.graph_coloring_util(m, color, 0)
        if not found_solution:
            print("No solution exists.")

    def graph_coloring_util(self, m, color, v):
        if v == self.vertices:
            self.print_solution(color)
            return True

        for c in range(m):
            if self.is_safe(v, color, c):
                color[v] = c
                if self.graph_coloring_util(m, color, v + 1):
                    return True
                color[v] = -1

        return False

    def print_solution(self, color):
        color_names = ["Red", "Green", "Blue", "Yellow", "Orange"]  # Add more colors if needed
        for v in range(self.vertices):
            print("Vertex", v, "is colored", color_names[color[v]])


# Example usage
g = Graph(4)
g.graph = [
    [0, 1, 1, 1],
    [1, 0, 1, 0],
    [1, 1, 0, 1],
    [1, 0, 1, 0]
]

m = 3  # Number of available colors
g.graph_coloring(m)
