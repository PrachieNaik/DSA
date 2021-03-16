/*

Problem statement: Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 
Input: N = 7, a[] = {2,6,1,9,4,5,3}
Output: 6
Explanation: The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6  numbers form the longest consecutive subsquence.

Constraints: 1 <= N <= 10^5, 0 <= a[i] <= 10^5

Approach: 
1. Create an empty hash.
2. Insert all array elements to hash.
3. Do following for every element arr[i]
4. Check if this element is the starting point of a subsequence. To check this, simply look for arr[i] - 1 in the hash, if not found, then this is the first element a subsequence.
5. If this element is the first element, then count the number of elements in the consecutive starting with this element. Iterate from arr[i] + 1 till the last element that can be found.
6. If the count is more than the previous longest subsequence found, then update this.

Time Complexity: O(N).
Auxiliary Space: O(N).

*/

int findLongestConseqSubseq(int arr[], int N)
{
    unordered_set<int> s;
    int ans = 0;
    for(int i = 0;i < N;i++) {
        s.insert(arr[i]);
    }
    for(int i = 0;i < N;i++) {
        if(s.find(arr[i]-1) == s.end()) {
            int j = arr[i];
            while(s.find(j) != s.end()) {
                j++;
            }
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}
