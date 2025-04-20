#include <stdio.h>
#include <stdbool.h>

#define N 4

void printBoard(char board[N][N]) {
    printf("__________\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c  ", board[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(char board[N][N], int row, int col) {
    // Check vertical up
    for (int i = row - 1; i >= 0; i--) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // Check diagonal left up
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Check diagonal right up
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

void nQueen(char board[N][N], int row) {
    if (row == N) {
        printBoard(board);
        return;
    }

    for (int j = 0; j < N; j++) {
        if (isSafe(board, row, j)) {
            board[row][j] = 'Q';
            nQueen(board, row + 1);
            board[row][j] = 'X'; // backtrack
        }
    }
}

int main() {
    char board[N][N];

    // Initialize board
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 'X';
        }
    }

    nQueen(board, 0);
    return 0;
}
