/*

Problem statement:Given an array of N elements. The task is to build a Binary Heap from the given array. The heap can be either Max Heap or Min Heap.

Example:

Input: arr[] = {4, 10, 3, 5, 1}
Output: Corresponding Max-Heap:
       10
     /   \
    5     3
   /  \
  4    1

Input: arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}
Output: Corresponding Max-Heap:
                 17
              /      \
            15         13
          /    \      /  \
         9      6    5   10
        / \    /  \
       4   8  3    1

Simple Approach: Suppose, we need to build a Max-Heap from the above-given array elements. It can be clearly seen that the above complete binary tree formed does
not follow the Heap property. So, the idea is to heapify the complete binary tree formed from the array in reverse level order following a top-down approach.

    That is first heapify, the last node in level order traversal of the tree, then heapify the second last node and so on.

    Time Complexity: Heapify a single node takes O(log N) time complexity where N is the total number of Nodes. Therefore, building the entire Heap will take N 
    heapify operations and the total time complexity will be O(N*logN).
    
Optimized Approach: The above approach can be optimized by observing the fact that the leaf nodes need not to be heapified as they already follow the heap
property. Also, the array representation of the complete binary tree contains the level order traversal of the tree.

    So the idea is to find the position of the last non-leaf node and perform the heapify operation of each non-leaf node in reverse level order.

    Last non-leaf node = parent of last-node.
    or, Last non-leaf node = parent of node at (n-1)th index.
    or, Last non-leaf node = Node at index ((n-1) - 1)/2. = (n/2) - 1.
   
    Time Complexity: O(n)
    Space Complexity: O(n)

*/

// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
void heapify(int arr[], int n, int i)
{
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
  
// Function to build a Max-Heap from the given array
void buildHeap(int arr[], int n)
{
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;
  
    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}
