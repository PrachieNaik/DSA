/*

Problem statement: A binary heap is a Binary Tree with the following properties:
1) It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible). This property of 
Binary Heap makes them suitable to be stored in an array.

2) A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at the root must be minimum among all keys present in Binary Heap. The same property
must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to MinHeap.

You are given an empty Binary Min Heap and some queries and your task is to implement the three methods insertKey,  deleteKey,  and extractMin on the Binary Min 
Heap and call them as per the query given below:
1) 1  x  (a query of this type means to insert an element in the min-heap with value x )
2) 2  x  (a query of this type means to remove an element at position x from the min-heap)
3) 3  (a query like this removes the min element from the min-heap and prints it ).

Constraints: 1 <= Q <= 10^4, 1 <= x <= 10^4

Time Complexity: O(Q*Log(size of Heap) ).
Auxiliary Space: O(1).

*/

/* Removes min element from min heap and returns it */
int MinHeap::extractMin() {
    if(heap_size <= 0)
    return -1;
    
    if(heap_size == 1) {
        heap_size--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    harr[heap_size - 1] = root;
    heap_size--;
    MinHeapify(0);
    
    return root;
}

/* Removes element from position x in the min heap  */
void MinHeap::deleteKey(int i) {
    if(heap_size<=i)
        return;
    decreaseKey(i,INT_MIN);
    extractMin();
}

/* Inserts an element at position x into the min heap*/
void MinHeap::insertKey(int k) {
    if(heap_size == capacity) {
        return;
    }
    harr[heap_size] = k;
    heap_size++;
    int i = heap_size - 1;
    
    while(i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i],&harr[parent(i)]);
        i = parent(i);
    }
}

// Decrease Key operation, helps in deleting key from heap
void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}
