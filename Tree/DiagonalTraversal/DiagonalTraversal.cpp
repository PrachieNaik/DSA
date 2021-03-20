/*

Problem statement: Given a Binary Tree, print the diagonal traversal of the binary tree. Consider lines of slope -1 passing between nodes. Given a Binary Tree, 
print all diagonal elements in a binary tree belonging to same line.

Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
        
Output : 
8 10 14
 3 6 7 13
 1 4

Constraints:
1 <= Number of nodes<= 10^5
1 <= Data of a node<= 10^5
 
Approach: The idea is to use a map. We use different slope distances and use them as key in the map. Value in the map is a vector (or dynamic array) of nodes.
We traverse the tree to store values in the map. Once map is built, we print the contents of it. 

Time Complexity : O(n)
Space Complexity : O(n)

*/

/* root - root of the binary tree
   d -  distance of current line from rightmost-topmost slope.
   diagonalPrint - multimap to store Diagonal elements (Passed by Reference) */

void diagonalPrintUtil(Node* root, int d,
                map<int, vector<int>> &diagonalPrint)
{
    // Base case
    if (!root)
        return;
 
    // Store all nodes of same line together as a vector
    diagonalPrint[d].push_back(root->data);
 
    // Increase the vertical distance if left child
    diagonalPrintUtil(root->left, 
                      d + 1, diagonalPrint);
 
    // Vertical distance remains same for right child
    diagonalPrintUtil(root->right, 
                         d, diagonalPrint);
}
 
// Print diagonal traversal of given binary tree
void diagonalPrint(Node* root)
{
     
    // create a map of vectors to store Diagonal elements
    map<int, vector<int> > diagonalPrint;
    diagonalPrintUtil(root, 0, diagonalPrint);
 
    cout << "Diagonal Traversal of binary tree : \n";
    for (auto it :diagonalPrint)
    {
        vector<int> v=it.second;
        for(auto it:v)
          cout<<it<<" ";
        cout<<endl;
    }
}
