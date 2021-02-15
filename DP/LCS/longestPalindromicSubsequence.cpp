/*

Problem statement: Given a String, find the longest palindromic subsequence

Input: string S(only lowercase) -> bbabcbcab
Output: Print the Maximum length possible for palindromic subsequence -> 7

Constraints:
1<=T<=100
1<=|Length of String|<=1000

Approch: Reverse the given string and store it in another string. Apply lcs on both of these strings.

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

int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    string s1;
	    cin>>s1;
	    string s2 = s1;
	    reverse(s2.begin(),s2.end());
	    cout<<lcs(s1.length(),s2.length(),s1,s2)<<endl;
	}
	return 0;
}
