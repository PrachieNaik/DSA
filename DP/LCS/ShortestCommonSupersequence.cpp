/*

Problem statement: Given two strings str1 and str2, the task is to find the length of the shortest string that has both str1 and str2 as subsequences.

Input:   str1 = "geek",  str2 = "eke"
Output: 5
Explanation: 
String "geeke" has both string "geek" 
and "eke" as subsequences.

Constraints:
1<=n, m<=1000

Approch: 1) Find Longest Common Subsequence (lcs) of two given strings. For example, lcs of “geek” and “eke” is “ek”. 
    2) Insert non-lcs characters (in their original order in strings) to the lcs found above, and return the result. So “ek” becomes “geeke” which is shortest 
    common supersequence.
    How does this work? 
    We need to find a string that has both strings as subsequences and is shortest such string. If both strings have all characters different, then result is sum 
    of lengths of two given strings. If there are common characters, then we don’t want them multiple times as the task is to minimize length. Therefore, we first
    find the longest common subsequence, take one occurrence of this subsequence and add extra characters. 

    Length of the shortest supersequence  = (Sum of lengths of given two strings) - (Length of LCS of two given strings) 

Time Complexity: O(m*n) 
Auxiliary Space: O(m*n)

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

//User function template for C++

// X : 1st given string of size m
// Y : 2nd given string of size n
int shortestCommonSupersequence(char* X, char* Y, int m, int n) {
 
    // find lcs
    int l = lcs(m, n, X, Y);
 
    // Result is sum of input string
    // lengths - length of lcs
    return (m + n - l);
}
