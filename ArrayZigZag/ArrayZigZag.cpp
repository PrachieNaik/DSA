/*

Given an array of DISTINCT elements, rearrange the elements of array in zig-zag fashion.
Note: this solution will only work for distinct elements.



Method 1: First sort the array. After sorting, exclude the first element, swap the remaining elements in pairs. (i.e. keep arr[0] as it is, swap arr[1] and arr[2], swap arr[3] and arr[4], and so on). 

Time complexity: O(N log N) since we need to sort the array first.



Method 2: The idea is to use a modified one pass of bubble sort.

Maintain a flag (or check for odd-even index) for representing which order(i.e. < or >) currently we need. If the current two elements are not in that order then swap those elements otherwise not. 
Suppose we are processing B and C currently and the current relation is ‘<‘, but we have B > C. Since current relation is ‘<‘ previous relation must be ‘>’ i.e., A must be greater than B. So, the relation is A > B and B > C. We can deduce A > C. So if we swap B and C then the relation is A > C and C < B. Finally we get the desired order A C B 

Time Complexity: O(n), Space Complexity: O(1)

*/

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:	

	void zigZag(int arr[], int n) {
  
        for (int i=0; i<n-1; i++)  
        {  
            if (i%2 == 0) {
                if (arr[i] > arr[i+1])  
                    swap(arr[i], arr[i+1]);  
            }  
            else {
                if (arr[i] < arr[i+1])  {
                    swap(arr[i], arr[i+1]);  
                }
            }  
        }  
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.zigZag(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
