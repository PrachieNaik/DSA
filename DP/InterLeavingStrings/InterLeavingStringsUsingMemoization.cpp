/*

Problem statement: Given three strings A, B and C. Write a function that checks whether C is an interleaving of A and B. C is said to be interleaving A and B,
if it contains all characters of A and B and order of all characters in individual strings is preserved. 

Example: 

Input: strings: "XXXXZY", "XXY", "XXZ"
Output: XXXXZY is interleaved of XXY and XXZ
The string XXXXZY can be made by 
interleaving XXY and XXZ
String:    XXXXZY
String 1:    XX Y
String 2:  XX  Z

Input: strings: "XXY", "YX", "X"
Output: XXY is not interleaved of YX and X
XXY cannot be formed by interleaving YX and X.
The strings that can be formed are YXX and XYX

Approach: 
Create a recursive function that takes parameters A, B, and C. To handle all cases, two possibilities need to be considered.

If the first character of C matches the first character of A, we move one character ahead in A and C and recursively check.
If the first character of C matches the first character of B, we move one character ahead in B and C and recursively check.
If any of the above function returns true or A, B and C are empty then return true else return false.
  
Time Complexity: O(n*m) 
Auxiliary Space: O(n*m)
*/

bool check(string A, string B, string C,int len1,int len2,int len3,int p1,int p2,int p3) {
    unordered_map<string,bool> m;
    if(p3 == len3) {
        if(p1 == len1 && p2 == len2)
        return true;
        else
        return false;
    }
    string key = to_string(p1)+'*'+to_string(p2)+'*'+to_string(p3);
    if(m.find(key) != m.end()) {
        return m[key];
    }
    
    if(p1 == len1) 
    return m[key] = (B[p2] == C[p3]) ? check(A,B,C,len1,len2,len3,p1,p2+1,p3+1) : false;
    
    if(p2 == len2)
    return m[key] = (A[p1] == C[p3]) ? check(A,B,C,len1,len2,len3,p1+1,p2,p3+1) : false;
    
    bool one = false, two = false;
    
    if(A[p1] == C[p3]) {
        one = check(A,B,C,len1,len2,len3,p1+1,p2,p3+1);
    }
    
    if(B[p2] == C[p3]) {
        two = check(A,B,C,len1,len2,len3,p1,p2+1,p3+1);
    }
    
    return m[key] = one or two;
}
bool isInterleave(string A, string B, string C) 
{
    int len1 = A.length();
    int len2 = B.length();
    int len3 = C.length();
    if(len1 + len2 != len3)
    return false;
    
    return check(A,B,C,len1,len2,len3,0,0,0);
}
