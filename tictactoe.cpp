/*
 * ============================================================
 *  TASK 3 - TIC-TAC-TOE GAME
 *  C++ Programming Internship Project
 *  Author: [alankrita shrivastava]
 * ============================================================
 *
 *  Description:
 *  A console-based 2-player Tic-Tac-Toe game.
 *  Features:
 *    • 3x3 Game Board
 *    • Two players: X and O
 *    • Input validation
 *    • Win / Draw detection
 *    • Play again option
 * ============================================================
 */

#include <iostream>
#include <limits>

using namespace std;

// ─── Constants ─────────────────────────────────────────────────
const int SIZE = 3;

// ─── Function Prototypes ───────────────────────────────────────
void  initBoard(char board[SIZE][SIZE]);
void  displayBoard(const char board[SIZE][SIZE]);
bool  playerMove(char board[SIZE][SIZE], char currentPlayer);
bool  checkWin(const char board[SIZE][SIZE], char player);
bool  checkDraw(const char board[SIZE][SIZE]);
void  switchPlayer(char& currentPlayer);
void  displayResult(char winner);
bool  playAgain();
void  displayBanner();

// ─── Main ──────────────────────────────────────────────────────
int main() {
    displayBanner();

    do {
        char board[SIZE][SIZE];
        initBoard(board);

        char currentPlayer = 'X';
        char winner        = ' ';
        bool gameOver      = false;

        cout << "\n  Player X and Player O — Let's begin!\n\n";

        while (!gameOver) {
            displayBoard(board);

            // Get valid move from current player
            bool moveMade = false;
            while (!moveMade) {
                moveMade = playerMove(board, currentPlayer);
            }

            // Check win
            if (checkWin(board, currentPlayer)) {
                winner   = currentPlayer;
                gameOver = true;
            }
            // Check draw
            else if (checkDraw(board)) {
                winner   = 'D'; // D = Draw
                gameOver = true;
            }
            // Switch turn
            else {
                switchPlayer(currentPlayer);
            }
        }

        // Show final board and result
        displayBoard(board);
        displayResult(winner);

    } while (playAgain());

    cout << "\n  Thanks for playing Tic-Tac-Toe! Goodbye! 👋\n\n";
    return 0;
}

// ─── Initialize Board with empty spaces ───────────────────────
void initBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = ' ';
}

// ─── Display the Board ─────────────────────────────────────────
void displayBoard(const char board[SIZE][SIZE]) {
    cout << "\n";
    cout << "       1   2   3\n";
    cout << "     ┌───┬───┬───┐\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "  " << (i + 1) << "  │";
        for (int j = 0; j < SIZE; j++) {
            cout << " " << board[i][j] << " │";
        }
        cout << "\n";
        if (i < SIZE - 1)
            cout << "     ├───┼───┼───┤\n";
    }
    cout << "     └───┴───┴───┘\n\n";
}

// ─── Get Player Move and Update Board ─────────────────────────
bool playerMove(char board[SIZE][SIZE], char currentPlayer) {
    int row, col;

    cout << "  Player " << currentPlayer << "'s turn.\n";
    cout << "  Enter row (1-3): ";
    if (!(cin >> row)) {
        cout << "  ⚠️  Invalid input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    cout << "  Enter col (1-3): ";
    if (!(cin >> col)) {
        cout << "  ⚠️  Invalid input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    // Convert to 0-indexed
    row--; col--;

    // Validate range
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        cout << "  ⚠️  Out of range! Enter values between 1 and 3.\n\n";
        return false;
    }

    // Check if cell is already occupied
    if (board[row][col] != ' ') {
        cout << "  ⚠️  Cell already taken! Choose another.\n\n";
        return false;
    }

    // Place the mark
    board[row][col] = currentPlayer;
    return true;
}

// ─── Check if a Player Has Won ─────────────────────────────────
bool checkWin(const char board[SIZE][SIZE], char player) {
    // Check all rows
    for (int i = 0; i < SIZE; i++)
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;

    // Check all columns
    for (int j = 0; j < SIZE; j++)
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;

    // Check main diagonal (top-left to bottom-right)
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    // Check anti-diagonal (top-right to bottom-left)
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// ─── Check for Draw (Board Full, No Winner) ───────────────────
bool checkDraw(const char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ')
                return false; // Empty cell found, not a draw yet
    return true;
}

// ─── Switch Between Players ────────────────────────────────────
void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// ─── Display Game Result ───────────────────────────────────────
void displayResult(char winner) {
    cout << "  ════════════════════════════════════\n";
    if (winner == 'D') {
        cout << "  🤝  It's a DRAW! Well played both!\n";
    } else {
        cout << "  🏆  Player " << winner << " WINS! Congratulations!\n";
    }
    cout << "  ════════════════════════════════════\n\n";
}

// ─── Ask to Play Again ─────────────────────────────────────────
bool playAgain() {
    char choice;
    cout << "  Play again? (y/n): ";
    cin  >> choice;
    cout << "\n";
    return (choice == 'y' || choice == 'Y');
}

// ─── Welcome Banner ────────────────────────────────────────────
void displayBanner() {
    cout << "\n";
    cout << "  ╔══════════════════════════════════════╗\n";
    cout << "  ║        TIC - TAC - TOE  GAME         ║\n";
    cout << "  ║    C++ Internship Task 3             ║\n";
    cout << "  ╚══════════════════════════════════════╝\n";
}
