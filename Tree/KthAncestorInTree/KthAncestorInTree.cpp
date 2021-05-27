/*

Problem statement: Given a binary tree in which nodes are numbered from 1 to n. Given a node and a positive integer K. We have to print the K-th ancestor of the
given node in the binary tree. If there does not exist any such ancestor then print -1.
For example in the below given binary tree, 2nd ancestor of node 4 and 5 is 1. 3rd ancestor of node 4 will be -1. 

Approach: The idea to do this is to first traverse the binary tree and store the ancestor of each node in an array of size n. For example, suppose the array is
anecestor[n]. Then at index i, ancestor[i] will store the ancestor of ith node. So, the 2nd ancestor of ith node will be ancestor[ancestor[i]] and so on. We will
use this idea to calculate the kth ancestor of the given node. We can use level order traversal to populate this array of ancestors.

Time Complexity : O( n ) 
Auxiliary Space : O( n )
*/

// fucntion to generate array of ancestors
void generateArray(Node *root, int ancestors[])
{
    // There will be no ancestor of root node
    ancestors[root->data] = -1;
 
    // level order traversal to
    // generate 1st ancestor
    queue<Node*> q;
    q.push(root);
 
    while(!q.empty())
    {
        Node* temp  = q.front();
        q.pop();
 
        if (temp->left)
        {
            ancestors[temp->left->data] = temp->data;
            q.push(temp->left);
        }
 
        if (temp->right)
        {
            ancestors[temp->right->data] = temp->data;
            q.push(temp->right);
        }
    }
}
 
// function to calculate Kth ancestor
int kthAncestor(Node *root, int n, int k, int node)
{
    // create array to store 1st ancestors
    int ancestors[n+1] = {0};
 
    // generate first ancestor array
    generateArray(root,ancestors);
 
    // variable to track record of number of
    // ancestors visited
    int count = 0;
 
    while (node!=-1)
    {  
        node = ancestors[node];
        count++;
 
        if(count==k)
            break;
    }
 
    // print Kth ancestor
    return node;
}
