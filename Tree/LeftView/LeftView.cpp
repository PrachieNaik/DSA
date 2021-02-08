/*

Problem statement: Given a Binary Tree, print left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from left side.

Constraints:
0 <= Number of nodes <= 100
1 <= Data of a node <= 1000


Approaches:

Method-1 (Using Recursion)

  The left view contains all nodes that are first nodes in their levels. A simple solution is to do level order traversal and print the first node in every level.
  The problem can also be solved using simple recursive traversal. We can keep track of the level of a node by passing a parameter to all recursive calls. The idea is to keep track of the maximum level also. Whenever we see a node whose level is more than maximum level so far, we print the node because this is the first node in its level (Note that we traverse the left subtree before right subtree). 
    
	Time Complexity: The function does a simple traversal of the tree, so the complexity is O(n). 
  Auxiliary Space: O(n), due to the stack space during recursive call.  

Method-2 (Using Queue):

  In this method, level order traversal based solution is discussed. If we observe carefully, we will see that our main task is to print the left most node of every level. So, we will do a level order traversal on the tree and print the leftmost node at every level.

	Time Complexity: O( n ), where n is the number of nodes in the binary tree.
    Auxiliary Space: O(1)

*/

// function to print left view of 
// binary tree 
void printLeftView(Node* root) 
{ 
    if (!root) 
        return; 
 
    queue<Node*> q; 
    q.push(root); 
 
    while (!q.empty()) 
    {     
        // number of nodes at current level 
        int n = q.size(); 
         
        // Traverse all nodes of current level 
        for(int i = 1; i <= n; i++) 
        { 
            Node* temp = q.front(); 
            q.pop(); 
                 
            // Print the left most element 
            // at the level 
            if (i == 1) 
                cout<<temp->data<<" "; 
             
            // Add left node to queue 
            if (temp->left != NULL) 
                q.push(temp->left); 
 
            // Add right node to queue 
            if (temp->right != NULL) 
                q.push(temp->right); 
        } 
    } 
}     
