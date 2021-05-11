/*

Problem statement: Find number of times a string occurs as a subsequence in given string

Examples: 

Input:  
string a = "GeeksforGeeks"
string b = "Gks"

Output: 4

Explanation:  
The four strings are - (Check characters marked in bold)
GeeksforGeeks
GeeksforGeeks
GeeksforGeeks
GeeksforGeeks

Approach: 
If we carefully analyze the given problem, we can see that it can be easily divided into sub-problems. The idea is to process all characters of both strings
one by one staring from either from left or right side. Let us traverse from right corner, there are two possibilities for every pair of character being traversed. 

m: Length of str1 (first string)
n: Length of str2 (second string)

If last characters of two strings are same, 
   1. We consider last characters and get count for remaining strings. So we recur for lengths m-1 and n-1. 
   2. We can ignore last character of first string and recurse for lengths m-1 and n.
else 
If last characters are not same, 
   We ignore last character of first string and recurse for lengths m-1 and n.
  
Time Complexity : O(n^m)
Space Complexity : O(n^m)
*/

// Iterative DP function to find the number of times
// the second string occurs in the first string,
// whether continuous or discontinuous
int count(string a, string b)
{
    int m = a.length();
    int n = b.length();
 
    // Create a table to store results of sub-problems
    int lookup[m + 1][n + 1] = { { 0 } };
 
    // If first string is empty
    for (int i = 0; i <= n; ++i)
        lookup[0][i] = 0;
 
    // If second string is empty
    for (int i = 0; i <= m; ++i)
        lookup[i][0] = 1;
 
    // Fill lookup[][] in bottom up manner
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // If last characters are same, we have two
            // options -
            // 1. consider last characters of both strings in solution
            // 2. ignore last character of first string
            if (a[i - 1] == b[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1] +
                               lookup[i - 1][j];
                 
            else
                // If last character are different, ignore
                // last character of first string
                lookup[i][j] = lookup[i - 1][j];
        }
    }
 
    return lookup[m][n];
}
