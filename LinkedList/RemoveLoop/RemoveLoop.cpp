/*

Problem statement: You are given a linked list of N nodes. Remove the loop from the linked list, if present. 

Constraints: 1 <= N <= 10^4

Approaches:

Brute Force: (Check one by one) We know that Floyd’s Cycle detection algorithm terminates when fast and slow pointers meet at a common point. We also
know that this common point is one of the loop nodes (2 or 3 or 4 or 5 in the above diagram). Store the address of this in a pointer variable say ptr2. 
After that start from the head of the Linked List and check for nodes one by one if they are reachable from ptr2. Whenever we find a node that is reachable,
we know that this node is the starting node of the loop in Linked List and we can get the pointer to the previous of this node.

	Time Complexity: O(N*C)
	Space Complexity: O(1)

Optimized: After detecting the loop, if we start slow pointer from head and move both slow and fast pointers at same speed until fast don’t meet, they would
meet at the beginning of the loop.

How does this work? 

Let slow and fast meet at some point after Floyd’s Cycle finding algorithm. 
Let M = distance to the first node of cycle from head, 
N = length of cycle, 
k = distance of point from starting point where slow and fast meet.

Distance traveled by fast pointer = 2 * (Distance traveled 
                                         by slow pointer)

(m + n*x + k) = 2*(m + n*y + k)

Note that before meeting the point shown above, fast
was moving at twice speed.

x -->  Number of complete cyclic rounds made by 
       fast pointer before they meet first time

y -->  Number of complete cyclic rounds made by 
       slow pointer before they meet first time
       
From above equation, we can conclude below 

    m + k = (x-2y)*n

Which means m+k is a multiple of n. 
Thus we can write, m + k = i*n or m = i*n - k.
Hence, distance moved by slow pointer: m, is equal to distance moved by fast pointer: i*n - k or (i-1)*n + n - k (cover the loop completely i-1 times and 
start from n-k).

So if we start moving both pointers again at same speed such that one pointer (say slow) begins from head node of linked list and other pointer (say fast)
begins from meeting point. When slow pointer reaches beginning of loop (has made m steps), fast pointer would have made also moved m steps as they are now
moving same pace. Since m+k is a multiple of n and fast starts from k, they would meet at the beginning. Can they meet before also? No because slow pointer 
enters the cycle first time after m steps. 
       
    Time Complexity: O(N)
    Space Complexity: O(1)

*/

void detectAndRemoveLoop(Node* head)
{
    // If list is empty or has only one node
    // without loop
    if (head == NULL || head->next == NULL)
        return;
 
    Node *slow = head, *fast = head;
 
    // Move slow and fast 1 and 2 steps
    // ahead respectively.
    slow = slow->next;
    fast = fast->next->next;
 
    // Search for loop using slow and
    // fast pointers
    while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
 
    /* If loop exists */
    if (slow == fast) 
    {
        slow = head;
           
        // this check is needed when slow 
        // and fast both meet at the head of the LL
          // eg: 1->2->3->4->5 and then 
        // 5->next = 1 i.e the head of the LL
          if(slow == fast) {
              while(fast->next != slow) fast = fast->next;
        }
          else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
 
        /* since fast->next is the looping point */
        fast->next = NULL; /* remove loop */
    }
}
