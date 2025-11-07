#include <iostream>
#include <vector>
#include <algorithm> // For std::max

// Use the standard namespace
using namespace std;


void knapsack_dp() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weights;
    vector<int> values;

    cout << "\nEnter weight and value (profit) for each item separated by space:\n";
    for (int i = 0; i < n; ++i) {
        int w, v;
        cout << "Item " << i + 1 << ": ";
        cin >> w >> v;
        weights.push_back(w);
        values.push_back(v);
    }

    int W;
    cout << "\nEnter maximum capacity of knapsack: ";
    cin >> W;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {

            if (weights[i - 1] <= w) {

                int include = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                int exclude = dp[i - 1][w];
                dp[i][w] = max(include, exclude);
            } else {
                
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Step 4: Output result
    // The final answer is in the bottom-right cell of the table
    cout << "\n Maximum profit that can be obtained: " << dp[n][W] << endl;
}

int main() {
    knapsack_dp();
    return 0;
}