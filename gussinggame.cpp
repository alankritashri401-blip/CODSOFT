/*
 * ============================================================
 *  TASK 1 - NUMBER GUESSING GAME
 *  C++ Programming Internship Project
 *  Author: [alankrita shrivastava]
 * ============================================================
 *
 *  Description:
 *  A console-based game where the computer generates a random
 *  number and the user tries to guess it. The program gives
 *  "Too High" or "Too Low" feedback after each guess.
 * ============================================================
 */

#include <iostream>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
#include <limits>    // for numeric_limits

using namespace std;

// ─── Function Prototypes ───────────────────────────────────────
void displayWelcomeBanner();
void playGame();
bool playAgain();
int  getUserGuess(int minRange, int maxRange);

// ─── Main ──────────────────────────────────────────────────────
int main() {
    // Seed the random number generator with current time
    srand(static_cast<unsigned int>(time(0)));

    displayWelcomeBanner();

    // Game loop – keeps playing until user decides to quit
    do {
        playGame();
    } while (playAgain());

    cout << "\n  Thanks for playing! Goodbye! 👋\n\n";
    return 0;
}

// ─── Display Welcome Banner ────────────────────────────────────
void displayWelcomeBanner() {
    cout << "\n";
    cout << "  ╔══════════════════════════════════════╗\n";
    cout << "  ║       NUMBER  GUESSING  GAME         ║\n";
    cout << "  ║    C++ Internship Task 1             ║\n";
    cout << "  ╚══════════════════════════════════════╝\n";
    cout << "\n  Guess the secret number between 1 and 100!\n\n";
}

// ─── Core Game Logic ───────────────────────────────────────────
void playGame() {
    const int MIN_RANGE = 1;
    const int MAX_RANGE = 100;

    // Generate a random number in [1, 100]
    int secretNumber = (rand() % MAX_RANGE) + MIN_RANGE;

    int guess       = 0;
    int attempts    = 0;
    bool hasWon     = false;

    cout << "  ─────────────────────────────────────\n";
    cout << "  A new secret number has been chosen!\n";
    cout << "  ─────────────────────────────────────\n\n";

    // Guessing loop
    while (!hasWon) {
        guess = getUserGuess(MIN_RANGE, MAX_RANGE);
        attempts++;

        if (guess < secretNumber) {
            cout << "  📉  Too LOW!  Try a higher number.\n\n";
        } else if (guess > secretNumber) {
            cout << "  📈  Too HIGH! Try a lower number.\n\n";
        } else {
            hasWon = true;
        }
    }

    // Victory message
    cout << "  ✅  CORRECT! The number was " << secretNumber << "!\n";
    cout << "  🏆  You guessed it in " << attempts;
    if (attempts == 1) cout << " attempt";
    else               cout << " attempts";
    cout << ".\n\n";

    // Performance feedback
    if (attempts <= 5)       cout << "  ⭐ Excellent! You're a guessing genius!\n\n";
    else if (attempts <= 8)  cout << "  👍 Good job! Keep practising!\n\n";
    else                     cout << "  💡 Tip: Use binary search – always guess the middle!\n\n";
}

// ─── Get a Valid Integer from the User ────────────────────────
int getUserGuess(int minRange, int maxRange) {
    int guess;
    while (true) {
        cout << "  Enter your guess (" << minRange << " - " << maxRange << "): ";
        if (cin >> guess) {
            if (guess >= minRange && guess <= maxRange) {
                return guess;
            }
            cout << "  ⚠️  Please enter a number between "
                 << minRange << " and " << maxRange << ".\n";
        } else {
            // Clear bad input (e.g., letters)
            cout << "  ⚠️  Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// ─── Ask User to Play Again ────────────────────────────────────
bool playAgain() {
    char choice;
    cout << "  Do you want to play again? (y/n): ";
    cin  >> choice;
    cout << "\n";
    return (choice == 'y' || choice == 'Y');
}
