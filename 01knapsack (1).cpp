#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(vector<int>& weights, vector<int>& profits, int n, int maxWeight) {
    vector<vector<int> > K(n + 1, vector<int>(maxWeight + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            if (weights[i - 1] <= w) {
                // Choose the maximum of including or excluding the item
                K[i][w] = max(profits[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            } else {
                // Exclude the item
                K[i][w] = K[i - 1][w];
            }
        }
    }

    return K[n][maxWeight];
}

int main() {
    int n, maxWeight;

    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> profits(n);
    vector<int> weights(n);

    cout << "Enter the profits of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> profits[i];
    }

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> maxWeight;

    int maxProfit = knapsack(weights, profits, n, maxWeight);

    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
