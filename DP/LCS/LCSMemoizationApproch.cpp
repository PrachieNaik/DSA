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

Approch: Memoization

*/

int dp[101][101];

int lcsUtil(int x, int y, string s1, string s2) {
    if(x == 0 || y == 0) {
        return 0;
    }
    if(dp[x][y] != -1)
    return dp[x][y];

    int ans = max(lcs(x - 1, y, s1,s2),lcs(x, y - 1,s1,s2));
    dp[x][y] = ans;
    
    if(s1[x - 1] == s2[y - 1]) {
        dp[x][y] = max(1 + lcs(x - 1, y - 1, s1, s2), dp[x][y]);
    }
    return dp[x][y];
}

int lcs(int x, int y, string s1, string s2){
    
    for(int i = 0;i <= x; i++) {
        for(int j = 0; j <= y; j++) {
            dp[x][y] = -1;
        }
    }
    return lcsUtil(x,y,s1,s2);
}
