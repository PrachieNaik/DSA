/*

Problem statement: Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR

Output: 3
Explanation: LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

Constraints:
1<=size(str1),size(str2)<=100

Approch: Recursion

*/

int lcs(int x, int y, string s1, string s2){
    
    //Base condition
    if(x == 0 || y == 0)
    return 0;
    
    int ans = max(lcs(x - 1, y, s1,s2),lcs(x, y - 1,s1,s2));
    
    if(s1[x - 1] == s2[y - 1]) {
        return max(1 + lcs(x - 1, y - 1, s1, s2), ans);
    }
    return ans;
}
