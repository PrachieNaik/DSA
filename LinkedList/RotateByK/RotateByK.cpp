/*

Problem statement: Given a singly linked list of size N. The task is to rotate the linked list counter-clockwise by k nodes, where k is a given positive 
integer smaller than or equal to length of the linked list.

Sample Input: 1,2,3,4,5,6,7,8 & K = 4

Sample Output: 5 6 7 8 1 2 3 4

Constraints: 1 <= N <= 103, 1 <= k <= N

Assumptions: Data of the node will be a positive integer.

Basic case: 1
Advance case: 2,4,7,8,9 & k = 3
Edge case: Even length
No input case: NA

Approaches:

Method 1:  
To rotate a linked list by k, we can first make the linked list circular and then moving k-1 steps forward from head node, making it null and make kth 
node as head.
Time Complexity: O(N)
Space Complexity: O(1)

Method 2: 
To rotate the linked list, we need to change next of kth node to NULL, next of the last node to the previous head node, and finally, change head to (k+1)th
node. So we need to get hold of three nodes: kth node, (k+1)th node and last node. 
Traverse the list from the beginning and stop at kth node. Store pointer to kth node. We can get (k+1)th node using kthNode->next. Keep traversing till the
end and store pointer to last node also. Finally, change pointers as stated above.
Time Complexity: O(N)
Space Complexity: O(1)

*/

Node* rotate(Node* head, int k)
{
    Node * cur = head,* kth = NULL;
    while(--k) {
        cur = cur ->next;
    }
    kth = cur;
    while(cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = head;
    head = kth->next;
    kth -> next = NULL;
    
    return head;
}
