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

Approch: DP

*/

int lcs(int x, int y, string s1, string s2){
    
    int dp[x + 1][y + 1];
    for(int i = 0;i <= x; i++) {
        for(int j = 0; j <= y; j++) {
            dp[i][j] = 0;
        }
    }
    for(int i = 1;i <= x; i++) {
        for(int j = 1; j <= y; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
            } 
        }
    }
    return dp[x][y];
}
