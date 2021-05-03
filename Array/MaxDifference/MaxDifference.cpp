/*

Problem statement: Given an array arr[] of integers, find out the maximum difference between any two elements such that larger element appears after the smaller
number. 

Examples : 
Input : arr = {2, 3, 10, 6, 4, 8, 1}
Output : 8
Explanation : The maximum difference is between 10 and 2.

Method 1 (Simple) : Use two loops. In the outer loop, pick elements one by one and in the inner loop calculate the difference of the picked element with every
other element in the array and compare the difference with the maximum difference calculated so far.
    
    Time Complexity : O(n^2) 
    Auxiliary Space : O(1)

Method 2: In this method, instead of taking difference of the picked element with every other element, we take the difference with the minimum element found so
far. So we need to keep track of 2 things: 
    1) Maximum difference found so far (max_diff). 
    2) Minimum number visited so far (min_element).
    
    Time Complexity : O(n) 
    Auxiliary Space : O(1)
*/

/* The function assumes that there are at least two elements in array. The function returns a negative value if the array is sorted in decreasing order and
returns 0 if elements are equal */
int maxDiff(int arr[], int arr_size)
{
    // Maximum difference found so far
    int max_diff = arr[1] - arr[0];
    
    // Minimum number visited so far
    int min_element = arr[0];
    for(int i = 1; i < arr_size; i++)
    {    
        if (arr[i] - min_element > max_diff)                            
        max_diff = arr[i] - min_element;
        
        if (arr[i] < min_element)
        min_element = arr[i];                    
    }
    
    return max_diff;
}
