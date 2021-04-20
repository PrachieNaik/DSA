/*

Problem statement: Given an array of integers arr[] and a number K.You can pair two numbers of the array if the difference between them is strictly less than K.
The task is to find the maximum possible sum of such disjoint pairs. The Sum of P pairs is the sum of all 2P numbers of pairs.

Example 1:

Input  : 
arr[] = {3, 5, 10, 15, 17, 12, 9}
K = 4
Output : 
62
Explanation :
Then disjoint pairs with difference less than K are, (3, 5), (10, 12), (15, 17) max sum which we can get is 3 + 5 + 10 + 12 + 15 + 17 = 62. Note that an alternate
way to form disjoint pairs is,(3, 5), (9, 12), (15, 17) but this pairing produces less sum.


Constraints:
1 ≤ N ≤ 10^5
0 ≤ K ≤ 10^5
1 ≤ arr[i] ≤ 10^4

Time Complexity: O(N. log(N))
Auxiliary Space: O(1)

*/

// Method to return maximum sum we can get by
// finding less than K difference pairs
int maxSumPair(int arr[], int N, int k)
{
    int maxSum = 0;
 
    // Sort elements to ensure every i and i-1 is closest
    // possible pair
    sort(arr, arr + N);
 
    // To get maximum possible sum,
    // iterate from largest to
    // smallest, giving larger
    // numbers priority over smaller
    // numbers.
    for (int i = N - 1; i > 0; --i)
    {
        // Case I: Diff of arr[i] and arr[i-1]
        //  is less then K,add to maxSum      
        // Case II: Diff between arr[i] and arr[i-1] is not
        // less then K, move to next i since with
        // sorting we know, arr[i]-arr[i-1] <
        // rr[i]-arr[i-2] and so on.
        if (arr[i] - arr[i - 1] < k)
        {
            // Assuming only positive numbers.
            maxSum += arr[i];
            maxSum += arr[i - 1];
 
            // When a match is found skip this pair
            --i;
        }
    }
 
    return maxSum;
}
