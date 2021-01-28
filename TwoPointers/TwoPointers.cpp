/*

Given a sorted array A (sorted in ascending order), having N integers(can have negative numbers too), find if there exists any pair of elements (A[i], A[j]) such that their sum is equal to X.

Method: Two pointers is really an easy and effective technique which is typically used for searching pairs in a sorted array.

How does this work? 
The algorithm basically uses the fact that the input array is sorted. We start the sum of extreme values (smallest and largest) and conditionally move both pointers. We move left pointer i when the sum of A[i] and A[j] is less than X. We do not miss any pair because the sum is already smaller than X. Same logic applies for right pointer j.

Time Complexity: O(n), Space Complexity: O(1)

*/


#include <iostream>
using namespace std;

// Two pointer technique based solution to find
// if there is a pair in A[0..N-1] with a given sum.
int isPairSum(int A[], int N, int X)
{
	// represents first pointer
	int i = 0;

	// represents second pointer
	int j = N - 1;

	while (i < j) {

		// If we find a pair
		if (A[i] + A[j] == X)
			return 1;

		// If sum of elements at current
		// pointers is less, we move towards
		// higher values by doing i++
		else if (A[i] + A[j] < X)
			i++;

		// If sum of elements at current
		// pointers is more, we move towards
		// lower values by doing j--
		else
			j--;
	}
	return 0;
}

// Driver code
int main()
{
	// array declaration
	int arr[] = { 3, 5, 9, 2, 8, 10, 11 };
	
	// value to search
	int val = 17;
	
	// size of the array
	int arrSize = *(&arr + 1) - arr;
	
	// Function call
	cout << (bool)isPairSum(arr, arrSize, val);

	return 0;
}



