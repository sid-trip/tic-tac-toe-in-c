#include <stdio.h>
#include <stdbool.h>

char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};

void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

bool isWinner() {
    for (int i = 0; i < 3; i++) {
        // Rows and Columns
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || 
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return true;
    }
    // Diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || 
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return true;

    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++) 
            if (board[i][j] != 'X' && board[i][j] != 'O') 
                return false;
    return true;
}

void makeMove(char player) {
    int choice;
    printf("Player %c, enter your move (1-9): ", player);
    scanf("%d", &choice);

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        printf("Invalid move! Try again.\n");
        makeMove(player);
    } else {
        board[row][col] = player;
    }
}

void resetBoard() {
    int count = 1;
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++) 
            board[i][j] = count++ + '0';
}

int main() {
    char playAgain = 'y';
    printf("Welcome to Tic-Tac-Toe!\n");

    while (playAgain == 'y' || playAgain == 'Y') {
        resetBoard();
        displayBoard();
        char currentPlayer = 'X';

        while (true) {
            makeMove(currentPlayer);
            displayBoard();

            if (isWinner()) {
                printf("Player %c wins! 🎉\n", currentPlayer);
                break;
            }

            if (isDraw()) {
                printf("It's a draw! 🤝\n");
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    }

    printf("Thanks for playing! 👋\n");
    return 0;
}
