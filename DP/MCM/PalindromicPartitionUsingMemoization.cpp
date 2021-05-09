/*

Problem statement: Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome.
Determine the fewest cuts needed for palindrome partitioning of given string.

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings are "a", "babbbab", "b", "ababa".

Approch: memoization

*/

int dp[501][501];
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
    
    if(dp[i][j] != -1)
    return dp[i][j];
    
    int ans = INT_MAX;
    for(int k = i;k <= j-1; k++) {
        int temp = palindromicPartitionUtil(str,i,k) 
                    + palindromicPartitionUtil(str,k + 1,j) 
                    + 1;
                    
        ans = min(ans,temp);
    }
    dp[i][j] = ans;
    return ans;
}
int palindromicPartition(string str)
{
    memset(dp,-1,sizeof(dp));
    return palindromicPartitionUtil(str,0,str.length() - 1);
    
}
