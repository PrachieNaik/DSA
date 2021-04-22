/*

Problem statement:Given N jobs where every job is represented by following three elements of it.

Start Time
Finish Time
Profit or Value Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.

Example:

Input: Number of Jobs n = 4
       Job Details {Start Time, Finish Time, Profit}
       Job 1:  {1, 2, 50} 
       Job 2:  {3, 5, 20}
       Job 3:  {6, 19, 100}
       Job 4:  {2, 100, 200}
Output: The maximum profit is 250. We can get the maximum profit by scheduling jobs 1 and 4. Note that there is longer schedules possible Jobs 1, 2 and 3 but the 
profit with this schedule is 20+50+100 which is less than 250.

Algorithm:

Sort the jobs by non-decreasing finish times.
For each i from 1 to n, determine the maximum value of the schedule from the subsequence of jobs[0..i]. Do this by comparing the inclusion of job[i] to the schedule
to the exclusion of job[i] to the schedule, and then taking the max. To find the profit with inclusion of job[i]. we need to find the latest job that doesn’t 
conflict with job[i]. The idea is to use Binary Search to find the latest non-conflicting job.

Time complexity: O(n * log n)
*/

struct Job {
    int start,end,profit;
    Job(int start,int end,int profit)
    {
        this->start = start;
        this->end = end;
        this->profit = profit;
    }
};

static bool mycomp(Job j1,Job j2) {
    return j1.end < j2.end;
}

// A Binary Search based function to find the latest job
// (before current job) that doesn't conflict with current
// job.  "index" is index of the current job.  This function
// returns -1 if all jobs before index conflict with it.
// The array jobs[] is sorted in increasing order of finish
// time.
int binarySearch(vector<Job> v,int index) {
    
    int low = 0,high = index - 1;
    
    while(low <= high) {
        int mid = (low + high) / 2;
        
        if(v[mid].end <= v[index].start) {
            if(v[mid + 1].end <= v[index].start) {
                low = mid + 1;
            } else {
                return mid;
            }
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    vector<Job> v;
    for(int i = 0;i < startTime.size();i++) {
        v.push_back(Job(startTime[i],endTime[i],profit[i]));
    }
    sort(v.begin(),v.end(),mycomp);
    
    int dp[startTime.size()];
    dp[0] = v[0].profit;
    
    for(int i = 1; i < startTime.size();i++) {
        dp[i] = 0;
        
        int l = binarySearch(v,i);
        if(l != -1)
            dp[i]=max(dp[i - 1],dp[l] + v[i].profit);
        else
            dp[i]=max(dp[i - 1],v[i].profit);
    }
    return dp[startTime.size() - 1];
}
