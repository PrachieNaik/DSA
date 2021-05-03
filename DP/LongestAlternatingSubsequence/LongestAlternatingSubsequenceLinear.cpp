/*

Problem statement: A sequence {x1, x2, .. xn} is alternating sequence if its elements satisfy one of the following relations : 

  x1 < x2 > x3 < x4 > x5 < …. xn or 
  x1 > x2 < x3 > x4 < x5 > …. xn
  
Examples :

Input: arr[] = {1, 5, 4}
Output: 3
The whole arrays is of the form  x1 < x2 > x3 

Input: arr[] = {1, 4, 5}
Output: 2
All subsequences of length 2 are either of the form 
x1 < x2; or x1 > x2

Approach:
    In the dp approach,at any moment we are keeping track of two values (Length of the longest alternating subsequence ending at index i, and last element is
    smaller than or greater than previous element), for every element on array. To optimise space, we only need to store two variables for element at any index i. 

    inc = Length of longest alternative subsequence so far with current value being greater than it’s previous value.
    dec = Length of longest alternative subsequence so far with current value being smaller than it’s previous value.
    The tricky part of this approach is to update these two values. 
    
    “inc” should be increased, if and only if the last element in the alternative sequence was smaller than it’s previous element.
    “dec” should be increased, if and only if the last element in the alternative sequence was greater than it’s previous element.
    
Time Complexity: O(n) 
Auxiliary Space: O(1)

*/

// Function for finding
// longest alternating
// subsequence
int LAS(int arr[], int n)
{
 
    // "inc" and "dec" intialized as 1
    // as single element is still LAS
    int inc = 1;
    int dec = 1;
    
    // Iterate from second element
    for (int i = 1; i < n; i++)
    {
    
        if (arr[i] > arr[i - 1])
        {
    
            // "inc" changes iff "dec"
            // changes
            inc = dec + 1;
        }
    
        else if (arr[i] < arr[i - 1])
        {
    
            // "dec" changes iff "inc"
            // changes
            dec = inc + 1;
        }
}
