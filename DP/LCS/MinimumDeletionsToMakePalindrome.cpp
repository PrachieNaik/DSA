/*

Problem statement: Given a string of S as input. Your task is to write a program to remove or delete minimum number of characters from the string so that the 
resultant string is palindrome.

Note: The order of characters in the string should be maintained.

Input: string S(only lowercase) -> geeksforgeeks
Output: Print the deletions required to make the string palindrome. -> 8

Constraints:
1<=T<=100
1<=length(S)<=10000

Approch: Reverse the given string and store it in another string. Apply lcs on both of these strings. We will get the maximum possible length of palindromic
sequence present in the string. We will get the required number of deletion by subtracting this value from length of string.

Node: This problem can also be asked as minimum number of insertion, the answer or code will not change
*/

#include <bits/stdc++.h>
using namespace std;
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
	    int lcsCount = lcs(s1.length(),s2.length(),s1,s2);
	    cout<< s1.length() - lcsCount<< endl;
	}
	return 0;
}
