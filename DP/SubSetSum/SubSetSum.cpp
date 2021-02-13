/*

Problem statement: Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9

Output: True  
There is a subset (4, 5) with sum 9.

Keywords: Choice, Optimize

Approaches:

Method 1: Recursion. For the recursive approach we will consider two cases. 
    
    Consider the last element and now the required sum = target sum – value of ‘last’ element and number of elements = total elements – 1
    Leave the ‘last’ element and now the required sum = target sum and number of elements = total elements – 1
    
    Complexity Analysis: The above solution may try all subsets of given set in worst case. Therefore time complexity of the above solution is exponential. 
    
Method 2: we will create a 2D array of size (arr.size() + 1) * (target + 1) of type boolean. The state DP[i][j] will be true if there exists a subset of elements from A[0….i] with sum value = ‘j’. The approach for the problem is: 

        if (A[i] > j)
        DP[i][j] = DP[i-1][j]
        else 
        DP[i][j] = DP[i-1][j] OR DP[i-1][j-A[i]]
        
        This means that if current element has value greater than ‘current sum value’ we will copy the answer for previous cases
        And if the current sum value is greater than the ‘ith’ element we will see if any of previous states have already experienced the sum=’j’ OR any previous states experienced a value ‘j – A[i]’ which will solve our purpose.
        
        Complexity Analysis: 

        Time Complexity: O(sum*n), where sum is the ‘target sum’ and ‘n’ is the size of array.
        Auxiliary Space: O(sum*n), as the size of 2-D array is sum*n. 
    
*/

// Returns true if there is a subset of set[]
// with sun equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if
    // there is a subset of set[0..j-1] with sum
    // equal to i
    bool subset[n + 1][sum + 1];
 
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;
 
    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;
 
    // Fill the subset table in botton up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j]
                               || subset[i - 1][j - set[i - 1]];
        }
    }
 
    return subset[n][sum];
}
