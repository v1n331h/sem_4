def make_move(move, matrix, i, j):
    if move == 'u':
        if i > 0:
            matrix[i][j], matrix[i-1][j] = matrix[i-1][j], matrix[i][j]
            board(matrix)
        else:
            print("Invalid move\n")
    elif move == 'd':
        if i < 2:  # Changed 3 to 2, as matrix is 3x3 (index range 0-2)
            matrix[i][j], matrix[i+1][j] = matrix[i+1][j], matrix[i][j]
            board(matrix)  # Fixed print statement
        else:
            print("Invalid move")
    elif move == 'l':
        if j > 0:
            matrix[i][j], matrix[i][j-1] = matrix[i][j-1], matrix[i][j]
            board(matrix)
        else:
            print("Invalid move")
    elif move == 'r':
        if j < 2:  # Changed 3 to 2 for the correct matrix size
            matrix[i][j], matrix[i][j+1] = matrix[i][j+1], matrix[i][j]
            board(matrix)
        else:
            print("Invalid move")

def board(matrix):
    for row in matrix:
        print(" ".join(map(str, row)))  # Fixed printing format for better readability
    print()

def check_h(matrix, goal_matrix):
    h_count = 0
    for i in range(3):
        for j in range(3):
            if matrix[i][j] == goal_matrix[i][j]:
                h_count += 1
    return h_count

def main():
    matrix = [[3, 7, 6], [5, 1, 2], [4, 0, 8]]
    matrix_goal = [[5, 3, 6], [7, 0, 2], [4, 1, 8]]
    
    board(matrix)  # Display initial board
    
    print("Enter position of 0 (i, j): ")
    i, j = map(int, input().split())  # Fixed input handling to take two integers
    
    move = input("Enter a move (UP -> u, DOWN -> d, LEFT -> l, RIGHT -> r): ")
    make_move(move, matrix, i, j)  # Added function call to actually execute the move

main()
