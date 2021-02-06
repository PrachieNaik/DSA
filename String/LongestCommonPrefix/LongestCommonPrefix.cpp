/*

Given a array of N strings, find the longest common prefix among all strings present in the array.

Edge cases: When all the strings are equal

Method: Go through the characters one by one.

Since we will iterate through all the characters of all the strings in worst case, so we can say that the time complexity is O(N M) where,
N = Number of strings
M = Length of the largest string string 

Auxiliary Space : To store the longest prefix string we are allocating space which is O(M).

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
   string longestCommonPrefix(string arr[],int n){
        int index = 0;
        int characterAtIndex;
        bool flag = 0;
        string ans;
        for(int index = 0; index < arr[0].size(); index++) {
            characterAtIndex = arr[0][index];
            for(int i=1; i<n; i++) {
                if(arr[i][index] != characterAtIndex) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                ans += characterAtIndex;
            } else {
                break;
            }
            
        }
        if(ans.length() == 0)
        return "-1";
        else
        return ans;

}

};

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}
