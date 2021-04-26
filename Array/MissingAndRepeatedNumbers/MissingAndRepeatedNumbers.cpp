/*

Problem statement: Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in
array. Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.

Method 1 (Use Sorting):

    Sort the input array.
    Traverse the array and check for missing and repeating.
    Time Complexity: O(nLogn)

Method 2 (Use count array):

    Create a temp array temp[] of size n with all initial values as 0.
    Traverse the input array arr[], and do following for each arr[i] 
    if(temp[arr[i]] == 0) temp[arr[i]] = 1;
    if(temp[arr[i]] == 1) output “arr[i]” //repeating
    Traverse temp[] and output the array element having value as 0 (This is the missing element)
    
    Time Complexity: O(n)
    Auxiliary Space: O(n)

Method 3 (Swap sort):
    Refer: https://www.youtube.com/watch?v=uo4kuV3pWfE
    Time Complexity: O(n)
    Auxiliary Space: O(1)
*/

int *findTwoElement(int *arr, int n) {

   for(int i = 0; i < n;) {
       if(arr[i] != arr[arr[i] - 1]) {
            swap(arr[i], arr[arr[i]-1]);
       } else {
           i++;
       }
   }
   int* ans = new int [2];
   for(int i = 0;i < n;i++) {
       if(arr[i] != i + 1) {
           ans[1] = i + 1; //missing
           ans[0] = arr[i]; //duplicate
       }
   }
   return ans;
}
