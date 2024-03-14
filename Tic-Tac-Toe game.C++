#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void displayBoard(const vector<vector<char>> &board);
bool checkWin(const vector<vector<char>> &board, char player);
bool checkDraw(const vector<vector<char>> &board);
void updateBoard(vector<vector<char>> &board, int row, int col, char player);
bool playAgain(const vector<vector<char>> &boar);

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // 3x3 game board
    char currentPlayer = 'X';
    bool gameOver = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    do {
        // Display board
        displayBoard(board);

        // Get player move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row col): ";
        cin >> row >> col;

        // Update board
        updateBoard(board, row, col, currentPlayer);

        // Check for win
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        } else if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            gameOver = true;
        } else {
            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

    } while (!gameOver);

    cout << "Thanks for playing!" << endl;

    return 0;
}

void displayBoard(const vector<vector<char>> &board) {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) {
                cout << "|";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "  -----" << endl;
        }
    }
}

bool checkWin(const vector<vector<char>> &board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Row
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Column
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Diagonal
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Diagonal
    }
    return false;
}

bool checkDraw(const vector<vector<char>> &board) {
    // Check if all cells are filled
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // Not a draw
            }
        }
    }
    return true; // Draw
}

void updateBoard(vector<vector<char>> &board, int row, int col, char player) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
    } else {
        cout << "Invalid move. Try again." << endl;
    }
}

// ... (rest of the functions)

bool playAgain() {
    char response;
    cout << "Do you want to play again? (y/n): ";
    cin >> response;

    if (response == 'y' || response == 'Y') {
        return true;
    }

    return false;
}