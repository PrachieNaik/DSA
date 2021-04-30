/*

Problem statement: Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

Approaches:

Method 1: The idea is very basic run a nested loop, the outer loop which will mark the starting point of the subarray of length k, the inner loop will run from the
starting index to index+k, k elements from starting index and print the maximum element among these k elements. 

    Complexity Analysis: 
    
    Time Complexity: O(N * K). 
    The outer loop runs n-k+1 times and the inner loop runs k times for every iteration of outer loop. So time complexity is O((n-k+1)*k) which can also be written
    as O(N * K).
    
    Space Complexity: O(1). 
    No extra space is required.
    
Method 2: This method uses Max-Heap to solve the above problem. The elements of the current window will be stored in the Max-Heap and the maximum element or the 
root will be printed in each iteration. Max-heap is a suitable data structure as it provides constant-time retrieval and logarithmic time removal of both the 
minimum and maximum elements in it, i.e. it takes constant time to find the maximum element and insertion and deletion takes log n time. 

    Algorithm: 

    1. Pick first k elements and create a max heap of size k.
    2. Perform heapify and print the root element.
    3. Store the next and last element from the array
    4. Run a loop from k – 1 to n 
       a. Replace the value of element which is got out of the window with new element which came inside the window.
       b. Perform heapify.
       c. Print the root of the Heap.
    
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(int i = 0; i < k - 1;i++) {
            pq.push({arr[i],i});
        }
        for(int i = k - 1; i < n;i++){
            pq.push({arr[i],i});
            while(!pq.empty() && pq.top().second <= i-k) {
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
    
    Complexity Analysis: 

    Time Complexity: O(n * k). 
    The time complexity of steps 4(a) is O(k), 4(b) is O(Log(k)) and it is in a loop that runs (n – k + 1) times. Hence, the time complexity of the complete 
    algorithm is O((k + Log(k)) * n) i.e. O(n * k).
    
    Space Complexity: O(k). 
    To store the elements in Heap O(k) space is used.

Method 3: This method uses Deque to solve the above problem. Create a Deque, Qi of capacity k, that stores only useful elements of current window of k elements. 
An element is useful if it is in current window and is greater than all other elements on right side of it in current window. Process all array elements one by one
and maintain Qi to contain useful elements of current window and these useful elements are maintained in sorted order. The element at front of the Qi is the 
largest and element at rear/back of Qi is the smallest of current window.

    Algorithm: 
    1. Create a deque to store k elements.
    2. Run a loop and insert first k elements in the deque. Before inserting the element, check if the element at the back of the queue is smaller than the current 
        element , if it is so remove the element from the back of the deque, until all elements left in the deque are greater than the current element. 
        Then insert the current element, at the back of the deque.
    3. Now, run a loop from k to end of the array.
    4. Print the front element of the deque.
    5. Remove the element from the front of the queue if they are out of the current window.
    6. Insert the next element in the deque. Before inserting the element, check if the element at the back of the queue is smaller than the current element , 
        if it is so remove the element from the back of the deque, until all elements left in the deque are greater than the current element. 
        Then insert the current element, at the back of the deque.
    7. Print the maximum element of the last window.

    Complexity Analysis: 
    
    Time Complexity: O(n). 
    It seems more than O(n) at first look. It can be observed that every element of array is added and removed at most once. So there are total 2n operations.
    
    Auxiliary Space: O(k). 
    Elements stored in the dequeue take O(k) space.
    
*/

// A Dequeue (Double ended queue) based method for printing maximum element of all subarrays of size k
void printKMax(int arr[], int n, int k)
{
     
    // Create a Double Ended Queue, Qi that will store indexes of array elements The queue will store indexes of useful elements in every window and it will 
    //maintain decreasing order of values from front to rear in Qi, i.e.,arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order
    std::deque<int> Qi(k);
 
    /* Process first k (or first window) elements of array */
    int i;
    for (i = 0; i < k; ++i) 
    {
        // For every element, the previous smaller elements are useless so remove them from Qi
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) {
            // Remove from rear
            Qi.pop_back();
        }
        // Add new element at rear of queue
        Qi.push_back(i);
    }
 
    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for (; i < n; ++i) 
    {
     
        // The element at the front of the queue is the largest element of previous window, so print it
        cout << arr[Qi.front()] << " ";
 
        // Remove the elements which are out of this window
        while ((!Qi.empty()) && Qi.front() <= i - k) {
            // Remove from front of queue
            Qi.pop_front(); 
        }
        // Remove all elements smaller than the currently being added element (remove useless elements)
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) {
            Qi.pop_back();
        }
        // Add current element at the rear of Qi
        Qi.push_back(i);
    }
 
    // Print the maximum element of last window
    cout << arr[Qi.front()];
}
