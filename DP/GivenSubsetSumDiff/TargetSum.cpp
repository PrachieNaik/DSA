/*

Problem statement: (Target Sum Problem)
Given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

Approch: This problem can be reduced to finding two sets S1 and S2 such that the absolute difference between their sums is equal to given difference.

for example: Input = 1,2,3,4, Sum = 1
solution: 1-2-3+5 = {1+5} - {2+3}
for given difference one, find two sets.

*/

int countSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if
    // there is a subset of set[0..j-1] with sum
    // equal to i
    int subset[n + 1][sum + 1];
 
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        subset[i][0] = 1;
 
    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        subset[0][i] = 0;
 
    // Fill the subset table in botton up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            else {
                subset[i][j] = subset[i - 1][j] + subset[i - 1][j - set[i - 1]];
            }
        }
    }
 
    return subset[n][sum];
}

int minDiffernce(int arr[], int n, int diff) { 
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    // s1 - s2 = diff , s2 = sum - s1
    // s1 - (sum - s1) = diff
    // s1 = (diff + sum) / 2
    
    int toFind = abs((diff - sum)/2);
    return countSubsetSum(arr, n, toFind);
} 
