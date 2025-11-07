#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

long long fib_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

void fib_non_recursive(int n) {
    if (n <= 0) {
        cout << endl;
        return;
    }

    long long n1 = 0;
    long long n2 = 1;

    if (n == 1) {
        cout << n1 << " " << endl;
        return;
    }

    cout << n1 << " " << n2 << " ";
    for (int i = 2; i < n; ++i) {
        long long n3 = n1 + n2;
        cout << n3 << " ";
        n1 = n2;
        n2 = n3;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "\nFibonacci Sequence (Recursive): ";
    for (int i = 0; i < n; ++i) {
        cout << fib_recursive(i) << " ";
    }

    cout << "\n\nFibonacci Sequence (Non-Recursive): ";
    fib_non_recursive(n);

    cout << endl; // For clean terminal output

    return 0;
}