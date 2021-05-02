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
 
// This function returns empty string if tree
string inorder(Node* root,unordered_map <string,int> &mp,int &flag)
{
	if(root==NULL)
	return "";
	
	string s = "(";
	s = s + inorder(root->left,mp,flag);
	s = s + to_string(root->data);
	s = s + inorder(root->right,mp,flag);
	s = s + ")";
    
  if(mp[s] == 1 && s.length() >= 5)
  {
    flag = 1;
	}
	mp[s]++;
	
	return s;
}
bool dupSub(Node *root)
{
    unordered_map <string,int> mp;
	int flag = 0;
	inorder(root,mp,flag);
	return flag;
}
