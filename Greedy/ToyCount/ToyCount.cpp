/*

Problem statement: Given an array arr[ ] of length N consisting cost of N toys and an integer K depicting the amount with you. Your task is to find maximum number 
of toys you can buy with K amount.

Input: N = 7 , K = 50, arr[] = {1, 12, 5, 111, 200, 1000, 10}
Output: 4
Explaination: The costs of the toys you can buy are 1, 12, 5 and 10.

Constraints: 1 ≤ N ≤ 10^5, 1 ≤ K, arr[i] ≤ 10^9

Approach:

The idea to solve this problem is to first sort the cost array in ascending order. This will arrange the toys in increasing order of the cost. Now iterate over the 
cost array and keep calculating the sum of costs until the sum is less than or equal to K. Finally return the number of toys used to calculate the sum which is just
less than or equals to K.

Time Complexity : O(N * logN), where N is the size of cost array.

*/

int toyCount(int N, int K, vector<int> arr)
{
    sort(arr.begin(),arr.end());
    int ans = 0;
    for(int i = 0; i < N;i++) {
        if(K - arr[i] >= 0) {
            ans++;
            K -= arr[i];
        }
        else
        break;
       
    }
    return ans;
}
