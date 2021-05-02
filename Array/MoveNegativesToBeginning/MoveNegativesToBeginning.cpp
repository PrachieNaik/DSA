/*

Problem statement: Move all negative numbers to beginning and positive to end with constant extra space. An array contains both positive and negative numbers in 
random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.

Note: Order of elements is not important here.

Examples : 

Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5

Two Pointer Approach: The idea is to solve this problem with constant space and linear time is by using a two-pointer or two-variable approach where we simply 
take two variables like left and right which hold the 0 and N-1 indexes. Just need to check that :

    Check If the left and right pointer elements are negative then simply increment the left pointer.
    Otherwise, if the left element is positive and the right element is negative then simply swap the elements, and simultaneously increment and decrement the left
    and right pointers.
    Else if the left element is positive and the right element is also positive then simply decrement the right pointer.
    Repeat the above 3 steps until the left pointer ≤ right pointer.

Time Complexity: O(N)
Auxiliary Space: O(1)
*/

// Function to shift all the
// negative elements on left side
void shiftall(int arr[], int left,int right)
{
   
    // Loop to iterate over the
    // array from left to the right
    while (left<=right)
    {
        // Condition to check if the left
        // and the right elements are
        // negative
        if (arr[left] < 0 && arr[right] < 0)
          left+=1;
         
        // Condition to check if the left
        // pointer element is positive and
        // the right pointer element is negative
        else if (arr[left]>0 && arr[right]<0)
        {
            int temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
            left+=1;
            right-=1;
        }
         
        // Condition to check if both the
        // elements are positive
        else if (arr[left]>0 && arr[right] >0)
            right-=1;
        else{
            left += 1;
            right -= 1;
        }
    }
}
