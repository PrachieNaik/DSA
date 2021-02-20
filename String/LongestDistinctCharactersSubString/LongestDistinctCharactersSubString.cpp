/*

Given a string S, find length of the longest substring with all distinct characters.

Method 1 : The idea is to scan the string from left to right, keep track of the maximum length Non-Repeating Character Substring seen so far in res. When we 
traverse the string, to know the length of current window we need two indexes. 
1) Ending index ( j ) : We consider current index as ending index. 
2) Starting index ( i ) : It is same as previous window if current character was not present in the previous window. To check if the current character was present 
in the previous window or not, we store last index of every character in an array lasIndex[]. If lastIndex[str[j]] + 1 is more than previous start, then we updated 
the start index i. Else we keep same i. 

Time Complexity: O(n + d) where n is length of the input string and d is number of characters in input string alphabet. For example, if string consists of 
lowercase English characters then value of d is 26. 
Auxiliary Space: O(d) 


*/


#include <bits/stdc++.h>
using namespace std;
int longestUniqueSubsttr(string str) 
{ 
    int n = str.size(); 
  
    int result = 0; 
  
    // last index of all characters is initialized as -1 
    vector<int> lastIndex(256, -1); 
  
    // Initialize start of current window 
    int start = 0; 
  
    // Move end of current window 
    for (int end = 0; end < n; end++) { 
  
        // Find the last index of str[j] Update i (starting index of current window) as maximum of current value of i and last index plus 1 
        start = max(start, lastIndex[str[end]] + 1); 
  
        // Update result if we get a larger window 
        result = max(result, end - start + 1); 
  
        // Update last index of j. 
        lastIndex[str[end]] = end; 
    } 
    return result; 
} 
int main()
 {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<longestUniqueSubsttr(s)<<endl;
	}
	return 0;
}
