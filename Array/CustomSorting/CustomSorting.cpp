/*

Given an array of numbers, arrange them in a way that yields the largest value. For example, if the given numbers are {54, 546, 548, 60}, the arrangement 
6054854654 gives the largest value. And if the given numbers are {1, 34, 3, 98, 9, 76, 45, 4}, then the arrangement 998764543431 gives the largest value.

Method: Given two numbers X and Y, how should myCompare() decide which number to put first – we compare two numbers XY (Y appended at the end of X) and YX 
(X appended at the end of Y). If XY is larger, then X should come before Y in output, else Y should come before. For example, let X and Y be 542 and 60. To compare
X and Y, we compare 54260 and 60542. Since 60542 is greater than 54260, we put Y first.

Time Complexity:  O(nlogn) ,sorting is considered to have running time complexity of O(nlogn) and the for loop runs in O(n) time.

Auxiliary Space: O(1).

*/

#include <bits/stdc++.h>
using namespace std;

int mycomp (string x, string y) {
    string xy = x+y;
    string yx = y+x;
    return xy>yx;
}

class Solution{
public:
	string printLargest(vector<string> &arr) {
	    
	    sort(arr.begin(),arr.end(),mycomp);
	    
	    string ans;
	    for (int i = 0; i < arr.size(); i++)
            ans+=arr[i];
        return ans;
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}
