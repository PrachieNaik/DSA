/*

Problem statement: Given a binary tree, find all duplicate subtrees. For each duplicate subtree, we only need to return the root node of any one of them. Two trees 
are duplicates if they have the same structure with the same node values.

Examples: 

Input :
       1
      / \
     2   3
    /   / \
   4   2   4
      /
     4

Output : 
   2           
  /    and    4
 4
 
Explanation: Above Trees are two duplicate subtrees. Therefore, you need to return above trees root in the form of a list.

The idea is to use hashing. We store inorder traversals of subtrees in a hash. Since simple inorder traversal cannot uniquely identify a tree, we use symbols like
‘(‘ and ‘)’ to represent NULL nodes. 
We pass an Unordered Map in C++ as an argument to the helper function which recursively calculates inorder string and increases its count in map. If any string 
gets repeated, then it will imply duplication of the subtree rooted at that node so push that node in the Final result and return the vector of these nodes.  

Time Complexity: O(N^2)
Space Complexity: O(N)
*/

string inorder(Node* node, unordered_map<string, int>& m)
{
    if (!node)
        return "";
 
    string str = "(";
    str += inorder(node->left, m);
    str += to_string(node->data);
    str += inorder(node->right, m);
    str += ")";
 
    // Subtree already present (Note that we use
    // unordered_map instead of unordered_set
    // because we want to print multiple duplicates
    // only once, consider example of 4 in above
    // subtree, it should be printed only once.
    if (m[str] == 1)
        cout << node->data << " ";
 
    m[str]++;
 
    return str;
}
 
// Wrapper over inorder()
void printAllDups(Node* root)
{
    unordered_map<string, int> m;
    inorder(root, m);
}
