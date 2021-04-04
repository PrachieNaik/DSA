/**

Given an array A of N positive numbers. WAP to find the first Equilibium Point in the array. Equilibrium Point in an array is a position such that the sum of 
elements before it is equal to the sum of elements after it.

The idea is to get the total sum of the array first. Then Iterate through the array and keep updating the left sum which is initialized as zero. In the loop, we 
can get the right sum by subtracting the elements one by one. 

**/


// C++ program to find equilibrium 
// index of an array 
#include <bits/stdc++.h>
using namespace std;

int equilibrium(int arr[], int n) 
{ 
    int sum = 0; // initialize sum of whole array 
    int leftsum = 0; // initialize leftsum 

    /* Find sum of the whole array */
    for (int i = 0; i < n; ++i) 
        sum += arr[i]; 

    for (int i = 0; i < n; ++i) 
    { 
        sum -= arr[i]; // sum is now right sum for index i 

        if (leftsum == sum) 
            return i; 

        leftsum += arr[i]; 
    } 

    /* If no equilibrium index found, then return -1 */
    return -1; 
} 

// Driver code 
int main() 
{ 
    int arr[] = { -7, 1, 5, 2, -4, 3, 0 }; 
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
    cout << "First equilibrium index is " << equilibrium(arr, arr_size); 
    return 0; 
} 

//Time complexity: O(n), Space complexity: O(1)
