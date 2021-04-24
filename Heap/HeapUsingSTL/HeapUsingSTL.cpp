/*

How to implement Min/Max Heap using STL?

In C++ STL, there is priority_queue that can directly be used to implement Max Heap. 

*/

int main ()
{
    // Creates a max heap
    priority_queue <int> pq;
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(30);
    pq.push(20);
 
    // One by one extract items from max heap
    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
 
    return 0;
}

/*

priority_queue supports a constructor that requires two extra arguments to make it min-heap. 
 
priority_queue <Type, vector<Type>, ComparisonType > min_heap;

`The third parameter, ‘Comparison Type’ can either be a function or factor (aka function object) that must have bool as return-type and must have 2 arguments.

*/

int main ()
{
    // Creates a min heap
    priority_queue <int, vector<int>, greater<int> > pq;
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(30);
    pq.push(20);
 
    // One by one extract items from min heap
    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
 
    return 0;
}

/*

Another method for making min-heap using default priority_queue:

This is frequently used in Competitive Programming. We first multiply all elements with (-1). Then we create a max heap (max heap is the default for priority queue).
When we access the data and want to print it we simply multiply those elements with (-1) again.

*/

int main()
{
    // data
    int arr[] = { 25, 7, 9, 15, 20, 36, 50 };
   
      // default priority_queue using max-heap
    priority_queue<int> pq;
   
      // size of the array
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // multiply -1 with all elements while
    // inserting
    for (int i = 0; i < n; i++) {
        pq.push((-1) * arr[i]);
    }
 
    // multiply all elements with -1 while
    // retrive the elements
    while (!pq.empty()) {
        cout << (pq.top()) * (-1) << " ";
        pq.pop();
    }
 
    return 0;
}
