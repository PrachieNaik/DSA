/*

Problem statement:Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the last level.

Example 1:

Input :
        1
      /   \
     3     2

Output: 3 2 1
Explanation:
Traversing level 1 : 3 2
Traversing level 0 : 1
Example 2:

Input :
       10
      /  \
     20   30
    / \ 
   40  60

Output: 40 60 20 30 10
Explanation:
Traversing level 2 : 40 60
Traversing level 1 : 20 30
Traversing level 0 : 10

Constraints:
1 ≤ N ≤ 10^5
1 ≤ Node Data ≤ 10^5

Approach 1: (Recursive function to print a given level) 
We can easily modify the method 1 of the normal level order traversal. In method 1, we have a method printGivenLevel() which prints a given level number.
The only thing we need to change is, instead of calling printGivenLevel() from the first level to the last level, we call it from the last level to the first level. 
    
    /* Function to print REVERSE 
    level order traversal a tree
    void reverseLevelOrder(node* root) 
    { 
        int h = height(root); 
        int i; 
        for (i=h; i>=1; i--) //THE ONLY LINE DIFFERENT FROM NORMAL LEVEL ORDER 
            printGivenLevel(root, i); 
    } 
      
    /* Print nodes at a given level 
    void printGivenLevel(node* root, int level) 
    { 
        if (root == NULL) 
            return; 
        if (level == 1) 
            cout << root->data << " "; 
        else if (level > 1) 
        { 
            printGivenLevel(root->left, level - 1); 
            printGivenLevel(root->right, level - 1); 
        } 
    } 
      
    /* Compute the "height" of a tree -- the number of 
        nodes along the longest path from the root node 
        down to the farthest leaf node.
    int height(node* node) 
    { 
        if (node == NULL) 
            return 0; 
        else
        { 
            /* compute the height of each subtree 
            int lheight = height(node->left); 
            int rheight = height(node->right); 
      
            /* use the larger one 
            if (lheight > rheight) 
                return(lheight + 1); 
            else return(rheight + 1); 
        } 
    } 
    
    Time Complexity: The worst-case time complexity of this method is O(n^2). For a skewed tree, printGivenLevel() takes O(n) time where n is the number of
    nodes in the skewed tree. So time complexity of printLevelOrder() is O(n) + O(n-1) + O(n-2) + .. + O(1) which is O(n^2).
    
Approach 2: The idea is to use a deque(double-ended queue) to get the reverse level order. A deque allows insertion and deletion at both the ends. If we do
normal level order traversal and instead of printing a node, push the node to a stack and then print the contents of the deque, we get “5 4 3 2 1” for the above
example tree, but the output should be “4 5 2 3 1”. So to get the correct sequence (left to right at every level), we process children of a node in reverse
order, we first push the right subtree to the deque, then process the left subtree.

    Time Complexity: O(n) where n is the number of nodes in the binary tree.
*/

/* Given a binary tree, print its nodes in reverse level order */
void reverseLevelOrder(node* root)
{
    stack <node *> S;
    queue <node *> Q;
    Q.push(root);
  
    // Do something like normal level order traversal order. Following are the
    // differences with normal level order traversal
    // 1) Instead of printing a node, we push the node to stack
    // 2) Right subtree is visited before left subtree
    while (Q.empty() == false)
    {
        /* Dequeue node and make it root */
        root = Q.front();
        Q.pop();
        S.push(root);
  
        /* Enqueue right child */
        if (root->right)
            Q.push(root->right); // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT
  
        /* Enqueue left child */
        if (root->left)
            Q.push(root->left);
    }
  
    // Now pop all items from stack one by one and print them
    while (S.empty() == false)
    {
        root = S.top();
        cout << root->data << " ";
        S.pop();
    }
}
