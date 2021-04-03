/*

Problem statement: Given a Binary Tree, we need to print the bottom view from left to right. A node x is there in output if x is the bottommost node at its 
horizontal distance. Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, and that of right child is horizontal distance of 
x plus 1. 

Approach: Using Queue 
    The following are steps to print Bottom View of Binary Tree. 
    1. We put tree nodes in a queue for the level order traversal. 
    2. Start with the horizontal distance(hd) 0 of the root node, keep on adding left child to queue along with the horizontal distance as hd-1 and right child as 
        hd+1. 
    3. Also, use a TreeMap which stores key value pair sorted on key. 
    4. Every time, we encounter a new horizontal distance or an existing horizontal distance put the node data for the horizontal distance as key. For the first 
        time it will add to the map, next time it will replace the value. This will make sure that the bottom most element for that horizontal distance is present
        in the map and if you see the tree from beneath that you will see that element.

Time Complexity of the above implementation is O(n Log n). Note that the above implementation uses a map which is implemented using self-balancing BST. We can 
reduce the time complexity to O(n) using unordered_map. To print nodes in the desired order, we can have 2 variables denoting min and max horizontal distance. We
can simply iterate from min to max horizontal distance and get corresponding values from Map. So it is O(n)
Auxiliary Space: O(n) 

*/

void bottomView(Node *root) 
{ 
    if (root == NULL) 
        return; 
  
    // Initialize a variable 'hd' with 0 
    // for the root element. 
    int hd = 0; 
  
    // TreeMap which stores key value pair 
    // sorted on key value 
    map<int, int> m; 
  
    // Queue to store tree nodes in level 
    // order traversal 
    queue<Node *> q; 
  
    // Assign initialized horizontal distance 
    // value to root node and add it to the queue. 
    root->hd = hd; 
    q.push(root);  // In STL, push() is used enqueue an item 
  
    // Loop until the queue is empty (standard 
    // level order loop) 
    while (!q.empty()) 
    { 
        Node *temp = q.front(); 
        q.pop();   // In STL, pop() is used dequeue an item 
  
        // Extract the horizontal distance value 
        // from the dequeued tree node. 
        hd = temp->hd; 
  
        // Put the dequeued tree node to TreeMap 
        // having key as horizontal distance. Every 
        // time we find a node having same horizontal 
        // distance we need to replace the data in 
        // the map. 
        m[hd] = temp->data; 
  
        // If the dequeued node has a left child, add 
        // it to the queue with a horizontal distance hd-1. 
        if (temp->left != NULL) 
        { 
            temp->left->hd = hd-1; 
            q.push(temp->left); 
        } 
  
        // If the dequeued node has a right child, add 
        // it to the queue with a horizontal distance 
        // hd+1. 
        if (temp->right != NULL) 
        { 
            temp->right->hd = hd+1; 
            q.push(temp->right); 
        } 
    } 
  
    // Traverse the map elements using the iterator. 
    for (auto i = m.begin(); i != m.end(); ++i) 
        cout << i->second << " "; 
} 
