/*

Problem statement: A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457 

Constraints:
1 <= N <= 10^1000

Approach 1: Reverse given linked list. For example, 1-> 9-> 9 -> 9 is converted to 9-> 9 -> 9 ->1.
    Start traversing linked list from leftmost node and add 1 to it. If there is a carry, move to the next node. Keep moving to the next node while there is a
    carry.
    Reverse modified linked list and return head.
    
    Time Complexity : O(n) 
    Auxiliary Space : O(1)
    
Approach 2: We can recursively reach the last node and forward carry to previous nodes. Recursive solution doesn’t require reversing of linked list. We can also 
    use a stack in place of recursion to temporarily hold nodes.

    // Recursively add 1 from end to beginning and returns
    // carry after all nodes are processed.
    int addWithCarry(Node* head)
    {
        // If linked list is empty, then
        // return carry
        if (head == NULL)
            return 1;
     
        // Add carry returned be next node call
        int res = head->data + addWithCarry(head->next);
     
        // Update data and return new carry
        head->data = (res) % 10;
        return (res) / 10;
    }
     
    // This function mainly uses addWithCarry().
    Node* addOne(Node* head)
    {
        // Add 1 to linked list from end to beginning
        int carry = addWithCarry(head);
     
        // If there is carry after processing all nodes,
        // then we need to add a new node to linked list
        if (carry) {
            Node* newNode = new Node;
            newNode->data = carry;
            newNode->next = head;
            return newNode; // New node becomes head now
        }
     
        return head;
    }
    Time Complexity : O(n) 
    Auxiliary Space : O(n)

Approach 3: The main focus in this question is on the digit 9 which creates all the changes otherwise for other digits we have to just increment their value by
    1 but if we change the node’s value with the value 9 it makes a carry which then has to be passed through the linked list.
    Find the last node in the linked list which is not equal to 9. Now there are three cases: 
    
    If there is no such node i.e. the value of every node is 9 then the new linked list will contain all 0s and a single 1 inserted at the head of the linked list.
    If the rightmost node which is not equal to 9 is the last node in the linked list then add 1 to this node and return the head of the linked list.
    If the node is other than the last node i.e. every node after it is equal to 9 then add 1 to the current node and change all the nodes after it to 0.
    
    Time Complexity: O(N)
    Space Complexity: O(1)

*/

// Function to add one to a number
// represented as linked list
Node* addOne(Node* head)
{
 
    // To store the last node in the linked
    // list which is not equal to 9
    Node* last = NULL;
    Node* cur = head;
 
    // Iterate till the last node
    while (cur->next != NULL) {
 
        if (cur->data != 9) {
            last = cur;
        }
        cur = cur->next;
    }
 
    // If last node is not equal to 9
    // add 1 to it and return the head
    if (cur->data != 9) {
        cur->data++;
        return head;
    }
 
    // If list is of the type 9 -> 9 -> 9 ...
    if (last == NULL) {
        last = new Node();
        last->data = 0;
        last->next = head;
        head = last;
    }
 
    // For cases when the righmost node which
    // is not equal to 9 is not the last
    // node in the linked list
    last->data++;
    last = last->next;
 
    while (last != NULL) {
        last->data = 0;
        last = last->next;
    }
 
    return head;
}
