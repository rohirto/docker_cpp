#include <iostream>
#include <vector>
#include <cstdlib> // For system("clear") or system("cls")

// Function to clear the terminal screen
void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

// Function to print the Tic Tac Toe board
void printBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';

    while (true) {
        clearScreen();
        printBoard(board);

        // Get player move
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        // Validate the move
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            std::cout << "Invalid move! Try again.\n";
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            clearScreen();
            printBoard(board);
            std::cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        // Check for a tie
        bool isTie = true;
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ') {
                    isTie = false;
                    break;
                }
            }
            if (!isTie) {
                break;
            }
        }

        if (isTie) {
            clearScreen();
            printBoard(board);
            std::cout << "It's a tie!\n";
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
