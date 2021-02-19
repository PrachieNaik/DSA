/*

Problem statement: Write a function to print spiral level order traversal of a tree. 

Approach: The idea is to keep on entering nodes like normal level order traversal, but during printing, in alternative turns push them onto the stack and print them,
and in other traversals, just print them the way they are present in the queue.

Time Complexity : O(n)
Auxiliary Space : O(n)

*/

/* Function to print a tree in spiral form using one stack */
void printSpiralUsingOneStack(Node* root) 
{ 
    if (root == NULL) 
        return; 
  
    stack<int> s;  
    queue<Node*> q; 
  
    bool reverse = true; 
    q.push(root); 
    while (!q.empty()) { 
  
        int size = q.size(); 
        while (size) { 
            Node* p = q.front(); 
            q.pop(); 
  
            // if reverse is true, push node's data onto the stack, else print it 
            if (reverse) 
                s.push(p->data); 
            else
                cout << p->data << " "; 
  
            if (p->left) 
                q.push(p->left); 
            if (p->right) 
                q.push(p->right); 
            size--; 
        } 
  
        // print nodes from the stack if reverse is true 
        if (reverse) { 
            while (!s.empty()) { 
                cout << s.top() << " "; 
                s.pop(); 
            } 
        } 
  
        // the next row has to be printed as it is, hence change the value of reverse 
        reverse = !reverse; 
    } 
} 
