/*

Problem statement: Given a Linked List and a number n, write a function that returns the value at the n’th node from the end of the Linked List.

Approaches:

Method 1 (Use length of linked list) 
1) Calculate the length of Linked List. Let the length be len. 
2) Print the (len – n + 1)th node from the beginning of the Linked List. 
Double pointer concept : First pointer is used to store the address of the variable and second pointer used to store the address of the first pointer. If we wish to change the value of a variable by a function, we pass pointer to it. And if we wish to change value of a pointer (i. e., it should start pointing to something else), we pass pointer to a pointer.
Time complexity: O(n) 
Auxiliary Space:  O(1)

Method 2 (Use two pointers) 
Maintain two pointers – reference pointer and main pointer. Initialize both reference and main pointers to head. First, move the reference pointer to n nodes from head. Now move both pointers one by one until the reference pointer reaches the end. Now the main pointer will point to nth node from the end. Return the main pointer.
Time complexity : O( n ) 
Auxiliary Space:  O(1)


*/

int getNthFromLast(Node *head, int n)
{
       Node * fast = head;
       while(n--) {
           if(fast == NULL)
           return -1;
           fast = fast->next;
       }
       Node * slow = head;
       while(fast!=NULL) {
           slow = slow ->next;
           fast = fast -> next;
       }
       return slow->data;
}
