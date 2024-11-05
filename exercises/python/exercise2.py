import random

SIZE = 5
MINES = 5

board = [[0 for _ in range(SIZE)] for _ in range(SIZE)]
revealed = [[False for _ in range(SIZE)] for _ in range(SIZE)]


def init():
    mines_placed = 0
    while mines_placed < MINES:
        x = random.randint(0, SIZE - 1)
        y = random.randint(0, SIZE - 1)
        if board[x][y] != -1:
            board[x][y] = -1
            mines_placed += 1


def count_mines(x, y):
    count = 0
    for i in range(-1, 2):
        for j in range(-1, 2):
            if 0 <= x + i < SIZE and 0 <= y + j < SIZE and board[x + i][y + j] == -1:
                count += 1
    return count


def reveal(x, y):
    if 0 <= x < SIZE and 0 <= y < SIZE and not revealed[x][y]:
        revealed[x][y] = True
        if board[x][y] == -1:
            print("Game Over")
            exit(0)
        else:
            board[x][y] = count_mines(x, y)


def print_board():
    for i in range(SIZE):
        for j in range(SIZE):
            if revealed[i][j]:
                if board[i][j] == -1:
                    print("*", end=" ")
                else:
                    print(board[i][j], end=" ")
            else:
                print("-", end=" ")
        print()


def main():
    init()
    while True:
        print_board()
        x, y = map(int, input("Enter row and column: ").split())
        reveal(x, y)


if __name__ == "__main__":
    main()
