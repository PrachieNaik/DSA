/*

Problem statement: Given a linked list of N nodes. The task is to check if the the linked list has a loop. Linked list can contain self loop.

Approaches:

Method 1: Hashing Approach: 
Traverse the list one by one and keep putting the node addresses in a Hash Table. At any point, if NULL is reached then return false and if next of current node points to any of the previously stored nodes in Hash then return true. 
Time complexity: O(n). 
Only one traversal of the loop is needed.
Auxiliary Space: O(n). 
n is the space required to store the value in hashmap.

Method 2: This solution requires modifications to the basic linked list data structure. 

Have a visited flag with each node.
Traverse the linked list and keep marking visited nodes.
If you see a visited node again then there is a loop. This solution works in O(n) but requires additional information with each node.
A variation of this solution that doesn’t require modification to basic data structure can be implemented using a hash, just store the addresses of visited nodes in a hash and if you see an address that already exists in hash then there is a loop.
Time complexity : O( n ) 
Auxiliary Space:  O(1)

Method 3:
Marking visited nodes without modifying the linked list data structure 
In this method, a temporary node is created. The next pointer of each node that is traversed is made to point to this temporary node. This way we are using the next pointer of a node as a flag to indicate whether the node has been traversed or not. Every node is checked to see if the next is pointing to a temporary node or not. In the case of the first node of the loop, the second time we traverse it this condition will be true, hence we find that loop exists. If we come across a node that points to null then loop doesn’t exist.
Time Complexity: O(n) 
Auxiliary Space: O(1)

Method 4:
In this method, two pointers are created, first (always points to head) and last. Each time last pointer moves we calculate no of nodes in between first and last and check whether current no of nodes > previous no of nodes, if yes we proceed by moving last pointer else it means we’ve reached the end of the loop, so we return output accordingly.
Time Complexity: O(n^2) 
Auxiliary Space: O(1)

Method 3: Floyd’s Cycle-Finding Algorithm 
Traverse linked list using two pointers.
Move one pointer(slow_p) by one and another pointer(fast_p) by two.
If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have a loop.
Time Complexity: O(n) 
Auxiliary Space: O(1)

*/

int intersectPoint(Node* head1, Node* head2)
{
    int c1 = 0, c2 = 0;
    Node *temp1 = head1, *temp2 = head2;
    
    while(temp1 != NULL) {
        c1++;
        temp1 = temp1->next;
    }
    while(temp2 != NULL) {
        c2++;
        temp2 = temp2->next;
    }
    
    int diff = abs(c1-c2);
    temp1 = head1;
    temp2 = head2;
    
    if(c1>c2) {
        while(diff--) {
            temp1 = temp1->next;
        }
    } else {
        while(diff--) {
            temp2 = temp2->next;
        }
    }
    
    while(temp1 != NULL) {
        if(temp1 == temp2)
            return temp1->data;
        else {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    
    return -1;
}

