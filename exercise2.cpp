#include <iostream>
#include <ctime>
#include <cstdlib>

#define SIZE 5
#define MINES 5

int board[SIZE][SIZE];
bool revealed[SIZE][SIZE];

void init() {
    srand(time(0));
    for(int i = 0; i < MINES; i++) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if(board[x][y] != -1) {
            board[x][y] = -1;
        } else {
            i--;
        }
    }
}

int countMines(int x, int y) {
    int count = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if(x+i >= 0 && x+i < SIZE && y+j >= 0 && y+j < SIZE && board[x+i][y+j] == -1) {
                count++;
            }
        }
    }
    return count;
}

void reveal(int x, int y) {
    if(x >= 0 && x < SIZE && y >= 0 && y < SIZE && !revealed[x][y]) {
        revealed[x][y] = true;
        if(board[x][y] == -1) {
            std::cout << "Game Over\n";
            exit(0);
        } else {
            board[x][y] = countMines(x, y);
        }
    }
}

void printBoard() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(revealed[i][j]) {
                if(board[i][j] == -1) {
                    std::cout << "* ";
                } else {
                    std::cout << board[i][j] << " ";
                }
            } else {
                std::cout << "- ";
            }
        }
        std::cout << "\n";
    }
}

int main() {
    init();
    while(true) {
        printBoard();
        int x, y;
        std::cout << "Enter row and column: ";
        std::cin >> x >> y;
        reveal(x, y);
    }
    return 0;
}
