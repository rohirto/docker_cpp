#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <termios.h>

using namespace std;

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;

class Tetris {
public:
    Tetris();
    void run();

private:
    vector<vector<char>> board;
    int currentPiece;
    int currentRotation;
    int currentX, currentY;

    void initBoard();
    void drawBoard();
    void drawPiece();
    bool isValidMove(int x, int y, int piece, int rotation);
    void placePiece();
    void clearLines();
    bool isGameOver();
    int getRandomPiece();
    void getInput(char& input);
    void rotatePiece();
    void movePieceLeft();
    void movePieceRight();
    void movePieceDown();
};

Tetris::Tetris() {
    srand(time(nullptr));
    initBoard();
    currentPiece = getRandomPiece();
    currentRotation = 0;
    currentX = BOARD_WIDTH / 2;
    currentY = 0;
}

void Tetris::initBoard() {
    board.assign(BOARD_HEIGHT, vector<char>(BOARD_WIDTH, ' '));
}

void Tetris::drawBoard() {
    system("clear");  // Clear the console (Linux specific)
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void Tetris::drawPiece() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if ((i + currentY >= 0) && (i + currentY < BOARD_HEIGHT) && (j + currentX >= 0) &&
                (j + currentX < BOARD_WIDTH)) {
                if ((piece[currentPiece][currentRotation][i][j] != ' ') &&
                    (board[i + currentY][j + currentX] == ' ')) {
                    board[i + currentY][j + currentX] = piece[currentPiece][currentRotation][i][j];
                }
            }
        }
    }
}

bool Tetris::isValidMove(int x, int y, int piece, int rotation) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (pieceShapes[piece][rotation][i][j] != ' ') {
                if ((x + j < 0) || (x + j >= BOARD_WIDTH) || (y + i >= BOARD_HEIGHT) ||
                    (board[y + i][x + j] != ' ')) {
                    return false;
                }
            }
        }
    }
    return true;
}

void Tetris::placePiece() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (piece[currentPiece][currentRotation][i][j] != ' ') {
                board[currentY + i][currentX + j] = piece[currentPiece][currentRotation][i][j];
            }
        }
    }
}

void Tetris::clearLines() {
    for (int i = BOARD_HEIGHT - 1; i >= 0; --i) {
        bool lineIsFull = true;
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            if (board[i][j] == ' ') {
                lineIsFull = false;
                break;
            }
        }
        if (lineIsFull) {
            for (int k = i; k > 0; --k) {
                for (int j = 0; j < BOARD_WIDTH; ++j) {
                    board[k][j] = board[k - 1][j];
                }
            }
            // Increment i to recheck the current line
            ++i;
        }
    }
}

bool Tetris::isGameOver() {
    for (int j = 0; j < BOARD_WIDTH; ++j) {
        if (board[0][j] != ' ') {
            return true;
        }
    }
    return false;
}

int Tetris::getRandomPiece() {
    return rand() % 7;  // There are 7 different Tetris pieces
}

void Tetris::getInput(char& input) {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    cin >> input;
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

void Tetris::rotatePiece() {
    int newRotation = (currentRotation + 1) % 4;
    if (isValidMove(currentX, currentY, currentPiece, newRotation)) {
        currentRotation = newRotation;
    }
}

void Tetris::movePieceLeft() {
    if (isValidMove(currentX - 1, currentY, currentPiece, currentRotation)) {
        --currentX;
    }
}

void Tetris::movePieceRight() {
    if (isValidMove(currentX + 1, currentY, currentPiece, currentRotation)) {
        ++currentX;
    }
}

void Tetris::movePieceDown() {
    if (isValidMove(currentX, currentY + 1, currentPiece, currentRotation)) {
        ++currentY;
    } else {
        placePiece();
        clearLines();
        currentPiece = getRandomPiece();
        currentRotation = 0;
        currentX = BOARD_WIDTH / 2;
        currentY = 0;

        if (!isValidMove(currentX, currentY, currentPiece, currentRotation)) {
            // If the new piece cannot be placed, the game is over
            cout << "Game Over!\n";
            exit(0);
        }
    }
}

int main() {
    Tetris tetris;
    char input;

    while (true) {
        tetris.drawBoard();
        tetris.drawPiece();

        tetris.getInput(input);

        switch (input) {
            case 'a':
                tetris.movePieceLeft();
                break;
            case 'd':
                tetris.movePieceRight();
                break;
            case 's':
                tetris.movePieceDown();
                break;
            case 'w':
                tetris.rotatePiece();
                break;
            case 'q':
                exit(0);
            default:
                break;
        }
    }

    return 0;
}
``
