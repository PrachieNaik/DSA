/*

Problem statement: Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. The possible operations
are:

    Insert
    Remove
    Replace

Input: s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required inserting 's' between two 'e's of str1.

Constraints:
1 <= Length of both strings <= 100. Both the strings are in lowercase.

Keywords: Minimum

Approach: Dynamic Programming

Time complexity: O(S * T), S = length of string 1, T = length of string 2
Space complexity: O(S * T)

Note: The claim that edit distance = length of s1 + length of s2 - (2*LCS) will not work here as replace operation is also allowed.
    
    Consider the case: S1 = abc, S2 = def.
    If only insertion and deletion is allowed then edit distance will be 6.
    If relacement is also allowed then edit distance will be 3.
*/

int editDistDP(string str1, string str2, int m, int n)
{
    // Create a table to store results of subproblems
    int dp[m + 1][n + 1];

    // Fill d[][] in bottom up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If first string is empty, only option is to
            // insert all characters of second string
            if (i == 0)
                dp[i][j] = j; // Min. operations = j

            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i

            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            // If the last character is different, consider
            // all possibilities and find the minimum
            else
                dp[i][j] = 1 + min(
                            dp[i][j - 1], // Insert
                            dp[i - 1][j], // Remove
                            dp[i - 1][j - 1] // Replace
                        ); 
        }
    }

    return dp[m][n];
}
