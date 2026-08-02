// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
// Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
// Original Matrix:       Transposed Matrix:
// 1 2 3                  1 4
// 4 5 6                  2 5
//                        3 6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
// Enter number of rows: 2
// Enter number of columns: 3
// Enter element [0][0]: 1
// Enter element [0][1]: 2
// ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//
// =============================================================================
// YOUR CODE BELOW
// =============================================================================
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_SIZE = 10;

// Helper function to read a matrix from the user
void inputMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

// Helper function to print a matrix in a neat grid format
void displayMatrix(const int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

// PART A: Transpose a matrix
void transposeMatrix(const int src[MAX_SIZE][MAX_SIZE], int dest[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[j][i] = src[i][j]; // Rows become columns, columns become rows
        }
    }
}

// PART B: Add two matrices element-wise
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int sum[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }
}

// PART C: Multiply two matrices (A x B)
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int product[MAX_SIZE][MAX_SIZE], int rA, int cA, int cB) {
    // Initialize product matrix with zeros
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            product[i][j] = 0;
            // The inner loop iterates through row elements of A and column elements of B
            for (int k = 0; k < cA; k++) {
                product[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[MAX_SIZE][MAX_SIZE];
    int B[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    
    int rA, cA, rB, cB;

    cout << "=== PART A: MATRIX TRANSPOSE ===" << endl;
    cout << "Enter number of rows: ";
    cin >> rA;
    cout << "Enter number of columns: ";
    cin >> cA;

    if (rA <= 0 || rA > MAX_SIZE || cA <= 0 || cA > MAX_SIZE) {
        cout << "Error: Dimensions must be between 1 and " << MAX_SIZE << "." << endl;
        return 1;
    }

    cout << "Input items for Matrix A:" << endl;
    inputMatrix(A, rA, cA);

    cout << "\nOriginal Matrix A:" << endl;
    displayMatrix(A, rA, cA);

    // Compute and display transpose
    transposeMatrix(A, result, rA, cA);
    cout << "\nTransposed Matrix A:" << endl;
    displayMatrix(result, cA, rA); // Note that rows and columns swap positions

    cout << "\n=== PART B: MATRIX ADDITION ===" << endl;
    cout << "Matrix B must be the same size (" << rA << "x" << cA << ")." << endl;
    cout << "Input items for Matrix B:" << endl;
    inputMatrix(B, rA, cA);

    addMatrices(A, B, result, rA, cA);
    cout << "\nResult of A + B:" << endl;
    displayMatrix(result, rA, cA);

    cout << "\n=== PART C: MATRIX MULTIPLICATION ===" << endl;
    cout << "For A x B, Matrix B rows must equal Matrix A columns (" << cA << ")." << endl;
    rB = cA; // Enforce rule: inner dimensions must match
    cout << "Enter number of columns for Matrix B: ";
    cin >> cB;

    if (cB <= 0 || cB > MAX_SIZE) {
        cout << "Error: Dimensions must be between 1 and " << MAX_SIZE << "." << endl;
        return 1;
    }

    cout << "Input items for Matrix B (" << rB << "x" << cB << "):" << endl;
    inputMatrix(B, rB, cB);

    multiplyMatrices(A, B, result, rA, cA, cB);
    cout << "\nResult of A x B:" << endl;
    displayMatrix(result, rA, cB);

    return 0;
}
