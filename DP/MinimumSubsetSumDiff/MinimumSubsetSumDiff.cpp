/*

Problem statement: Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum. 
    If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

Input:  arr[] = {1, 6, 11, 5} 
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11   

Keywords: Choice

Approach: The problem can be solved using dynamic programming when the sum of the elements is not too big. We can create a 2D array dp[n+1][sum+1] where n is a number of elements in a given set and sum is the sum of all elements. We can construct the solution in a bottom-up manner.

    The task is to divide the set into two parts. 
    We will consider the following factors for dividing it. 
    Let dp[n+1][sum+1] = {1 if some subset from 1st to i'th has a sum equal to j             0 otherwise}
        
        i ranges from {1..n}
        j ranges from {0..(sum of all elements)}  
    
    So      
        dp[n+1][sum+1]  will be 1 if 
        1) The sum j is achieved including i'th item
        2) The sum j is achieved excluding i'th item.
    
    Let sum of all the elements be S.  
    
    To find Minimum sum difference, w have to find j such 
    that Min{sum - j*2  : dp[n][j]  == 1 } 
        where j varies from 0 to sum/2
    
    The idea is, sum of S1 is j and it should be closest
    to sum/2, i.e., 2*j should be closest to sum.

Time Complexity = O(n*sum) where n is the number of elements and sum is the sum of all elements.

*/

int subsetSum(int arr[], int range, int n) {
        
    bool dp[n + 1][range + 1];
    
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    
    for(int i = 1; i <= range; i++) {
        dp[0][i] = 0;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= range; j++) {
             // If i'th element is excluded
            dp[i][j] = dp[i-1][j];
 
            // If i'th element is included
            if (arr[i-1] <= j)
                dp[i][j] |= dp[i-1][j-arr[i-1]];
        }
    }
    
    int mini = INT_MAX;
    for (int j=range/2; j>=0; j--) {
        if (dp[n][j]) {
            mini = range-2*j; // min = abs(j - i) = abs(j - (range - j))
            break;
        }
    }
    return mini;
}

int minDiffernce(int arr[], int n) { 
    int range = 0;
    for(int i = 0; i < n; i++) {
        range += arr[i];
    }
    return subsetSum(arr, range, n);
} 
