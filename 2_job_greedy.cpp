#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Job {
    char job_id;
    int deadline;
    int profit;
};

bool compareJobs(Job a, Job b) {
    return (a.profit > b.profit);
}

void job_sequencing(vector<Job>& jobs) {
    // Step 1: Sort jobs by descending profit
    sort(jobs.begin(), jobs.end(), compareJobs);

    // Step 2: Find the maximum deadline to create time slots
    int max_deadline = 0;
    for (const auto& job : jobs) {
        if (job.deadline > max_deadline) {
            max_deadline = job.deadline;
        }
    }

    // slots[i] will store the job_id scheduled at time i
    // Using 1-based indexing for slots, so size is max_deadline + 1
    vector<char> slots(max_deadline + 1, -1); 

    int total_profit = 0;
    int job_count = 0;

    // Step 3: Assign jobs to slots greedily
    for (const auto& job : jobs) {
        // Try to find a free slot before or on the deadline
        for (int t = job.deadline; t > 0; --t) {
            if (slots[t] == -1) {
                slots[t] = job.job_id;
                total_profit += job.profit;
                job_count += 1;
                break; // Move to the next job
            }
        }
    }

    // Step 4: Print result
    cout << "Scheduled Jobs: ";
    for (int i = 1; i <= max_deadline; ++i) {
        if (slots[i] != -1) {
            cout << slots[i] << " ";
        }
    }
    cout << endl;

    cout << "Total Jobs Done: " << job_count << endl;
    cout << "Total Profit: " << total_profit << endl;
}

int main() {
    // Example usage
    vector<Job> jobs = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    job_sequencing(jobs);

    return 0;
}