// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
// Multiplication Table for 5:
// 5 x 1 = 5
// 5 x 2 = 10
// 5 x 3 = 15
// ...
// 5 x 12 = 60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
// Multiplication Table for 1:
// 1 x 1 = 1
// ...
// 1 x 12 = 12
// ---------------------------
// Multiplication Table for 2:
// 2 x 1 = 2
// ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//
// =============================================================================
// YOUR CODE BELOW
// =============================================================================
#include <iostream>

using namespace std;

// PART A: Function to print a single multiplication table from 1 to 12
void printSingleTable(int num) {
    cout << "\nMultiplication Table for " << num << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << num << " x " << i << " = " << (num * i) << endl;
    }
}

// PART B: Function to print full multiplication tables from 1 up to N
void printMultipleTables(int n) {
    for (int currentNum = 1; currentNum <= n; currentNum++) {
        printSingleTable(currentNum);
        
        // Print a separator line after every table except the last one
        if (currentNum < n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int singleNum;
    int maxN;

    cout << "=== PART A: SINGLE TABLE GENERATOR ===" << endl;
    cout << "Enter a number: ";
    cin >> singleNum;

    // Validate input for Part A
    if (singleNum <= 0) {
        cout << "Error: Number must be a positive integer." << endl;
        return 1; // Terminate program early
    }
    printSingleTable(singleNum);

    cout << "\n=== PART B: TABLES FROM 1 TO N ===" << endl;
    cout << "Enter a number N: ";
    cin >> maxN;

    // Validate input for Part B
    if (maxN <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 1; // Terminate program early
    }
    printMultipleTables(maxN);

    return 0;
}
