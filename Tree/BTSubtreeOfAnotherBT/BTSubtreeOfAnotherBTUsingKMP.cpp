/*

Problem statement: Given two binary trees, check if the first tree is subtree of the second one. A subtree of a tree T is a tree S consisting of a node in T and
all of its descendants in T. The subtree corresponding to the root node is the entire tree; the subtree corresponding to any other node is called a proper subtree.

Approach: The idea is based on the fact that inorder and preorder/postorder uniquely identify a binary tree. Tree S is a subtree of T if both inorder and preorder
traversals of S arew substrings of inorder and preorder traversals of T respectively.

    Following are detailed steps.
    1) Find inorder and preorder traversals of T, store them in two auxiliary arrays inT[] and preT[].
    2) Find inorder and preorder traversals of S, store them in two auxiliary arrays inS[] and preS[].
    3) If inS[] is a subarray of inT[] and preS[] is a subarray preT[], then S is a subtree of T. Else not.
    We can also use postorder traversal in place of preorder in the above algorithm.
    
    The above algorithm doesn't work for cases where a tree is present
    in another tree, but not as a subtree. Consider the following example.
    
            Tree1
              x 
            /    \
          a       b
         /        
        c         
    
    
            Tree2
              x 
            /    \
          a       b
         /         \
        c            d
    
    Inorder and Preorder traversals of the big tree or Tree2 are.
    
    Inorder and Preorder traversals of small tree or Tree1 are
    
    The Tree2 is not a subtree of Tree1, but inS[] and preS[] are
    subarrays of inT[] and preT[] respectively.
    
    The above algorithm can be extended to handle such cases by adding a special character whenever we encounter NULL in inorder and preorder traversals.

    Time Complexity: Inorder and Preorder traversals of Binary Tree take O(n) time. The function strstr() can also be implemented in O(n) time using KMP string 
    matching algorithm.
    Auxiliary Space: O(n)
*/

void preorder(Node* root, vector<int> &a) {
    if (root != NULL) {
        a.push_back(root -> data);
        preorder(root -> left, a);
        preorder(root -> right, a);
    }
    else
    a.push_back(-1);
}
void inorder(Node* root, vector<int> &a) {
    if (root != NULL) {
        inorder(root -> left, a);        
        a.push_back(root -> data);
        inorder(root -> right, a);
    }
    else
    a.push_back(-1);
}

vector<int> kmp(vector<int>& text, vector<int>& pat)
{
    //return vector<int> which has indices of occurences of pat in text
    vector<int> ans;
    int n = text.size(), m = pat.size();
    vector<int> lps(m, 0);
    int j = 0;
    int k = 0;
    for (int i = 1; i <= m - 1; ++i)
    {
        while ( j > 0 && pat[i] != pat[j] )
            j = lps[j - 1];
        if ( pat[i] == pat[j] )
            lps[i] = ++j;
    }
    j = 0;
    for (int i = 0; i < n; ++i)
    {
        while ( j > 0 && pat[j] != text[i] )
            j = lps[j - 1];
        if ( pat[j] == text[i] )
        {
            j++;
            if ( j == m )
            {
                j = lps[j - 1];
                ans.push_back(i - m + 1);
            }
        }
    }
    return ans;
}

bool isSubTree(Node* t, Node* s) {
    // return 1 if S is subtree of T else 0
    vector<int> pre1,in1,pre2,in2;
    preorder(t, pre1);
    preorder(s, pre2);
    inorder(t, in1);
    inorder(s, in2);
    auto v1 = kmp(pre1, pre2), v2 = kmp(in1, in2);
    return (v1.empty() or v2.empty()) ? 0 : 1;
}
