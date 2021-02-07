/*

Problem statement: Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

Sample Input: 1->2->2->4->5->6->7->8 & K = 4

Sample Output: 4 2 2 1 8 7 6 5 

Constraints: 1 <= N <= 103, 1 <= k <= N

Assumptions: Data of the node will be a positive integer.

Basic case: 1
Advance case: 2,4,7,8,9 & k = 3
Edge case: n % k != 0
No input case: NA

Approaches:

Method 1:  
Reverse the first sub-list of size k. While reversing keep track of the next node and previous node. Let the pointer to the next node be next and pointer to the previous node be prev.
Time Complexity: O(N)
Space Complexity: O(N/K)

Method 2: 
Use a stack which will store the nodes of the given linked list. Firstly, push the k elements of the linked list in the stack. Now pop elements one by one and keep track of the previously popped node. Point the next pointer of prev node to top element of stack. Repeat this process, until NULL is reached.
Time Complexity: O(N)
Space Complexity: O(K)

*/

struct node *reverse (struct node *head, int k)
{ 
    node * cur = head, *prev = NULL, *next = NULL;
    int count = k;
    while(cur!=NULL && count--) {
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    if (next != NULL)  
    head->next = reverse(next, k);  
  
    return prev;  
}
