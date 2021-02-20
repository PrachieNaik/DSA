/*

Problem statement: There are two singly linked lists in a system. By some programming error, the end node of one of the linked list got linked to the second list, 
forming an inverted Y shaped list. Write a program to get the point where two linked list merge. 

Sample Input: LinkList1 = 3->6->9->common, LinkList2 = 10->common, common = 15->30->NULL

Sample Output: 15

Constraints: 1 ≤ N + M ≤ 2*105, -1000 ≤ value ≤ 1000

Approaches:

Method 1:  
    Use 2 nested for loops. The outer loop will be for each node of the 1st list and inner loop will be for 2nd list. In the inner loop, check if any of nodes of the
    2nd list is same as the current node of the first linked list. The time complexity of this method will be O(M * N) where m and n are the numbers of nodes in two 
    lists.

Method 2: Using Two pointers :
	Initialize two pointers ptr1 and ptr2  at the head1 and  head2.
	Traverse through the lists,one node at a time.
	When ptr1 reaches the end of a list, then redirect it to the head2.
	similarly when ptr2 reaches the end of a list, redirect it the head1.
	Once both of them go through reassigning,they will be equidistant from the collision point
	If at any node ptr1 meets ptr2, then it is the intersection node.
	After second iteration if there is no intersection node it returns NULL.
	
	Time complexity : O( m + n ) 
	Auxiliary Space:  O(1)

Method 3: 
	Get count of the nodes in the first list, let count be c1.
	Get count of the nodes in the second list, let count be c2.
	Get the difference of counts d = abs(c1 – c2)
	Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes 
	Then we can traverse both the lists in parallel till we come across a common node. (Note that getting a common node is done by comparing the address of the nodes)

	Time Complexity: O(m+n) 
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

