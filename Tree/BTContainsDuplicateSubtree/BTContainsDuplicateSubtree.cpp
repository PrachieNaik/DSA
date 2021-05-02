/*

Problem statement: Given a Binary Tree, check whether the Binary tree contains a duplicate sub-tree of size 2 or more. 
Note : Two same leaf nodes are not considered as subtree size of a leaf node is one.

Input :  Binary Tree 
               A
             /    \ 
           B        C
         /   \       \    
        D     E       B     
                     /  \    
                    D    E
Output : Yes

Approach 1:
A simple solution is that, we pick every node of tree and try to find is any sub-tree of given tree is present in tree which is identical with that sub-tree. 
Here we can use below post to find if a subtree is present anywhere else in tree. 

Approach 2:
An Efficient solution based on tree serialization and hashing. The idea is to serialize subtrees as strings and store the strings in hash table. Once we find a 
serialized tree (which is not a leaf) already existing in hash-table, we return true. 

*/
const char MARKER = '$';
unordered_set<string> subtrees;
 
// This function returns empty string if tree
// contains a duplicate subtree of size 2 or more.
string dupSubUtil(Node *root)
{
    string s = "";
 
    // If current node is NULL, return marker
    if (root == NULL)
        return s + MARKER;
 
    // If left subtree has a duplicate subtree.
    string lStr = dupSubUtil(root->left);
    if (lStr.compare(s) == 0)
    return s;
 
    // Do same for right subtree
    string rStr = dupSubUtil(root->right);
    if (rStr.compare(s) == 0)
    return s;
 
    // Serialize current subtree
    s = s + root->key + lStr + rStr;
 
    // If current subtree already exists in hash
    // table. [Note that size of a serialized tree
    // with single node is 3 as it has two marker
    // nodes.
    if (s.length() > 3 &&
        subtrees.find(s) != subtrees.end())
    return "";
 
    subtrees.insert(s);
 
    return s;
}
