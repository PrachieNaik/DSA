/*

Problem statement: Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled form of S1.
    Scrambled string: 
    Given string str, we can represent it as a binary tree by partitioning it to two non-empty substrings recursively.
    Note: Srambled string is not same as an Anagram
    Below is one possible representation of str = “coder”:
     
    
        coder
       /    \
      co    der
     / \    /  \
    c   o  d   er
               / \
              e   r
    To scramble the string, we may choose any non-leaf node and swap its two children. 
    Suppose, we choose the node “co” and swap its two children, it produces a scrambled string “ocder”.
     
    
        ocder
       /    \
      oc    der
     / \    /  \
    o   c  d   er
               / \
              e   r
    Thus, “ocder” is a scrambled string of “coder”.
    Similarly, if we continue to swap the children of nodes “der” and “er”, it produces a scrambled string “ocred”.
     
    
        ocred
       /    \
      oc    red
     / \    /  \
    o   c  re  d
           / \
          r   e
    Thus, “ocred” is a scrambled string of “coder”.
    Examples:
    
    Input: S1=”coder”, S2=”ocder” 
    Output: Yes 
    Explanation: 
    “ocder” is a scrambled form of “coder”
    Input: S1=”abcde”, S2=”caebd” 
    Output: No 
    Explanation: 
    “caebd” is not a scrambled form of “abcde”

Approch: n order to solve this problem, we are using Divide and Conquer approach. 
    Given two strings of equal length (say n+1), S1[0…n] and S2[0…n]. If S2 is a scrambled form of S1, then there must exist an index i such that at least one of the following conditions is true: 
     
    S2[0…i] is a scrambled string of S1[0…i] and S2[i+1…n] is a scrambled string of S1[i+1…n].
    S2[0…i] is a scrambled string of S1[n-i…n] and S2[i+1…n] is a scrambled string of S1[0…n-i-1].

*/

bool isScramble(string S1, string S2)
{
    // Strings of non-equal length
    // cant' be scramble strings
    if (S1.length() != S2.length()) {
        return false;
    }
 
    int n = S1.length();
 
    // Empty strings are scramble strings
    if (n == 0) {
        return true;
    }
 
    // Equal strings are scramble strings
    if (S1 == S2) {
        return true;
    }
 
    for (int i = 1; i < n; i++) {
 
        // Check if S2[0...i] is a scrambled
        // string of S1[0...i] and if S2[i+1...n]
        // is a scrambled string of S1[i+1...n]
        if (isScramble(S1.substr(0, i), S2.substr(0, i))
            && isScramble(S1.substr(i, n - i),
                          S2.substr(i, n - i))) {
            return true;
        }
 
        // Check if S2[0...i] is a scrambled
        // string of S1[n-i...n] and S2[i+1...n]
        // is a scramble string of S1[0...n-i-1]
        if (isScramble(S1.substr(0, i),
                       S2.substr(n - i, i))
            && isScramble(S1.substr(i, n - i),
                          S2.substr(0, n - i))) {
            return true;
        }
    }
 
    // If none of the above
    // conditions are satisfied
    return false;
}
