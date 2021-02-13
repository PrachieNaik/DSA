/*

Problem statement: Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is equal to given difference. 
    If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) equal to given difference.

Input:  arr[] = {1, 6, 11, 5} , diff = 1
Output: 2
Explanation:

Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11   
diff = 1

Subset1 = {5, 6}, sum of Subset1 = 11
Subset2 = {1, 11}, sum of Subset2 = 12 
diff = 1

Approach: This problem can be reduced to find the number of subsets with sum equal to X.
    s1 - s2 = diff , s2 = sum - s1
    s1 - (sum - s1) = diff
    s1 = (diff + sum) / 2
Count the number of subsets whose sum is s1.

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

int minDiffernce(int arr[], int n) { 
    int sum = 0;
    int diff = 1;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    // s1 - s2 = diff , s2 = sum - s1
    // s1 - (sum - s1) = diff
    // s1 = (diff + sum) / 2
    
    int toFind = abs((diff - sum)/2);
    return countSubsetSum(arr, n, toFind);
} 
