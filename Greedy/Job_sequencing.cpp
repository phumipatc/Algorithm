/*
	Task		: Job_sequencing
	Author		: PunnyOz2
	Language	: C++
	Explanation	: 
	Created		: 01 October 2022 [15:39]
*/
#include<bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job {
   
    char id; // Job Id
    int dead; // Deadline of job
    int profit; // Profit earned if job is completed before
                // deadline
    bool operator<(const Job &o) const{
        return profit > o.profit;
    }
};

vector<Job> jobSequencingResult(vector<Job> arr, int n) {
    sort(arr.begin(), arr.end(), [](Job a, Job b) { return a.dead < b.dead; });
    priority_queue<Job> pq;
    vector<Job> ans;
    for (int i = n - 1; i >= 0; i--) {
        int slot_available;
        if (pq.empty()) {
            slot_available = arr[i].dead;
        } else {
            slot_available = arr[i].dead - arr[i-1].dead;
        }
        pq.push(arr[i]);
        while(!slot_available && !pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
            slot_available--;
        }
    }
    sort(ans.begin(), ans.end(), [&](Job a, Job b) { return a.dead < b.dead; });
    return ans;
}

int jobSequencingProfitSum(vector<Job> arr, int n) {
    sort(arr.begin(), arr.end(), [](Job a, Job b) { return a.dead < b.dead; });
    priority_queue<Job> pq;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int slot_available;
        if (pq.empty()) {
            slot_available = arr[i].dead;
        } else {
            slot_available = arr[i].dead - arr[i-1].dead;
        }
        pq.push(arr[i]);
        while(!slot_available && !pq.empty()) {
            ans += pq.top().profit;
            pq.pop();
            slot_available--;
        }
    }
    return ans;
}