/*

Problem statement: Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete and insert the minimum number of characters 
from/in str1 to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some
another point.

Input : 
str1 = "heap", str2 = "pea" 

Output : 
Minimum Deletion = 2 and
Minimum Insertion = 1

Explanation:
p and h deleted from heap. Then, p is inserted at the beginning. One thing to note, though p was required yet it was removed/deleted first from its position and
then it is inserted to some other position. Thus, p contributes one to the deletion_count and one to the insertion_count.

Constraints:
1 ≤ |str1|, |str2| ≤ 1000
All the characters are lower case English alphabets

Approch: An efficient approach uses the concept of finding the length of the longest common subsequence of the given two sequences.
    str1 and str2 be the given strings.
    m and n be their lengths respectively.
    len be the length of the longest common subsequence of str1 and str2
    minimum number of deletions minDel = m – len
    minimum number of Insertions minInsert = n – len

*/

int minOperations(string str1, string str2) 
{ 
    int m = str1.length();
    int n = str2.length();
    int L[m+1][n+1]; 
    for (int i=0; i<=m; i++) { 
        for (int j=0; j<=n; j++) { 
            if (i == 0 || j == 0) 
                L[i][j] = 0; 
            else if (str1[i-1] == str2[j-1]) 
                L[i][j] = L[i-1][j-1] + 1; 
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]); 
        } 
    } 
    // no of adition = str2.length - lcs
    // no of deletion = str1.length - lcs
    // hence total = str1.length + str2.length - 2*lcs
    return m + n - 2 * L[m][n];
} 
