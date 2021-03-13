/*

Problem statement: Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement 
Heap Sort.

Input: N = 5, arr[] = {4,1,3,9,7}
Output: 1 3 4 7 9
Explanation: After sorting elements using heap sort, elements will be in order as 1,3,4,7,9.

Constraints: 1 <= N <= 10^6, 1 <= arr[i] <= 10^6

Approach:

Heap Sort Algorithm for sorting in increasing order: 
1. Build a max heap from the input data. 
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1.
Finally, heapify the root of the tree. 
3. Repeat step 2 while size of heap is greater than 1.

Time Complexity: Time complexity of heapify is O(Logn). Time complexity of createAndBuildHeap() is O(n) and overall time complexity of Heap Sort is O(nLogn).

*/

 void heapify(int arr[], int n, int i)  {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)  { 
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
    // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
