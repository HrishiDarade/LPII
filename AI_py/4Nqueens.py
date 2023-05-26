def check_safety(board, row, col):
    n = len(board)

    # Check for conflicting queen in the same row
    for i in range(col):
        if board[row][i] == 1:
            return False

    # Check top left diagonal
    r, c = row, col
    while r >= 0 and c >= 0:
        if board[r][c] == 1:
            return False
        r -= 1
        c -= 1

    # Check bottom left diagonal
    r, c = row, col
    while r < n and c >= 0:
        if board[r][c] == 1:
            return False
        r += 1
        c -= 1

    return True  # No conflicting queen present


def solve_n_queens(board, col, n):
    if col == n:
        return True  # All queens have been placed successfully

    for row in range(n):
        if check_safety(board, row, col):
            board[row][col] = 1  # Place the queen

            if solve_n_queens(board, col + 1, n):
                return True  # Queen placement successful for remaining columns

            board[row][col] = 0  # Backtrack and try next row

    return False  # Queen placement not possible for this configuration


def print_board(board):
    for row in board:
        for cell in row:
            if cell == 1:
                print(" Q ", end="")
            else:
                print(" _ ", end="")
        print()


while True:
    n = int(input("\nEnter the number of queens: "))

    if n == -1:
        print("\nThank You.....")
        break

    board = [[0] * n for _ in range(n)]

    if solve_n_queens(board, 0, n):
        print("\n")
        print_board(board)
        print("\nPositions of Queens:")
        for i in range(n):
            for j in range(n):
                if board[i][j] == 1:
                    print(f"Queen {i + 1}: Row {i + 1}, Column {j + 1}")
    else:
        print("\nSolution not possible\n")

    print("\nEnter -1 to exit...\n")
