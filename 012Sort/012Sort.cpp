/**
WAP to sort an array of 0s, 1s and 2s


Method 1: Count the number of 0s, 1s and 2s in the given array. Then store all the 0s in the beginning followed by all the 1s then all the 2s.
Time Complexity: O(n). Space Complexity: O(1).


Method 2: Dutch National Flag Algorithm OR 3-way Partitioning:
At first, the full array is unknown. There are three indices – low, mid and high. Initially, the value of low = mid = 1 and high = N.
If the ith element is 0 then swap the element to the low range, thus shrinking the unknown range.
Similarly, if the element is 1 then keep it as it is but shrink the unknown range.
If the element is 2 then swap it with an element in high range.

**/



#include <bits/stdc++.h> 
using namespace std; 
  
// Function to sort the input array, 
// the array is assumed 
// to have values in {0, 1, 2} 
void sort012(int a[], int arr_size) 
{ 
    int lo = 0; 
    int hi = arr_size - 1; 
    int mid = 0; 
  
    // Iterate till all the elements 
    // are sorted 
    while (mid <= hi) { 
        switch (a[mid]) { 
  
        // If the element is 0 
        case 0: 
            swap(a[lo++], a[mid++]); 
            break; 
  
        // If the element is 1 . 
        case 1: 
            mid++; 
            break; 
  
        // If the element is 2 
        case 2: 
            swap(a[mid], a[hi--]); 
            break; 
        } 
    } 
} 
  
// Function to print array arr[] 
void printArray(int arr[], int arr_size) 
{ 
    // Iterate and print every element 
    for (int i = 0; i < arr_size; i++) 
        cout << arr[i] << " "; 
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    sort012(arr, n); 
  
    cout << "array after segregation "; 
  
    printArray(arr, n); 
  
    return 0; 
} 

// time complexity: O(N), auxiliary space complexity O(1)
