/*

Problem statement: Given an array and a positive integer k, find the first negative integer for each window(contiguous subarray) of size k. If a window does not 
contain a negative integer, then print 0 for that window.

Examples:  

Input : arr[] = {-8, 2, 3, -6, 10}, k = 2
Output : -8 0 -6 -6
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6

Input : arr[] = {12, -1, -7, 8, -15, 30, 16, 28} , k = 3
Output : -1 -1 -7 -15 -15 0

Approach 1:
It is a variation of the problem of Sliding Window Maximum. 
We create a Dequeue, Di of capacity k, that stores only useful elements of the current window of k elements. An element is useful if it is in the current window
and it is a negative integer. We process all array elements one by one and maintain Di to contain useful elements of current window and these useful elements are 
all negative integers. For a particular window, if Di is not empty then the element at front of the Di is the first negative integer for that window, else that 
window does not contain a negative integer.

    Time Complexity: O(n) 
    Auxiliary Space: O(k)

Approach 2: 
It is also possible to accomplish this with constant space. The idea is to have a variable firstNegativeIndex to keep track of the first negative element in the k 
sized window. At every iteration, we skip the elements which no longer fall under the current k size window (firstNegativeIndex <= i – k) as well as the positive 
elements. 

Time Complexity: O(n) 
Auxiliary Space: O(1)

*/

void printFirstNegativeInteger(int arr[], int k, int n)
{
    int firstNegativeIndex = 0;
    int firstNegativeElement;
     
    
    for(int i = k - 1; i < n; i++)
    {
       
        // skip out of window and positive elements
        while((firstNegativeIndex < i ) &&
              (firstNegativeIndex <= i - k ||
               arr[firstNegativeIndex] > 0))
        {
            firstNegativeIndex ++;
        }
         
        // check if a negative element is found, otherwise use 0
        if(arr[firstNegativeIndex] < 0)
        {
            firstNegativeElement = arr[firstNegativeIndex];
        }
        else
        {
            firstNegativeElement = 0;
        }
        cout<<firstNegativeElement << " ";
    }
     
}
 
