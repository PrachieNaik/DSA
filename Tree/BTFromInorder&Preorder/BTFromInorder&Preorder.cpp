/*

Problem statement: Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

Example 1:

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5

Constraints:
1<=Number of Nodes<=1000

Approach: buildTree() 
1) Pick an element from Preorder. Increment a Preorder Index Variable (preIndex in below code) to pick the next element in the next recursive call. 
2) Create a new tree node tNode with the data as the picked element. 
3) Find the picked element’s index in Inorder. Let the index be inIndex. 
4) Call buildTree for elements before inIndex and make the built tree as a left subtree of tNode. 
5) Call buildTree for elements after inIndex and make the built tree as a right subtree of tNode. 
6) return tNode.

Time Complexity: O(n^2). The worst case occurs when the tree is left-skewed. Example Preorder and Inorder traversals for worst-case are {A, B, C, D} and {D, C, B, A}. 
*/

Node* buildTreeUtil(int in[],int pre[], int &preIndex,int start,int end,int n) {
    if(preIndex >= n)
    return NULL;
    
    if(start>end)
    return NULL;
    
    Node* node = new Node(pre[preIndex++]);
    if(start == end)
    return node;
    
    int inIndex = 0;
    for(int i = start;i<=end;i++) {
        if(in[i] == node->data)
        inIndex = i;
    }
    node->left = buildTreeUtil(in,pre,preIndex,start,inIndex - 1,n);
    node->right = buildTreeUtil(in,pre,preIndex,inIndex + 1,end,n);
    return node;
}
Node* buildTree(int in[],int pre[], int n)
{
    int preIndex = 0;
    return buildTreeUtil(in,pre,preIndex,0,n-1,n);
    
}
