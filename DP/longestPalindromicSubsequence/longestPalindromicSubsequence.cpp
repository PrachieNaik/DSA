/*

Problem statement: Given a String, find the longest palindromic subsequence

Input: string S(only lowercase) -> bbabcbcab
Output: Print the Maximum length possible for palindromic subsequence -> 7

Constraints:
1<=T<=100
1<=|Length of String|<=1000

Approch: Reverse the given string and store it in another string. Apply lcs on both of these strings.

*/

int lcs(string s){
    
    int n = s.length();

    vector<vector<short>> dp(n, vector<short>(n));

    for(int i =0; i <n;i++)
    {
        dp[i][i] = 1;
    }

    for(int i = n-2; i >= 0; i--)
    {
        for(int j = i+1; j < n; j++)
        {   
            if(i > j)
            {
                dp[i][j] = 0;//12
            }
            else if(s[i] == s[j])
            {   
                //Next row , previous column
                dp[i][j] = 2 + dp[i+1][j-1];
            }
            else
            {   
                //prefix or suffix maximum
                dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
    }

    return dp[0][s.length() -1];
 
}
