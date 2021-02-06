/*

Find the element before which all the elements are smaller than it, and after which all are greater.

Method: Create two arrays leftMax[] and rightMin[].
Traverse input array from left to right and fill leftMax[] such that leftMax[i] contains a maximum element from 0 to i-1 in the input array.
Traverse input array from right to left and fill rightMin[] such that rightMin[i] contains a minimum element from to n-1 to i+1 in the input array.
Traverse input array. For every element arr[i], check if arr[i] is greater than leftMax[i] and smaller than rightMin[i]. If yes, return i.
Further Optimization to the above approach is to use only one extra array and traverse input array only twice. The first traversal is the same as above and fills leftMax[]. Next traversal traverses from the right and keeps track of the minimum. The second traversal also finds the required element. This method will return first valid element from right.

Time Complexity:  O(n) , Auxiliary Space: O(1).

*/

#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

int findElement(int a[], int n) {
    int rmin[n];
    rmin[n-1]=a[n-1];
    
    for(int i=n-2;i>=0;i--)
    {
        rmin[i]=min(rmin[i+1],a[i]);
    }
    
    int lmax = a[0];
    for(int i=1;i<n-1;i++)
    {
        lmax=max(lmax,a[i]);
        
        if(lmax<=a[i] && rmin[i]>=a[i])
        {
            return a[i];
        }
    }
    
    return -1;
}
