/**
Given an unsorted array of nonnegative integers, WAP to find a continuous subarray which adds to a given number.



Method 1: A simple solution is to consider all subarrays one by one and check the sum of every subarray. Run two loops: the outer loop picks a starting 
point I and the inner loop tries all subarrays starting from i.
Time Complexity: O(n^2) in worst case. Space Complexity: O(1).


Method 2: If all the elements of the array are positive. If a subarray has sum greater than the given sum then there is no possibility that adding elements
to the current subarray the sum will be x (given sum). Idea is to use a similar approach to a sliding window. Start with an empty subarray, add elements to
the subarray until the sum is less than x. If the sum is greater than x, remove elements from the start of the current subarray.

**/

#include <iostream>
using namespace std;

/* Returns true if the there is a subarray of 
arr[] with a sum equal to 'sum' otherwise 
returns false. Also, prints the result */
int subArraySum(int arr[], int n, int sum)
{
    /* Initialize curr_sum as value of 
    first element and starting point as 0 */
    int curr_sum = arr[0], start = 0, i;

    /* Add elements one by one to curr_sum and 
    if the curr_sum exceeds the sum,
    then remove starting element */
    for (i = 1; i <= n; i++) {
        // If curr_sum exceeds the sum,
        // then remove the starting elements
        while (curr_sum > sum && start < i - 1) {
            curr_sum = curr_sum - arr[start];
            start++;
        }

        // If curr_sum becomes equal to sum,
        // then return true
        if (curr_sum == sum) {
            cout << "Sum found between indexes "
                 << start << " and " << i - 1;
            return 1;
        }

        // Add this element to curr_sum
        if (i < n)
            curr_sum = curr_sum + arr[i];
    }

    // If we reach here, then no subarray
    cout << "No subarray found";
    return 0;
}

// Driver Code
int main()
{
    int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 23;
    subArraySum(arr, n, sum);
    return 0;
}

// time complexity: O(N), auxiliary space complexity O(1)
