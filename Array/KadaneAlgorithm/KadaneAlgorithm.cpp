/*

Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.

Kadane's Algorithm: Simple idea of the Kadane's algorithm is to look for all positive contiguous segments of the array (max_ending_here is used for this). And 
keep track of maximum sum contiguous segment among all positive segments (max_so_far is used for this). Each time we get a positive sum compare it with max_so_far 
and update max_so_far if it is greater than max_so_far

Time Complexity: O(n), Space Complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n){
    
    int max_so_far = 0;
    int max_ending_here = 0;
    for(int i=0;i<n;i++) {
        max_ending_here += arr[i];
        
        if(max_ending_here < 0)
            max_ending_here = 0;
            
        max_so_far = max(max_so_far,max_ending_here);
    }
    return max_so_far;
}

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}


/*To handle the case where all the elements are negative in the array:


#include<iostream>
using namespace std;

int maxSubArraySum(int a[], int size)
{
   int max_so_far = a[0];
   int curr_max = a[0];

   for (int i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);        //here
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}

int main()
{
   int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a, n);
   cout << "Maximum contiguous sum is " << max_sum;
   return 0;
}

*/
