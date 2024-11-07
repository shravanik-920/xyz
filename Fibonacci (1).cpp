#include <iostream>
using namespace std;

// Global variable to count the number of steps
int stepCount = 0;

// Recursive function to calculate Fibonacci number
int fibonacci(int n) {
    stepCount++;  // Increment step count for each function call
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    cout << "Enter the position (n) for the Fibonacci series: ";
    cin >> n;

    // Print Fibonacci series up to position n
    cout << "Fibonacci series up to position " << n << " is: ";
    for (int i = 0; i <= n; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    // Calculate and print the Fibonacci number at position n
    int result = fibonacci(n);
    cout << "Fibonacci number at position " << n << " is: " << result << endl;

    // Print the total step count
    cout << "Total steps (function calls) taken: " << stepCount << endl;

    return 0;
}
