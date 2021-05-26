/*

Problem statement: Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that the sum of chosen nodes is maximum
under a constraint that no two chosen node in the subset should be directly connected that is, if we have taken a node in our sum then we can’t take any of its
children in consideration and vice versa. 

Approach: We can solve this problem by considering the fact that both node and its children can’t be in sum at the same time, so when we take a node into our sum we
will call recursively for its grandchildren or if we don’t take this node then we will call for all its children nodes and finally we will choose maximum from both 
of the results. 
It can be seen easily that the above approach can lead to solving the same subproblem many times. We can stop solving these nodes more than once by memoizing the result
at all nodes. 
In the below code, a map is used for memoizing the result which stores the result of the complete subtree rooted at a node in the map so that if it is called again, 
the value is not calculated again instead stored value from the map is returned directly. 

*/

// method returns maximum sum possible from subtrees rooted
// at grandChildrens of node 'node'
int sumOfGrandChildren(node* node, map<struct node*, int>& mp)
{
    int sum = 0;
 
    //  call for children of left child only if it is not NULL
    if (node->left)
        sum += getMaxSumUtil(node->left->left, mp) + getMaxSumUtil(node->left->right, mp);
 
    //  call for children of right child only if it is not NULL
    if (node->right)
        sum += getMaxSumUtil(node->right->left, mp) + getMaxSumUtil(node->right->right, mp);
 
    return sum;
}
 
//  Utility method to return maximum sum rooted at node 'node'
int getMaxSumUtil(node* node, map<struct node*, int>& mp)
{
    if (node == NULL)
        return 0;
 
    // If node is already processed then return calculated
    // value from map
    if (mp.find(node) != mp.end())
        return mp[node];
 
    //  take current node value and call for all grand children
    int incl = node->data + sumOfGrandChildren(node, mp);
 
    //  don't take current node value and call for all children
    int excl = getMaxSumUtil(node->left, mp) + getMaxSumUtil(node->right, mp);
 
    //  choose maximum from both above calls and store that in map
    mp[node] = max(incl, excl);
 
    return mp[node];
}
 
// Returns maximum sum from subset of nodes
// of binary tree under given constraints
int getMaxSum(node* node)
{
    if (node == NULL)
        return 0;
    map<struct node*, int> mp;
    return getMaxSumUtil(node, mp);
}
 
