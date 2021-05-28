/*

Problem statement:Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Constraints:
1 ≤ N ≤ 10^5
1 ≤ Node Data ≤ 10^5

Approach: We break the problem in 3 parts:
1. Print the left boundary in top-down manner.
2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts:
.....2.1 Print all leaf nodes of left sub-tree from left to right.
.....2.2 Print all leaf nodes of right subtree from left to right.
3. Print the right boundary in bottom-up manner

*/

void printleft(Node* root,vector <int> &ans)
{
    if(root==NULL)return;
    
    if(root->left)
    {
        ans.push_back(root->data);
        printleft(root->left,ans);
    }
    else if(root->right)
    {
        ans.push_back(root->data);
        printleft(root->right,ans);
    }
}
void printright(Node* root,vector <int> &ans)
{
    if(root==NULL)return;
    
    if(root->right)
    {
        printright(root->right,ans);
        ans.push_back(root->data);
    }
    else if(root->left)
    {
        printright(root->left,ans);
        ans.push_back(root->data);
    }
}
void printleaf(Node* root,vector <int> &ans)
{
    if(root==NULL)return;
    
    printleaf(root->left,ans);
    
    if(root->left==NULL&&root->right==NULL)
    {
        ans.push_back(root->data);
    }
    
    printleaf(root->right,ans);
}
vector <int> printBoundary(Node *root)
{
     vector <int> ans;
     
     if(root==NULL)return ans;
     
     ans.push_back(root->data);
     printleft(root->left,ans);
     
     printleaf(root->left,ans);
     printleaf(root->right,ans);
     
     printright(root->right,ans);
     return ans;
}
