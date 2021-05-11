/*

Problem statement: Given an array of n integers. The task is to remove or delete the minimum number of elements from the array so that when the remaining
elements are placed in the same sequence order to form an increasing sorted sequence.

Examples :

Input : {5, 6, 1, 7, 4}
Output : 2
Removing 1 and 4
leaves the remaining sequence order as
5 6 7 which is a sorted sequence.

Input : {30, 40, 2, 5, 1, 7, 45, 50, 8}
Output : 4

Approach: 
-->arr be the given array.
-->n number of elements in arr.
-->len be the length of longest increasing subsequence in arr.
-->minimum number of deletions min = n - len
    
Time Complexity : O(n^2)
    
*/

/* lis() returns the length
   of the longest increasing 
   subsequence in arr[] of size n */
int lis( int arr[], int n )
{
    int result = 0;
    int lis[n];
  
    /* Initialize LIS values
    for all indexes */
    for (int i = 0; i < n; i++ )
        lis[i] = 1;
  
    /* Compute optimized LIS 
       values in bottom up manner */
    for (int i = 1; i < n; i++ )
        for (int j = 0; j < i; j++ )
            if ( arr[i] > arr[j] &&
                 lis[i] < lis[j] + 1)
            lis[i] = lis[j] + 1;
  
    /* Pick resultimum 
    of all LIS values */
    for (int i = 0; i < n; i++ )
        if (result < lis[i])
            result = lis[i];
  
    return result;
}
