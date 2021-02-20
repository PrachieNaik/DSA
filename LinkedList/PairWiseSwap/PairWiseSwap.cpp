/*

Problem statement: Given a singly linked list of size N. The task is to swap elements in the linked list pairwise.

Sample Input: 1->2->3->4->5->6->7 

Sample Output: 2->1->4->3->6->5->7

Constraints: 1 ≤ N ≤ 10^3

Basic case: 1
Advance case: 1->2->3->4
Edge case: 1, 1->2
No input case: NA

Approaches:

Brute Force: Start from the head node and traverse the list. While traversing swap data of each node with its next node’s data.
	Time Complexity: O(N)
	Space Complexity: O(1)

Optimized: If data contains many fields, there will be many swap operations. So changing links is a better idea in general.
	Time Complexity: O(N)
	Space Complexity: O(1)

*/

Node* pairWiseSwap(struct Node* head) {
    // The task is to complete this method
	Node * first = head;
	Node * second = head->next;
	if(first==NULL || second == NULL)
		return first;
	head = second;
	while(first != NULL && second != NULL) {
		Node * temp = second ->next;
		second -> next = first;
		if(temp == NULL || temp -> next == NULL)
		{
		     first -> next = temp;
		     return head;
		}
		first -> next = temp -> next;
		first = temp;
		second = temp-> next;
	}
	return head;
}
