#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void fractionalKnapsack() {
    // Step 1: Take number of items
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<double> weights(n), values(n);

    // Step 2: Take weight and value for each item
    cout << "\nEnter weight and value for each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Weight of item " << i + 1 << ": ";
        cin >> weights[i];
        cout << "Value of item " << i + 1 << ": ";
        cin >> values[i];
    }

    // Step 3: Take knapsack capacity
    double capacity;
    cout << "\nEnter knapsack capacity: ";
    cin >> capacity;

    // Step 4: Calculate value/weight ratio for each item
    vector<double> ratio(n);
    for (int i = 0; i < n; i++) {
        ratio[i] = values[i] / weights[i];
    }

    // Step 5: Sort items manually by ratio (descending)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(weights[i], weights[j]);
                swap(values[i], values[j]);
            }
        }
    }

    // Step 6: Apply greedy selection
    double totalValue = 0.0;
    cout << fixed << setprecision(2);
    cout << "\nItem selection process:\n";

    for (int i = 0; i < n; i++) {
        if (capacity == 0)
            break;

        if (weights[i] <= capacity) {
            totalValue += values[i];
            capacity -= weights[i];
            cout << "  Took full item (weight=" << weights[i]
                 << ", value=" << values[i] << ")\n";
        } else {
            double fraction = capacity / weights[i];
            totalValue += values[i] * fraction;
            cout << "  Took " << fraction * 100 << "% of item (weight=" << weights[i]
                 << ", value=" << values[i] << ")\n";
            capacity = 0;
        }
    }

    cout << "\nMaximum value in knapsack = " << totalValue << endl;
}

// Step 7: Run the program
int main() {
    fractionalKnapsack();
    return 0;
}
