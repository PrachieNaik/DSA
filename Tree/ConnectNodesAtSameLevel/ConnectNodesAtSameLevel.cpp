/*

Problem statement: Given a binary tree, connect the nodes that are at same level. You'll be given an addition nextRight pointer for the same.Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.

Constraints:
1 <= Number of nodes <= 100
0 <= Data of a node <= 1000

Approaches: 

    Method 1: Using level order traversal 

    void connect(Node *p)
    {
       // Your Code Here
       if(p == NULL)
       return;
       
       queue<Node*> q;
       q.push(p);
       
       while(!q.empty()) {
           int size = q.size();
           
           for(int i =0;i<size;i++) {
               
               Node * temp = q.front();
               q.pop();
               
               if(i == size-1) {
                   temp->nextRight = NULL;
               } else { 
                    temp->nextRight = q.front();
               }
               
               if(temp->left!=NULL) 
               q.push(temp->left);
               if(temp->right!=NULL)
               q.push(temp->right);
           }
           
       }
    }

    Method 2: Instead of traversing in Pre Order fashion (root, left, right), if we traverse the nextRight node before the left and right children (root, nextRight, left), then we can make sure that all nodes at level i have the nextRight set, before the level i+1 nodes. 
    Auxiliary Space = O(1)
    
*/

/* This function returns the leftmost 
child of nodes at the same level as p.  
This function is used to getNExt right 
of p's right child  If right child of 
is NULL then this can also be used for 
the left child */
node *getNextRight(node *p)  
{  
    node *temp = p->nextRight;  
  
    /* Traverse nodes at p's level 
    and find and return the first  
    node's first child */
    while (temp != NULL)  
    {  
        if (temp->left != NULL)  
            return temp->left;  
        if (temp->right != NULL)  
            return temp->right;  
        temp = temp->nextRight;  
    }  
  
    // If all the nodes at p's level  
    // are leaf nodes then return NULL  
    return NULL;  
}  
  
/* Sets nextRight of all nodes 
of a tree with root as p */
void connectRecur(node* p)  
{  
    node *temp;  
  
    if (!p)  
    return;  
  
    // Set nextRight for root  
    p->nextRight = NULL;  
  
    // set nextRight of all levels one by one  
    while (p != NULL)  
    {  
        node *q = p;  
  
        /* Connect all childrem nodes of p and 
        children nodes of all other nodes at 
        same level as p */
        while (q != NULL)  
        {  
            // Set the nextRight pointer 
            // for p's left child  
            if (q->left)  
            {  
                // If q has right child, then  
                // right child is nextRight of  
                // p and we also need to set 
                // nextRight of right child  
                if (q->right)  
                    q->left->nextRight = q->right;  
                else
                    q->left->nextRight = getNextRight(q);  
            }  
  
            if (q->right)  
                q->right->nextRight = getNextRight(q);  
  
            // Set nextRight for other  
            // nodes in pre order fashion  
            q = q->nextRight;  
        }  
  
        // start from the first  
        // node of next level  
        if (p->left)  
            p = p->left;  
        else if (p->right)  
            p = p->right;  
        else
            p = getNextRight(p);  
    }  
}  
