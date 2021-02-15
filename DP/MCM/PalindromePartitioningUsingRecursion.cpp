/*

Problem statement: Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of given string.

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings are "a", "babbbab", "b", "ababa".

Approch: This problem is a variation of Matrix Chain Multiplication problem. If the string is a palindrome, then we simply return 0. Else, like the Matrix Chain Multiplication problem, we try making cuts at all possible places, recursively calculate the cost for each cut and return the minimum value. 
    Let the given string be str and minPalPartion() be the function that returns the fewest cuts needed for palindrome partitioning. 

    // i is the starting index and j is the ending index. i must be passed as 0 and j as n-1
    
    minPalPartion(str, i, j) = 0 if i == j. // When string is of length 1.
    
    minPalPartion(str, i, j) = 0 if str[i..j] is palindrome.
    
    // If none of the above conditions is true, then minPalPartion(str, i, j) can be 
    
    // calculated recursively using the following formula.
    
    minPalPartion(str, i, j) = Min { minPalPartion(str, i, k) + 1 + minPalPartion(str, k+1, j) } where k varies from i to j-1

*/

bool isPalindrom(string s,int i, int j) {
    while(i < j) {
        if(s[i] != s[j])
        return 0;
        i++;
        j--;
    }
    return 1;
}
int palindromicPartitionUtil(string str, int i, int j) {
    if(i >= j)
    return 0;
    
    if(isPalindrom(str,i,j)) 
    return 0;
    
    int ans = INT_MAX;
    for(int k = i;k <= j-1; k++) {
        int temp = palindromicPartitionUtil(str,i,k) 
                    + palindromicPartitionUtil(str,k + 1,j) 
                    + 1;
                    
        ans = min(ans,temp);
    }
    return ans;
}
int palindromicPartition(string str)
{
    return palindromicPartitionUtil(str,0,str.length() - 1);
    
}
