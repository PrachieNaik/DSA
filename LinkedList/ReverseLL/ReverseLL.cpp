/*

Problem statement: Given pointer to the head node of a linked list, the task is to reverse the linked list. 

Sample Input: 1->2->3->4->NULL 

Sample Output: 4->3->2->1->NULL

Constraints: 1 <= N <= 10^4

Assumptions: Data of the node will be a positive integer.

Basic case: 1
Advance case: 1->2->3->4->5
Edge case: Even length
No input case: NA

Approaches:

Recursive:  
    1) Divide the list in two parts - first node and rest of the linked list.
    2) Call reverse for the rest of the linked list.
    3) Link rest to first.
    4) Fix head pointer
    
    Node* reverse(Node* node)
    {
        if (node == NULL)
            return NULL;
        if (node->next == NULL) {
            head = node;
            return node;
        }
        Node* node1 = reverse(node->next);
        node1->next = node;
        node->next = NULL;
        return node;
    }
    
    Time Complexity: O(n) 
    Space Complexity: O(1)

Iterative: 
    Initialize three pointers prev as NULL, curr as head and next as NULL.
    Iterate through the linked list. In loop, do following. 
    // Before changing next of current, 
    // store next node 
    next = curr->next
    // Now change next of current 
    // This is where actual reversing happens 
    curr->next = prev 
    // Move prev and curr one step forward 
    prev = curr 
    curr = next
    Time Complexity: O(N)
    Space Complexity: O(1)

*/

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *reverseList(struct Node *head);

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        head = reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}

// Should reverse list and return new head.
struct Node* reverseList(struct Node *head)
{
    struct Node * prev = NULL, *cur = head, *next = NULL;
    while(cur!=NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
    
}
