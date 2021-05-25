/*

Problem statement: Given a Binary Search Tree and a target sum. Check whether there's a pair of Nodes in the BST with value summing up to the target sum. 

Example 1:

Input:
        2
      /   \
     1     3
sum = 5
Output: 1 
Explanation: 
Nodes with value 2 and 3 sum up to 5.

Constraints:
1<=Number of Nodes<=100000
1<=Sum<=1000005

Approach:
The idea is same as finding the pair in sorted array. We traverse BST in Normal Inorder and Reverse Inorder simultaneously. In reverse inorder, we start from the
rightmost node which is the maximum value node. In normal inorder, we start from the left most node which is minimum value node. We add sum of current nodes in both
traversals and compare this sum with given target sum. If the sum is same as target sum, we return true. If the sum is more than target sum, we move to next node in
reverse inorder traversal, otherwise we move to next node in normal inorder traversal. If any of the traversals is finished without finding a pair, we return false.

Reference: https://youtu.be/wkd7e5K7KF8
*/

void pushElements(stack<Node*> &s,int dir,Node *root) {
    if(dir) {
        while(root) {
            s.push(root);
            root = root->left;
        }
    } else {
        while(root) {
            s.push(root);
            root = root->right;
        }
    }
}
// root : the root Node of the given BST
// target : the target sum
int isPairPresent(struct Node *root, int target)
{
    if(root == NULL)
    return 0;
    stack<Node*> s1,s2;
    Node* temp;
    int x,y;
    pushElements(s1,true,root);
    pushElements(s2,false,root);
    
    while(!s1.empty() && !s2.empty() && s1.top() -> data < s2.top() -> data) {
        x = s1.top() -> data;
        y = s2.top() -> data;
        if(x+y == target) {
            return 1;
        }
        if(x+y < target) {
            temp = s1.top();
            s1.pop();
            pushElements(s1,true,temp->right);
        } else {
            temp = s2.top();
            s2.pop();
            pushElements(s2,false,temp->left);
        }
    }
    return 0;
}
