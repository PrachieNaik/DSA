/*

Problem statement: Given a Binary Search Tree, find median of it.

If no. of nodes are even: then median = ((n/2th node + (n+1)/2th node) /2
If no. of nodes are odd : then median = (n+1)/2th node.

Algorithm:
1- Count the no. of nodes in the given BST using Morris Inorder Traversal.
2- Then Perform Morris Inorder traversal one  more time by counting nodes and by checking if count is equal to the median point. To consider even no. of nodes an 
extra variable to the previous node data is used.
   
*/

/* Function to traverse the binary tree without recursion
   and without stack */
int countNodes(Node* root)
{
    int ans;
    Node * curr = root;
    while(curr != NULL) {
        if(curr -> left == NULL) {
            ans++;
            curr = curr->right;
        } else {
            /* Find the inorder predecessor of current */
            Node * prev = curr->left;
            while(prev->right != NULL && prev->right != curr) {
                prev = prev -> right;
            }
            /* Make current as the right child of its
               inorder predecessor */
            if(prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            } 
            /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
            else {
                prev->right = NULL;
                ans++;
                curr = curr->right;
            }
        }
    }
    return ans;
}

float findMedian(struct Node *root)
{
    int totalCount = countNodes(root);
    int currCount = 0;
    Node * curr = root;
    int prevNodeData = 0;
    while(curr != NULL) {
        if(curr -> left == NULL) {
            currCount++;
            if(totalCount % 2 == 0 && currCount == (totalCount/2)) {
                tempCount = curr -> data;
            } else if(totalCount % 2 == 0 && currCount == (totalCount/2) + 1) {
                return (float)(prevNodeData + curr->data)/2;
            } else if(totalCount % 2 != 0 && currCount == (totalCount+1)/2) {
                return curr->data;
            }
            curr = curr->right;
        } else {
            /* Find the inorder predecessor of current */
            Node * prev = curr->left;
            while(prev->right != NULL && prev->right != curr) {
                prev = prev -> right;
            }
            /* Make current as the right child of its
               inorder predecessor */
            if(prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            } 
            /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
            else {
                prev->right = NULL;
                currCount++;
                if(totalCount % 2 == 0 && currCount == (totalCount/2)) {
                    tempCount = curr -> data;
                } else if(totalCount % 2 == 0 && currCount == (totalCount/2) + 1) {
                    return (float)(prevNodeData + curr->data)/2;
                } else if(totalCount % 2 != 0 && currCount == (totalCount+1)/2) {
                    return curr->data;
                }
                curr = curr->right;
            }
        }
    }
    return 0;
}
