/*

Problem statement: Given a singly linked list of N nodes. The task is to find the middle of the linked list.

Sample Input: 1->2->3->4->5->6

Sample Output: 4

Constraints: 1 <= N <= 5000

Assumptions: Data of the node will be a positive integer.

Basic case: 1
Advance case: 1->2->3->4->5
Edge case: 1, even length
No input case: NA

Keywords: Slow pointer, Fast pointer

Approaches:

Brute Force: Count all elements in first traversal, Go to middle in second traversal.
	Time Complexity: O(N)
	Space Complexity: O(1)

Optimized: Keep two pointers: fast and slow. When fast reaches end, slow reaches half.
	Time Complexity: O(N)
	Space Complexity: O(1)

*/

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
/* Function to get the middle of the linked list*/
int getMiddle(Node *head);
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		cout<<getMiddle(head)<<endl;
	}
	return 0; 
} 

/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
   Node *fast = head;
   Node *slow = head;
   while(fast!=NULL && fast->next!=NULL) {
       slow = slow->next;
       fast = fast->next->next;
   }
   return slow->data;
} 



