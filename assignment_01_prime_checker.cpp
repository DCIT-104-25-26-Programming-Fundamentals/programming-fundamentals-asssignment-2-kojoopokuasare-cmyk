#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    // Numbers less than 2 are not prime
    if (n < 2) {
        return false;
    }
    
    // Check for factors from 2 up to n/2
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false; // Found a factor, so it is not prime
        }
    }
    
    return true; // No factors found, it is prime
}

int main() {
    int number;
    
    // Prompt the user for input
    cout << "Enter a number: ";
    cin >> number;
    
    // Call the function and print the result based on the requirements
    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is NOT a prime number." << endl;
    }
    
    return 0;
}
