/*

Problem statement:Given a Binary Tree, WAP to print the Preorder traversal of the given binary tree.

Recursive Approach: 
    Algorithm Preorder(tree)
       1. Visit the root.
       2. Traverse the left subtree, i.e., call Preorder(left-subtree)
       3. Traverse the right subtree, i.e., call Preorder(right-subtree) 
    Time Complexity: O(n) 
    Auxiliary Space : If we don’t consider size of stack for function calls then O(1) otherwise O(h) where h is the height of the tree. 

Iterative Approach:
    
    iterativePreorder(node) {
      if (node = null) {
          return
      }
      s —> empty stack
      s.push(node)
      while (!s.isEmpty()) {
          node —> s.pop()
          visit(node)
          if (node.right != null) {
              s.push(node.right)
          }
          if (node.left != null) {
              s.push(node.left)
          }
      }
    }
    Time Complexity: O(n) 
    Auxiliary Space: O(h) where h is the height of the tree. 


*/

// Iterative function to perform preorder traversal on the tree
void preorderIterative(Node* root)
{
    // return if the tree is empty
    if (root == nullptr)
    return;
 
    // create an empty stack and push the root node
    stack<Node*> stack;
    stack.push(root);
 
    // loop till stack is empty
    while (!stack.empty())
    {
        // pop a node from the stack and print it
        Node* curr = stack.top();
        stack.pop();
 
        cout << curr->data << " ";
 
        // push the right child of the popped node into the stack
        if (curr->right) {
            stack.push(curr->right);
        }
 
        // push the left child of the popped node into the stack
        if (curr->left) {
            stack.push(curr->left);
        }
 
        // the right child must be pushed first so that the left child
        // is processed first (LIFO order)
    }
}
 
