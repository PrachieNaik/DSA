/*

Problem statement: Construct a binary tree from a string consisting of parenthesis and integers. The whole input represents a binary tree. It contains an
integer followed by zero, one or two pairs of parenthesis. The integer represents the root’s value and a pair of parenthesis contains a child binary tree with
the same structure. Always start to construct the left child node of the parent first if it exists.

Examples: 

Input : "1(2)(3)" 
Output : 1 2 3
Explanation :
           1
          / \
         2   3
Explanation: first pair of parenthesis contains 
left subtree and second one contains the right 
subtree. Preorder of above tree is "1 2 3".  

Input : "4(2(3)(1))(6(5))"
Output : 4 2 3 1 6 5
Explanation :
           4
         /   \
        2     6
       / \   / 
      3   1 5   

Approach:

The very first element of the string is the root.
If the next two consecutive elements are “(” and “)”, this means there is no left child otherwise we will create and add the left child to the parent node recursively.
Once the left child is added recursively, we will look for consecutive “(” and add the right child to the parent node.
Encountering “)” means the end of either left or right node and we will increment the start index
The recursion ends when the start index is greater than equal to the end index

*/

// Below function accepts sttring and a pointer variable as
// an argument
// and draw the tree. Returns the root of the tree
Node* constructtree(string s, int* start)
{
    // Assuming there is/are no negative
    // character/characters in the string
    if (s.size() == 0 || *start >= s.size())
        return NULL;
 
    // constructing a number from the continuous digits
    int num = 0;
    while (*start < s.size() && s[*start] != '(' && s[*start] != ')') {
        int num_here = (int)(s[*start] - '0');
        num = num * 10 + num_here;
        *start = *start + 1;
    }
 
    // creating a node from the constructed number from
    // above loop
    struct Node* root = new Node(num);
 
    // check if start has reached the end of the string
    if (*start >= s.size())
        return root;
 
    // As soon as we see first right parenthesis from the
    // current node we start to construct the tree in the
    // left
    if (*start < s.size() && s[*start] == '(') {
        *start = *start + 1;
        root->left = constructtree(s, start);
    }
    if (*start < s.size() && s[*start] == ')')
        *start = *start + 1;
 
    // As soon as we see second right parenthesis from the
    // current node we start to construct the tree in the
    // right
    if (*start < s.size() && s[*start] == '(') {
        *start = *start + 1;
        root->right = constructtree(s, start);
    }
    if (*start < s.size() && s[*start] == ')')
        *start = *start + 1;
    return root;
}
