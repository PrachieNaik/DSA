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

Algorithm: 

Create a DP array (matrix) of size M*N, where m is the size of the first string and n is the size of the second string. Initialize the matrix to false.
If the sum of sizes of smaller strings is not equal to the size of the larger string then return false and break the array as they cant be the interleaved to
form the larger string.
Run a nested loop the outer loop from 0 to m and the inner loop from 0 to n. Loop counters are i and j.
If the values of i and j are both zeroes then mark dp[i][j] as true. If the value of i is zero and j is non zero and the j-1 character of B is equal to j-1 
character of C the assign dp[i][j] as dp[i][j-1] and similarly if j is 0 then match i-1 th character of C and A and if it matches then assign dp[i][j] as dp[i-1][j].
Take three characters x, y, z as (i-1)th character of A and (j-1)th character of B and (i + j – 1)th character of C.
if x matches with z and y does not match with z then assign dp[i][j] as dp[i-1][j] similarly if x is not equal to z and y is equal to z then assign dp[i][j] 
as dp[i][j-1]
if x is equal to y and y is equal to z then assign dp[i][j] as bitwise OR of dp[i][j-1] and dp[i-1][j].
return value of dp[m][n].
  
Complexity Analysis: 

Time Complexity: O(M*N). 
Since a traversal of DP array is needed, so the time complexity is O(M*N).
Space Complexity: O(M*N). 
This is the space required to store the DP array.

*/

bool isInterleave(string A, string B, string C) 
    {
        int len1 = A.length();
        int len2 = B.length();
        int len3 = C.length();
        
        if(len1 + len2 != len3)
        return false;
        
        int IL[len1+1][len2+1];
        
        for (int i = 0; i <= len1; ++i) {
            for (int j = 0; j <= len2; ++j) {
                
                IL[i][j] = 0;
                // two empty strings have an
                // empty string as interleaving
                if (i == 0 && j == 0)
                    IL[i][j] = 1;
     
                // A is empty
                else if (i == 0) {
                    if (B[j - 1] == C[j - 1])
                        IL[i][j] = IL[i][j - 1];
                }
     
                // B is empty
                else if (j == 0) {
                    if (A[i - 1] == C[i - 1])
                        IL[i][j] = IL[i - 1][j];
                }
     
                // Current character of C matches
                // with current character of A,
                // but doesn't match with current
                // character of B
                else if ( A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1])
                    IL[i][j] = IL[i - 1][j];
     
                // Current character of C matches
                // with current character of B,
                // but doesn't match with current
                // character of A
                else if ( A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1])
                    IL[i][j] = IL[i][j - 1];
     
                // Current character of C matches
                // with that of both A and B
                else if ( A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1])
                    IL[i][j] = (IL[i - 1][j] || IL[i][j - 1]);
            }
        }
 
        return IL[len1][len2];
    }
