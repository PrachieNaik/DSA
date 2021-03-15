/*

Problem statement: Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked 
list.

Input: K = 4, value = {{1,2,3},{4 5},{5 6},{7,8}}
Output: 1 2 3 4 5 5 6 7 8

Constraints: 1 <= K <= 10^3

Approach:
MinHeap: A Min-Heap is a complete binary tree in which the value in each internal node is smaller than or equal to the values in the children of that node. Mapping
the elements of a heap into an array is trivial: if a node is stored at index k, then its left child is stored at index 2k + 1 and its right child at index 2k + 2.

The process must start with creating a MinHeap and inserting the first element of all the k linked list. Remove the root element of Minheap and insert it in the 
output list and insert the next element from the linked list of removed element. To get the result the step must continue until there is no element in the MinHeap
left.

Time Complexity: O(nk Logk)
Auxiliary Space: O(k)

*/

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
struct compare {
    bool operator()(
        struct Node* a, struct Node* b)
    {
        return a->data > b->data;
    }
};

Node * mergeKLists(Node *arr[], int K)
{
    priority_queue<Node*,vector<Node*>,compare> pq;
   
    for(int i = 0; i < K; i++) {
       if(arr[i] != NULL)
            pq.push(arr[i]);
    }
    if (pq.empty())
        return NULL;

    struct Node *dummy = new Node(0);
    struct Node *last = dummy;
    
    while(!pq.empty()) {
        struct Node * cur = pq.top();
        pq.pop();
        
        last -> next = cur;
        last = last -> next;
        
        if(cur -> next !=NULL)
            pq.push(cur -> next);
    }
    return dummy -> next;
}

