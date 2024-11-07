#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a job
struct Job {
    int id;       // Job ID
    int deadline; // Deadline of job
    int profit;   // Profit if job is done before or on deadline
};

// Comparator function to sort jobs based on profit in descending order
bool compareJobs(Job a, Job b) {
    return a.profit > b.profit;
}

// Function to find the maximum profit sequence of jobs
void jobSequencing(vector<Job>& jobs) {
    // Sort jobs by descending profit
    sort(jobs.begin(), jobs.end(), compareJobs);

    int n = jobs.size();
    int maxDeadline = 0;

    // Find maximum deadline
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    // Array to keep track of free time slots
    vector<int> slot(maxDeadline + 1, -1); // Initialize with -1 (no job scheduled)

    int totalProfit = 0;
    int jobCount = 0;

    // Schedule jobs in order of profit
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (starting from its deadline)
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == -1) { // If slot is free
                slot[j] = jobs[i].id; // Schedule this job
                totalProfit += jobs[i].profit;
                jobCount++;
                break;
            }
        }
    }

    // Display the result
    cout << "Scheduled Jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != -1) {
            cout << slot[i] << " ";
        }
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);
    cout << "Enter job details (ID, deadline, profit) for each job:\n";

    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> jobs[i].id;
        cout << "Deadline: ";
        cin >> jobs[i].deadline;
        cout << "Profit: ";
        cin >> jobs[i].profit;
    }

    jobSequencing(jobs);

    return 0;
}
