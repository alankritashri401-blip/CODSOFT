/*
 * ============================================================
 *  TASK 2 - SIMPLE CALCULATOR
 *  C++ Programming Internship Project
 *  Author: [alankrita shrivastava]
 * ============================================================
 *
 *  Description:
 *  A console-based calculator that performs:
 *    + Addition        - Subtraction
 *    * Multiplication  / Division  % Modulus (integers)
 *
 *  Features:
 *    • Input validation for numbers and operator
 *    • Division-by-zero protection
 *    • Continuous use until user chooses to exit
 * ============================================================
 */

#include <iostream>
#include <iomanip>   // for setprecision, fixed
#include <limits>    // for numeric_limits
#include <cmath>     // for fmod (floating-point modulus)

using namespace std;

// ─── Function Prototypes ───────────────────────────────────────
void  displayBanner();
void  displayMenu();
double getNumber(const string& prompt);
char  getOperator();
double calculate(double num1, double num2, char op, bool& validOp);
void  displayResult(double num1, double num2, char op, double result);
bool  continueCalculating();

// ─── Main ──────────────────────────────────────────────────────
int main() {
    displayBanner();

    do {
        displayMenu();

        double num1   = getNumber("  Enter first number  : ");
        char   op     = getOperator();
        double num2   = getNumber("  Enter second number : ");

        bool   validOp = true;
        double result  = calculate(num1, num2, op, validOp);

        if (validOp) {
            displayResult(num1, num2, op, result);
        }

    } while (continueCalculating());

    cout << "\n  Thank you for using the Calculator! 👋\n\n";
    return 0;
}

// ─── Display Banner ────────────────────────────────────────────
void displayBanner() {
    cout << "\n";
    cout << "  ╔══════════════════════════════════════╗\n";
    cout << "  ║         SIMPLE  CALCULATOR           ║\n";
    cout << "  ║    C++ Internship Task 2             ║\n";
    cout << "  ╚══════════════════════════════════════╝\n\n";
}

// ─── Display Operator Menu ─────────────────────────────────────
void displayMenu() {
    cout << "  ─────────────────────────────────────\n";
    cout << "   Available Operations:\n";
    cout << "    [+]  Addition\n";
    cout << "    [-]  Subtraction\n";
    cout << "    [*]  Multiplication\n";
    cout << "    [/]  Division\n";
    cout << "    [%]  Modulus\n";
    cout << "  ─────────────────────────────────────\n\n";
}

// ─── Get a Valid Double from User ─────────────────────────────
double getNumber(const string& prompt) {
    double number;
    while (true) {
        cout << prompt;
        if (cin >> number) {
            return number;
        }
        cout << "  ⚠️  Invalid input! Please enter a numeric value.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// ─── Get a Valid Operator from User ───────────────────────────
char getOperator() {
    char op;
    while (true) {
        cout << "  Choose operator (+, -, *, /, %): ";
        cin >> op;
        if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%') {
            return op;
        }
        cout << "  ⚠️  Invalid operator! Choose from: + - * / %\n";
    }
}

// ─── Perform the Calculation ──────────────────────────────────
double calculate(double num1, double num2, char op, bool& validOp) {
    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/':
            if (num2 == 0) {
                cout << "\n  ❌ Error: Division by zero is undefined!\n\n";
                validOp = false;
                return 0;
            }
            return num1 / num2;
        case '%':
            if (num2 == 0) {
                cout << "\n  ❌ Error: Modulus by zero is undefined!\n\n";
                validOp = false;
                return 0;
            }
            return fmod(num1, num2);
        default:
            validOp = false;
            return 0;
    }
}

// ─── Display the Result Nicely ─────────────────────────────────
void displayResult(double num1, double num2, char op, double result) {
    cout << "\n  ┌─────────────────────────────────┐\n";
    cout << "  │  " << fixed << setprecision(4)
         << num1 << " " << op << " " << num2
         << " = " << result << "\n";
    cout << "  └─────────────────────────────────┘\n\n";
}

// ─── Ask to Continue ──────────────────────────────────────────
bool continueCalculating() {
    char choice;
    cout << "  Perform another calculation? (y/n): ";
    cin  >> choice;
    cout << "\n";
    return (choice == 'y' || choice == 'Y');
}
