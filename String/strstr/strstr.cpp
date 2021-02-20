/*

Implement the function strstr. The function takes two strings as arguments (s,x) and  locates the occurrence of the string x in the string s.
The function returns and integer denoting the first occurrence of the string x in s (0 based indexing).

Edge cases: Target string length is greater then given string. 

Method: The idea is to run a loop from start to end and for every index in the given string check whether the sub-string can be formed from that index. 
This can be done by running a nested loop traversing the given string and in that loop run another loop checking for sub-string from every index. 

Time complexity: O(m * n) where m and n are lengths of s1 and s2 respectively. A nested loop is used the outer loop runs from 0 to N-M and inner loop from 0 to M 
Space Complexity: O(1). 
*/

#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

/* The function should return position where the target string matches the string str */
int strstr(string s, string x)
{
     if(s.length() < x.length()) 
     return -1;
     
     for(int i=0; i<s.length()-x.length()+1 ;i++) {
         int indexOfS = i;
         int indexOfX = 0;
         while ( indexOfS < s.length() && indexOfX < x.length() && s[indexOfS] == x[indexOfX]
        ) {
             indexOfS ++;
             indexOfX ++;
         }
         if(indexOfX == x.length())
         return indexOfS - indexOfX;
     }
     return -1;
}
