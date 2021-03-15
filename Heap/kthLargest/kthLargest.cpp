/*

Problem statement: Given an input stream arr[] of n integers, find the kth largest element for each element in the stream.

Input: k = 4, n = 6, arr[] = {1, 2, 3, 4, 5, 6}
Output: -1 -1 -1 1 2 3

Explanation:
k = 4
For 1, the 4th largest element doesn't
exist so we print -1.
For 2, the 4th largest element doesn't
exist so we print -1.
For 3, the 4th largest element doesn't
exist so we print -1.
For 4, the 4th largest element is 1.
For 5, the 4th largest element is 2.
for 6, the 4th largest element is 3.

Constraints: 1 ≤ k ≤ n ≤ 10^5, 1 ≤ arr[i] ≤ 10^5

Time Complexity: O(nlogk)
Auxiliary Space: O(n)

*/

vector<int> kthLargest(int k, int arr[], int n) {
    priority_queue<int,vector<int>,greater<int>> q;
    vector<int> ans;
    for(int i = 0; i < n;i++) {
        if(q.size() < k) {
            q.push(arr[i]);
            if(q.size() == k) {
                ans.push_back(q.top());
            } else {
                ans.push_back(-1);
            }
        } else {
            if(q.top() < arr[i]) {
                q.pop();
                q.push(arr[i]);
            }
            ans.push_back(q.top());
        }
    }
    return ans;
}
