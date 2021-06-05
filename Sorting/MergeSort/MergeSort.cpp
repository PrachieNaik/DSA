/*
This is a C++ program to sort the given data using Merge Sort.

Problem Description
1. Merge-sort is based on an algorithmic design pattern called divide-and-conquer.
2. It forms tree structure.
3. The height of the tree will be log(n).
4. we merge n element at every level of the tree.
5. The time complexity of this algorithm is O(n*log(n)).

Problem Solution
1. Split the data into two equal half until we get at most one element in both half.
2. Merge Both into one making sure the resulting sequence is sorted.
3. Recursively split them and merge on the basis of constraint given in step 1.
4. Display the result.
5. Exit.

1. Space Complexity
Auxiliary Space: O(n)
Sorting In Place: No
Algorithm : Divide and Conquer

2. Time Complexity
Merge Sort is a recursive algorithm and time complexity can be expressed as following recurrence relation.

T(n) = 2T(n/2) + O(n)

The solution of the above recurrence is O(nLogn). The list of size N is divided into a max of Logn parts, and the merging of all sublists into a single
list takes O(N) time, the worst-case run time of this algorithm is O(nLogn)

Best Case Time Complexity: O(n*log n)

Worst Case Time Complexity: O(n*log n)

Average Time Complexity: O(n*log n)

The time complexity of MergeSort is O(n*Log n) in all the 3 cases (worst, average and best) as the mergesort always divides the array into two halves and
takes linear time to merge two halves.

*/

// A function to merge the two half into a sorted data.
void Merge(int *a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
 
// A function to split array into two parts.
void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
 
		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}
