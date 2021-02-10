/*

Problem statement: Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level. If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Approaches:

    Method 1: 
    1. To maintain a hash for the branch of each node.
    2. Traverse the tree in level order fashion.
    3. In level order traversal, maintain a queue
       which holds, node and its vertical branch.
        * pop from queue.
        * add this node's data in vector corresponding
          to its branch in the hash.
        * if this node hash left child, insert in the 
          queue, left with branch - 1.
        * if this node hash right child, insert in the 
          queue, right with branch + 1.
	
	Time Complexity of the above implementation is O(n Log n). Note that the above implementation uses a map which is implemented using self-balancing BST. We can reduce the time complexity to O(n) using unordered_map. To print nodes in the desired order, we can have 2 variables denoting min and max horizontal distance. We can simply iterate from min to max horizontal distance and get corresponding values from Map. So it is O(n)
    Auxiliary Space: O(n) 

*/

// The main function to print vertical oder of a
// binary tree with given root
void printVerticalOrder(Node* root)
{
    // Base case
    if (!root)
        return;
 
    // Create a map and store vertical oder in
    // map using function getVerticalOrder()
    map<int, vector<int> > m;
    int hd = 0;
 
    // Create queue to do level order traversal.
    // Every item of queue contains node and
    // horizontal distance.
    queue<pair<Node*, int> > que;
    que.push(make_pair(root, hd));
 
    while (!que.empty()) {
        // pop from queue front
        pair<Node*, int> temp = que.front();
        que.pop();
        hd = temp.second;
        Node* node = temp.first;
 
        // insert this node's data in vector of hash
        m[hd].push_back(node->key);
 
        if (node->left != NULL)
            que.push(make_pair(node->left, hd - 1));
        if (node->right != NULL)
            que.push(make_pair(node->right, hd + 1));
    }
 
    // Traverse the map and print nodes at
    // every horigontal distance (hd)
    map<int, vector<int> >::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        for (int i = 0; i < it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}
