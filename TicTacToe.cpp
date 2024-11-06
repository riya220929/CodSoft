#include <iostream>
#include <vector>

void displayBoard(const std::vector<char>& board) {
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    std::cout << "---|---|---\n";
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    std::cout << "---|---|---\n";
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n\n";
}

bool checkWin(const std::vector<char>& board, char player) {
    // Check rows, columns, and diagonals for a win
    return ((board[0] == player && board[1] == player && board[2] == player) ||
            (board[3] == player && board[4] == player && board[5] == player) ||
            (board[6] == player && board[7] == player && board[8] == player) ||
            (board[0] == player && board[3] == player && board[6] == player) ||
            (board[1] == player && board[4] == player && board[7] == player) ||
            (board[2] == player && board[5] == player && board[8] == player) ||
            (board[0] == player && board[4] == player && board[8] == player) ||
            (board[2] == player && board[4] == player && board[6] == player));
}

bool checkDraw(const std::vector<char>& board) {
    for (char cell : board) {
        if (cell != 'X' && cell != 'O') {
            return false; // Found an empty cell, so it's not a draw
        }
    }
    return true;
}

void playGame() {
    std::vector<char> board(9); // 3x3 board represented by a 1D array
    for (int i = 0; i < 9; ++i) {
        board[i] = '1' + i; // Fill board with numbers 1-9 for easier user input
    }

    char currentPlayer = 'X';
    bool gameOngoing = true;

    while (gameOngoing) {
        displayBoard(board);
        int move;
        
        std::cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        std::cin >> move;

        // Validate the move
        if (move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O') {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }

        // Update the board and check for a win or draw
        board[move - 1] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            std::cout << "Player " << currentPlayer << " wins!\n";
            gameOngoing = false;
        } else if (checkDraw(board)) {
            displayBoard(board);
            std::cout << "The game is a draw!\n";
            gameOngoing = false;
        } else {
            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

int main() {
    char playAgain;
    do {
        playGame();
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thanks for playing!\n";
    return 0;
}
