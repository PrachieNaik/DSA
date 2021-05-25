/*

Problem statement: Given preorder traversal of a binary search tree, construct the BST.

For example, if the given traversal is {10, 5, 1, 7, 40, 50}, then the output should be the root of the following tree.

     10
   /   \
  5     40
 /  \      \
1    7      50

Approach:  The trick is to set a range {min .. max} for every node. Initialize the range as {INT_MIN .. INT_MAX}. The first node will definitely be in range, so create
a root node. To construct the left subtree, set the range as {INT_MIN …root->data}. If a value is in the range {INT_MIN .. root->data}, the values are part of the left
subtree. To construct the right subtree, set the range as {root->data..max .. INT_MAX}. 

Time Complexity: O(n)

*/

int construct_BST(vector<int> &preorder,int n,int pos,TreeNode *curr,int left,int right)
    {
        if(pos==n || preorder[pos]<left || preorder[pos]>right) //Boundary case
            return pos;
        
        if(preorder[pos]<curr->val)     //Insert in left-subtree
        {
            curr->left = getNewnode(preorder[pos]);
            pos += 1;
            pos = construct_BST(preorder,n,pos,curr->left,left,curr->val-1);
        }
        
        if(pos==n || preorder[pos]<left || preorder[pos]>right)
            return pos;
        
        //Insert in right-subtree
        curr->right = getNewnode(preorder[pos]);
        pos += 1;
        pos = construct_BST(preorder,n,pos,curr->right,curr->val+1,right);
        return pos;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n = preorder.size();
        if(n==0)
            return NULL;
        
        TreeNode *root = getNewnode(preorder[0]);
        if(n==1)
            return root;

        construct_BST(preorder,n,1,root,INT_MIN,INT_MAX);
        return root;
    }
