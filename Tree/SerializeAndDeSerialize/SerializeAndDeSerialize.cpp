/*

Problem statement: The task is to complete two function serialize which takes the root node of the tree as input andstores the tree into an array and deSerialize which deserializes the array to the original tree and returns the root of it.

Constraints:
1 <= Number of nodes <= 1000
1 <= Data of a node <= 1000

Example:
    Let the marker for NULL pointers be '-1'
    
    Input:
             20
           /    
          8     
         / \
        4  12 
          /  \
         10  14
    Output: 20 8 4 -1 -1 12 10 -1 -1 14 -1 -1 -1 
    
Time Complexity: O(n)

*/

void serializeUtil(Node *root,vector<int> &ans) {
    
    //base case (-1 is marker to show the node is null)
    if(root == NULL) {
        ans.push_back(-1);
        return;
    }
    
    ans.push_back(root->data);
    
    //recursion 
    serializeUtil(root->left, ans);
    serializeUtil(root->right, ans);
}

/*this  function serializes the binary tree and stores it in the vector A*/
vector<int> serialize(Node *root) {
    
    vector<int> ans;
    serializeUtil(root, ans);
    return ans;
}

Node* deSerializeUtil(Node *root,vector<int> &ans,int &index) {
    
    //base case (-1 is marker to show the node is null)
    if(ans[index] == -1) {
        root = NULL;
        return root;
    }
    
    root = new Node(ans[index]);
    
    //recursion
    root->left = deSerializeUtil(root->left, ans,++index);
    root->right = deSerializeUtil(root->right, ans,++index);
    return root;
}

/*this function deserializes the serialized vector A*/
Node * deSerialize(vector<int> &A)
{
   Node* root = NULL;
   int index = 0;
   root = deSerializeUtil(root, A,index);
   return root;
}
