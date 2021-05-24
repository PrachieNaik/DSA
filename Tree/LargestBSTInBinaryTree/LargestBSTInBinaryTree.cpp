/*

Problem statement: Given a Binary Tree, write a function that returns the size of the largest subtree which is also a Binary Search Tree (BST). If the
complete Binary Tree is BST, then return the size of the whole tree.

Examples: 
Input: 
      5
    /  \
   2    4
 /  \
1    3

Output: 3 
The following subtree is the maximum size BST subtree 
   2  
 /  \
1    3


Input: 
       50
     /    \
  30       60
 /  \     /  \ 
5   20   45    70
              /  \
            65    80
Output: 5
The following subtree is the maximum size BST subtree 
      60
     /  \ 
   45    70
        /  \
      65    80
   
Approach: A Tree is BST if following is true for every node x. 
 
The largest value in left subtree (of x) is smaller than value of x.
The smallest value in right subtree (of x) is greater than value of x.
We traverse tree in bottom up manner. For every traversed node, we return maximum and minimum values in subtree rooted with it. If any node follows
above properties and size of it's bst is greater then overall max size bst we update the answer.

*/

struct Info
{
    int size;
    bool isbst;
    int mx;
    int mn;
};
Info solve(Node* root,int& a)
{
    if(root == NULL)
    {
        Info t;
        t.size = 0;
        t.isbst = true;
        t.mx = INT_MIN;
        t.mn = INT_MAX;
        return t;   
    }
    Info left = solve(root->left,a);
    Info right = solve(root->right,a);
    Info ans;
    ans.mx = max(root->data,max(left.mx,right.mx));
    ans.mn = min(root->data,min(left.mn,right.mn));
    ans.size = 1 + left.size + right.size;
    ans.isbst = left.isbst && right.isbst && left.mx < root->data && right.mn > root->data;
   
    if(ans.isbst)
    {
        a = max(a,ans.size);
    }
    return ans;
}
int largestBst(Node *root)
{
    int a = 0;
    solve(root,a);
    return a;
}
