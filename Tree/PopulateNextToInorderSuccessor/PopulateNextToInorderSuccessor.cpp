/*

Problem statement: Given a Binary Tree, write a function to populate next pointer for all nodes. The next pointer for every node should be set to point to inorder successor.

Example 1:

Input:
3
10 8 L 8 3 L 10 12 R

Output:
3->8 8->10 10->12 12->-1

Constraints:
1<=T<=10^5
1<=n<=10^5
1<=data of the node<=10^5

Approach:
Keep track of previous variable while traversing in inorder way. Set previous node's next pointer to current node.

Time complexity: O(N)

Reference: https://youtu.be/os0of0znlRk
*/

void populateNext(struct node* root)
{
    static node* prev=NULL;
    if(root==NULL)
    {
        return;
    }
    populateNext(root->left);
    if(prev!=NULL)
    {
        prev->next=root;
    }
    prev=root;
    populateNext(root->right);

}
