/*

Problem statement: Inorder Tree Traversal without recursion and without stack

Using Morris Traversal, we can traverse the tree without using stack and recursion. The idea of Morris Traversal is based on Threaded Binary Tree. In this 
traversal, we first create links to Inorder successor and print the data using these links, and finally revert the changes to restore original tree. 

1. Initialize current as root 
2. While current is not NULL
   If the current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Find rightmost node in current left subtree OR
              node whose right child == current.
         If we found right child == current
             a) Update the right child as NULL of that node whose right child is current
             b) Print current’s data
             c) Go to the right, i.e. current = current->right
         Else
             a) Make current as the right child of that rightmost 
                node we found; and 
             b) Go to this left child, i.e., current = current->left
             
Time Complexity : O(n) If we take a closer look, we can notice that every edge of the tree is traversed at most two times. And in the worst case, the same 
number of extra edges (as input tree) are created and removed.
*/

/* Function to traverse the binary tree without recursion and without stack */
vector<int> inOrder(Node* root)
{
    vector<int> ans;
    Node * curr = root;
    while(curr != NULL) {
    
        if(curr -> left == NULL) {
            ans.push_back(curr->data);
            curr = curr->right;
        } else {
        
            /* Find the inorder predecessor of current */
            
            Node * prev = curr->left;
            while(prev->right != NULL && prev->right != curr) {
                prev = prev -> right;
            }
            
            /* Make current as the right child of its inorder predecessor */
            if(prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            } 
            
            /* Revert the changes made in the 'if' part to restore the original tree i.e., fix the right child of predecessor */
            else {
                prev->right = NULL;
                ans.push_back(curr -> data);
                curr = curr->right;
            }
        }
    }
    return ans;
}
