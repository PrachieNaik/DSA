/*

Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Constraints: 1 <= N <= 10^5

Approaches:

Method 1:
    
    1) Get the middle of the linked list. 
    2) Reverse the second half of the linked list. 
    3) Check if the first half and second half are identical. 
    4) Construct the original linked list by reversing the second half again and attaching it back to the first half

    Time complexity:O(n).
    Auxiliary Space:O(1).

*/

Node * rev(Node *head) {
    Node * cur = head, *prev = NULL, *next = NULL;
    while(cur!=NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    //Your code here
    
    Node * slow = head;
    Node * fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = head;
    slow = rev(slow);
    while(slow!=NULL) {
        if(slow -> data != fast->data) {
            return 0;
        }
        fast = fast->next;
        slow = slow->next;
    }
    return 1;
} 

