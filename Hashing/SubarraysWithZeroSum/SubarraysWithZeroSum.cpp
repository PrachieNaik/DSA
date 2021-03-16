/*

Problem statement: You are given an array A[] of size N. Find the total count of sub-arrays having their sum equal to 0.

Input: N = 6, A[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are [0], [0], [0], [0], [0,0], and [0,0].

Constraints: 1<= N <= 107, -1010 <= Ai <= 1010

Approach: 
Maintain sum of elements encountered so far in a variable (say sum).
If current sum is 0, we found a subarray starting from index 0 and ending at index current index
Check if current sum exists in the hash table or not.
If current sum already exists in the hash table then it indicates that this sum was the sum of some sub-array elements arr[0]…arr[i] and now the same sum is
obtained for the current sub-array arr[0]…arr[j] which means that the sum of the sub-array arr[i+1]…arr[j] must be 0.
Insert current sum into the hash table

*/

ll findSubarray(vector<ll> arr, int n ) {
    unordered_map<ll,vector<int>> aux;
    ll ans = 0;
    ll sum = 0;
    for(int i = 0;i < n;i++) {
        sum += arr[i];
        if(sum == 0) {
            ans++;
        }
        if(aux.find(sum) != aux.end()) {
            ans += aux[sum].size();
        }
        aux[sum].push_back(i);
    }
    return ans;
}
