/*

Given a string, recursively remove adjacent duplicate characters from the string. The output string should not have any adjacent duplicates.

Method 1: Keep removing duplicate characters till we reach a new character.
Worst case time complexity: O(n^2). Space complexity: O(n). 

string removedupli(string s) {
    string result;
    int resultIndex = 0;
    int i = 0;
    while(i < s.length()) {
        if(s[i] == s[i+1]) {
            int left = i;
            int right = i+2;
            while(right <s.length() && s[left] == s[right]) {
                right++;
            }
            i = right;
        }
        else {
            result.insert(resultIndex++, 1, s[i++]);
        }
    }
    if(s.length() != result.length())
        return removedupli(result);
        
    return result;
}


Method: Check for previous and next characters of current character, if none of them are same then we can add current character in the output string of that iteration. Do this till we don't find any consecutively same character in current iteration. 
Worst case: Even length palindrome
Worst case time complexity: O(n^2). Space complexity: O(n). 

*/

#include <bits/stdc++.h>
using namespace std;
string removeDupli(string s)
{
    string temp;
    if(s[0]!=s[1])
    temp+=s[0];
    int i=1;
    while(i<s.length())
    {
        if(s[i]!=s[i-1] && s[i]!=s[i+1])
        temp+=s[i];
        i++;
    }
    if(temp.length()==0)
    return temp;
    if(temp.length()!=s.length())
    return removeDupli(temp);
    return temp;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    s=removeDupli(s);
	    cout<<s<<endl;
	}
	
	return 0;
}
