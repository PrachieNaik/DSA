/*

Problem statement: Given a Binary Tree, find size of the Largest Independent Set(LIS) in it. A subset of all tree nodes is an independent set if there is no edge
between any two nodes of the subset.

Approach 1: Let LISS(X) indicates size of largest independent set of a tree with root X.
    
    LISS(X) = MAX { (1 + sum of LISS for all grandchildren of X),
                         (sum of LISS for all children of X) }
                         
    The idea is simple, there are two possibilities for every node X, either X is a member of the set or not a member. If X is a member, then the value of LISS(X)
    is 1 plus LISS of all grandchildren. If X is not a member, then the value is sum of LISS of all children.
    
    int LISS(struct Node *root)
    {
        if(root == NULL)
        return 0;
        
        int excl = LISS(root->left) + LISS(root->right);
        int incl = 1;
        if(root->left) {
            incl += LISS(root->left->left) +LISS(root->left->right);
        }
        if(root->right) {
            incl += LISS(root->right->left) +LISS(root->right->right);
        }
        return max(incl,excl);
    }

    Time complexity of the above naive recursive approach is exponential
   

Approach 2: Memoization

*/
int LISS(struct Node *root, map<Node*,int> &memo)
{
    if(root == NULL)
        return 0;
    if( root->left == NULL && root->right == NULL  )
        return 1;
    if( memo.find(root) != memo.end() )
        return memo[root];
    // not include curr_node
    int size_excl = LISS(root->left) + LISS(root->right);
    
    // include curr_node
    int size_incl = 1;
    if( root->left != NULL )
        size_incl += LISS((root->left)->left) + LISS((root->left)->right) ; 
    if( root->right != NULL )
        size_incl += LISS((root->right)->left) + LISS((root->right)->right) ;
        
    // return max(include , exclude)
    memo[root]= max( size_excl , size_incl );
    return memo[root];
}

int LISS( struct Node *root )
{   
    map<Node*, int> memo;
    return LISS( root, memo );
}
