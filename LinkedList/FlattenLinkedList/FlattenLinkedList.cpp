/*

Problem statement: Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.

Constraints: 0 <= N <= 50
1 <= Mi <= 20
1 <= Element of linked list <= 10^3

Approach:
Consider last two nodes in horizontal list. Now, problem boiles down to merging this two lists. Merge these two lists using merge function of merge sort. Now merge
third list from last with the resultant list. Do this recursively and we will get the result.

*/

Node * merge(Node *a, Node *b) {
    
    if(a == NULL)
    return b;
    
    if(b == NULL)
    return a;
    
    Node * result;
    if(a->data < b->data) {
        result = a;
        result -> bottom = merge(a->bottom,b);
    } else {
        result = b;
        result -> bottom = merge(b->bottom,a);
    }
    
    result -> next = NULL;
    return result;
}
/*  Function which returns the root of the flattened linked list. */
Node *flatten(Node *root)
{
    if(root == NULL || root->next == NULL)
    return root;
    
    return merge(root, flatten(root->next));
}

