/*

Problem statement:Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in 
Binary Search Tree.


Example 1:

Input:
      4
    /   \
   2     9
k = 2 
Output: 4

Constraints:
1 <= N <= 1000
1 <= K <= N

Approach:
The idea is to do reverse inorder traversal of BST. Keep a count of nodes visited.
The reverse inorder traversal traverses all nodes in decreasing order, i.e, visit the right node then centre then left and continue traversing the nodes recursively.
While doing the traversal, keep track of the count of nodes visited so far.
When the count becomes equal to k, stop the traversal and print the key.

Time Complexity: O(h + k). 
The code first traverses down to the rightmost node which takes O(h) time, then traverses k elements in O(k) time. Therefore overall time complexity is O(h + k).
Auxiliary Space: O(1). 
As no extra space is needed (if recursion stack is counted then O(H))
*/

// A function to find k'th largest element in a given tree.
void kthLargestUtil(Node *root, int k, int &c)
{
    // Base cases, the second condition is important to
    // avoid unnecessary recursive calls
    if (root == NULL || c >= k)
        return;
 
    // Follow reverse inorder traversal so that the
    // largest element is visited first
    kthLargestUtil(root->right, k, c);
 
    // Increment count of visited nodes
    c++;
 
    // If c becomes k now, then this is the k'th largest
    if (c == k)
    {
        cout << "K'th largest element is "
             << root->key << endl;
        return;
    }
 
    // Recur for left subtree
    kthLargestUtil(root->left, k, c);
}
 
// Function to find k'th largest element
void kthLargest(Node *root, int k)
{
    // Initialize count of nodes visited as 0
    int c = 0;
 
    // Note that c is passed by reference
    kthLargestUtil(root, k, c);
}
