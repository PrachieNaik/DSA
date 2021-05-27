/*

Problem statement: Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when
the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3

Constraints:
1 ≤ N ≤ 10^5
1 ≤ Node Data ≤ 10^5

Approach 1: The idea is to do something similar to vertical Order Traversal. Like vertical Order Traversal, we need to put nodes of same horizontal distance
together. We do a level order traversal so that the topmost node at a horizontal node is visited before any other node of same horizontal distance below it.
Hashing is used to check if a node at given horizontal distance is seen or not. 

    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        queue<pair<Node*,int>> q;
        map<int,int> mp;
        q.push({root,0});
        
        while(!q.empty()) {
            pair<Node*,int> temp = q.front();
            q.pop();
            if(mp[temp.second] == 0) {
                mp[temp.second] = temp.first->data;
            }
            if(temp.first->left) {
                q.push({temp.first->left,temp.second - 1});
            }
            if(temp.first->right) {
                q.push({temp.first->right,temp.second + 1});
            }
        }
        
        for(auto it = mp.begin();it!=mp.end();it++) {
            ans.push_back(it->second);
        }
        return ans;
    }

Approach 2: This approach does not require a queue. Here we use the two variables, one for vertical distance of current node from the root and another for 
the depth of the current node from the root. We use the vertical distance for indexing. If one node with the same vertical distance comes again, we check if 
depth of new node is lower or higher with respect to the current node with same vertical distance in the map. If depth of new node is lower, then we replace it.

Time Complexity of the above implementation is O(nlogn) where n is the number of nodes in the given binary tree with each insertion operation in Map requiring
O(log2n) complexity.
*/

// function to fill the map
void fillMap(Node* root, int d, int l,
             map<int, pair<int, int> >& m)
{
    if (root == NULL)
        return;
 
    if (m.count(d) == 0) {
        m[d] = make_pair(root->data, l);
    }
    else if (m[d].second > l) {
        m[d] = make_pair(root->data, l);
    }
 
    fillMap(root->left, d - 1, l + 1, m);
    fillMap(root->right, d + 1, l + 1, m);
}
 
// function should print the topView of
// the binary tree
void topView(struct Node* root)
{
 
    // map to store the pair of node value and its level
    // with respect to the vertical distance from root.
    map<int, pair<int, int> > m;
 
    // fillmap(root,vectical_distance_from_root,level_of_node,map)
    fillMap(root, 0, 0, m);
 
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->second.first << " ";
    }
}
