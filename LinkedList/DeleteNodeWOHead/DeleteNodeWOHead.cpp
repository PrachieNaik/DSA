/*

Problem statement: You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes. The task is to delete the node. Pointer/ reference to head node is not given. 
Note: No head reference is given to you. It is guaranteed that the node to be deleted is not a tail node in the linked list.

Approaches:

Method 1: copy the data from the next node to the node to be deleted and delete the next node. Something like following.

    // Find next node using next pointer
    struct Node *temp  = node_ptr->next;

    // Copy data of next node to this node
    node_ptr->data  = temp->data;

    // Unlink next node
    node_ptr->next  = temp->next;

    // Delete next node
    free(temp);
    
	Time Complexity: O(1)
	Space Complexity: O(1)

*/

// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
// node: reference to the node which is to be deleted
void deleteNode(Node *node)
{
   // Your code here
   node -> data = node -> next -> data;
   Node * temp = node-> next -> next;
   delete (node-> next);
   node-> next = temp;
}
