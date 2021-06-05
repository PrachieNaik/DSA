/*
QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many
different versions of quickSort that pick pivot in different ways. 

Always pick first element as pivot.
Always pick last element as pivot (implemented below)
Pick a random element as pivot.
Pick median as pivot.

The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot, put x at its correct position
in sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x. All this should be done
in linear time.

Partition Algorithm 
There can be many ways to do partition, following pseudo code adopts the method given in CLRS book. The logic is simple, we start from the leftmost
element and keep track of index of smaller (or equal to) elements as i. While traversing, if we find a smaller element, we swap current element with
arr[i]. Otherwise we ignore current element. 

Analysis of QuickSort 
Time taken by QuickSort, in general, can be written as following. 

 T(n) = T(k) + T(n-k-1) + \theta(n)
The first two terms are for two recursive calls, the last term is for the partition process. k is the number of elements which are smaller than pivot. 
The time taken by QuickSort depends upon the input array and partition strategy. Following are three cases.

Worst Case: The worst case occurs when the partition process always picks greatest or smallest element as pivot. If we consider above partition strategy
where last element is always picked as pivot, the worst case would occur when the array is already sorted in increasing or decreasing order. Following 
is recurrence for worst case. 

 T(n) = T(0) + T(n-1) + \theta(n)
which is equivalent to  
T(n) = T(n-1) + \theta(n)
The solution of above recurrence is  \theta(n2).

Best Case: The best case occurs when the partition process always picks the middle element as pivot. Following is recurrence for best case. 

 T(n) = 2T(n/2) + \theta(n)
The solution of above recurrence is \theta(nLogn). It can be solved using case 2 of Master Theorem.

Average Case: 
To do average case analysis, we need to consider all possible permutation of array and calculate time taken by every permutation which doesn’t look easy. 
We can get an idea of average case by considering the case when partition puts O(n/9) elements in one set and O(9n/10) elements in other set. Following
is recurrence for this case. 

 T(n) = T(n/9) + T(9n/10) + \theta(n)
Solution of above recurrence is also O(nLogn)

Although the worst case time complexity of QuickSort is O(n2) which is more than many other sorting algorithms like Merge Sort and Heap Sort, QuickSort
is faster in practice, because its inner loop can be efficiently implemented on most architectures, and in most real-world data. QuickSort can be 
implemented in different ways by changing the choice of pivot, so that the worst case rarely occurs for a given type of data. However, merge sort is 
generally considered better when data is huge and stored in external storage. 

Is QuickSort stable? 
The default implementation is not stable. However any sorting algorithm can be made stable by considering indexes as comparison parameter. 

Is QuickSort In-place? 
As per the broad definition of in-place algorithm it qualifies as an in-place sorting algorithm as it uses extra space only for storing recursive function
calls but not for manipulating the input. 

*/

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
