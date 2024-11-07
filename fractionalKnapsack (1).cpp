#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item with weight and value
struct Item {
    int weight;
    int value;

    // Calculate value-to-weight ratio
    double valuePerWeight() const {
        return (double)value / weight;
    }
};

// Comparator function to sort items by value-to-weight ratio in descending order
bool compareItems(const Item& a, const Item& b) {
    return a.valuePerWeight() > b.valuePerWeight();
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(int capacity, vector<Item>& items) {
    // Sort items by value-to-weight ratio
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;  // Total value accumulated in the knapsack
    int currentWeight = 0;    // Current weight of the knapsack

    for (const auto& item : items) {
        if (currentWeight + item.weight <= capacity) {
            // Take the whole item
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            // Take fraction of the item
            int remainingWeight = capacity - currentWeight;
            totalValue += item.valuePerWeight() * remainingWeight;
            break; // Knapsack is now full
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    vector<Item> items(n);
    cout << "Enter weight and value for each item:\n";

    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ":\n";
        cout << "Weight: ";
        cin >> items[i].weight;
        cout << "Value: ";
        cin >> items[i].value;
    }

    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
