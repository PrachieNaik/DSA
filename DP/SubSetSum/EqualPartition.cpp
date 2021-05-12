/*

Problem statement: Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Input: N = 4
arr = {1, 5, 11, 5}

Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.

Keywords: Choice, Subset sum

Approach: Find the sum of all element in the array. If the sum is odd, we can't divide the array in two parts with same sum. If the sum is even, divide it by two 
and then try to find subset with that sum. Problem is reduced to subset sum.

Time complexity:  O(n * sum)
Space complexity: O(n)

*/

bool isSubsetSum(int arr[], int n, int sum) 
{ 
    // The value of subset[i%2][j] will be true  
    // if there exists a subset of sum j in  
    // arr[0, 1, ...., i-1] 
    bool subset[2][sum + 1]; 
  
    for (int i = 0; i <= n; i++) { 
        for (int j = 0; j <= sum; j++) { 
  
            // A subset with sum 0 is always possible  
            if (j == 0) {
                subset[i % 2][j] = true;  
            }
            // If there exists no element no sum  
            // is possible  
            else if (i == 0) {
                subset[i % 2][j] = false;  
            }
            else if (arr[i - 1] <= j) {
                subset[i % 2][j] = subset[(i + 1) % 2] [j - arr[i - 1]] ||
                subset[(i + 1) % 2][j]; 
            }
            else {
                subset[i % 2][j] = subset[(i + 1) % 2][j]; 
            }
        } 
    } 
  
    return subset[n % 2][sum]; 
} 

int equalPartition(int N, int arr[])
{
    int sum = 0;
    for(int i = 0; i < N;i++) {
        sum += arr[i];
    }
    if(sum % 2 != 0)
    return 0;
    
    sum = sum / 2;
    return equalPartitionUtil(arr,N,sum);
}
