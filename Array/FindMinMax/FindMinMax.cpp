/**
WAP to find maximum and minimum of an array using minimum number of comparisons.



Method 1: Simple linear search
In this method, the total number of comparisons is 1 + 2(n-2) in the worst case and 1 + n – 2 in the best case. 
Worst case: elements are sorted in descending order 
Best case: elements are sorted in ascending order.



Method 2: Divide the array into two parts and compare the maximums and minimums of the two parts to get the maximum and the minimum of the whole array.
Number of comparisons T(n) = T(floor(n/2)) + T(ceil(n/2)) + 2  , T(2) = 1, T(1) = 0
This approach does 3n/2 -2 comparisons if n is a power of 2. And it does more than 3n/2 -2 comparisons if n is not a power of 2.



METHOD 3: Compare in Pairs
If n is odd then initialize min and max as first element. 
If n is even then initialize min and max as minimum and maximum of the first two elements respectively. 
For rest of the elements, pick them in pairs and compare their 
maximum and minimum with max and min respectively. 
Number of comparisions:
If n is odd: 3*(n-1)/2  
If n is even: 1 Initial comparison for initializing min and max, 
and 3(n-2)/2 comparisons for rest of the elements  =  1 + 3*(n-2)/2 = 3n/2-2


**/


#include<iostream> 
using namespace std; 
 
// Structure is used to return 
// two values from minMax() 
struct Pair 
{ 
    int min; 
    int max; 
}; 
 
struct Pair getMinMax(int arr[], int n) 
{ 
    struct Pair minmax;     
    int i; 
     
    // If array has even number of elements 
    // then initialize the first two elements 
    // as minimum and maximum 
    if (n % 2 == 0) 
    { 
        if (arr[0] > arr[1])     
        { 
            minmax.max = arr[0]; 
            minmax.min = arr[1]; 
        } 
        else
        { 
            minmax.min = arr[0]; 
            minmax.max = arr[1]; 
        } 
         
        // Set the starting index for loop 
        i = 2; 
    } 
     
    // If array has odd number of elements 
    // then initialize the first element as 
    // minimum and maximum 
    else
    { 
        minmax.min = arr[0]; 
        minmax.max = arr[0]; 
         
        // Set the starting index for loop 
        i = 1; 
    } 
     
    // In the while loop, pick elements in 
    // pair and compare the pair with max 
    // and min so far 
    while (i < n - 1) 
    {         
        if (arr[i] > arr[i + 1])         
        { 
            if(arr[i] > minmax.max)     
                minmax.max = arr[i]; 
                 
            if(arr[i + 1] < minmax.min)         
                minmax.min = arr[i + 1];     
        } 
        else       
        { 
            if (arr[i + 1] > minmax.max)     
                minmax.max = arr[i + 1]; 
                 
            if (arr[i] < minmax.min)         
                minmax.min = arr[i];     
        } 
         
        // Increment the index by 2 as 
        // two elements are processed in loop 
        i += 2; 
    }         
    return minmax; 
} 
 
// Driver code 
int main() 
{ 
    int arr[] = { 1000, 11, 445, 1, 330, 3000 }; 
    int arr_size = 6; 
     
    Pair minmax = getMinMax(arr, arr_size); 
     
    cout << "nMinimum element is "<< minmax.min << endl; 
    cout << "nMaximum element is "<< minmax.max; 
         
    return 0; 
} 


// time complexity: O(N), auxiliary space complexity O(1)
