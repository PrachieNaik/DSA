/*

Problem statement: Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element key. The task is to find the 
index of the given element key in the array A.

Input: N = 9, A[] = {5 ,6 ,7 ,8 ,9 ,10 ,1 ,2 ,3}, key = 10
Output: 5
Explanation: 10 is found at index 5.

Constraints: 1 ≤ N ≤ 10^7, 0 ≤ A[i] ≤ 10^8 , 1 ≤ key ≤ 10^8

Approach: Instead of two or more pass of binary search the result can be found in one pass of binary search. The binary search needs to be modified to perform the 
search. The idea is to create a recursive function that takes l and r as range in input and the key.

1) Find middle point mid = (l + h)/2
2) If key is present at middle point, return mid.
3) Else If arr[l..mid] is sorted
    a) If key to be searched lies in range from arr[l]
       to arr[mid], recur for arr[l..mid].
    b) Else recur for arr[mid+1..h]
4) Else (arr[mid+1..h] must be sorted)
    a) If key to be searched lies in range from arr[mid+1]
       to arr[h], recur for arr[mid+1..h].
    b) Else recur for arr[l..mid] 
    
Complexity Analysis:

Time Complexity: O(log n). Binary Search requires log n comparisons to find the element. So time complexity is O(log n).
Space Complexity: O(1). As no extra space is required.

How to handle duplicates?
It doesn’t look possible to search in O(Logn) time in all cases when duplicates are allowed. For example consider searching 0 in {2, 2, 2, 2, 2, 2, 2, 2, 0, 2} and
{2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}.It doesn’t look possible to decide whether to recur for the left half or right half by doing a constant number of comparisons
at the middle.

*/

int search(int a[], int l, int h, int key){
    if (l > h) 
        return -1; 
    int mid = (l + h)/2;
    if(a[mid] == key) 
    return mid;
    
    if(a[l] <= a[mid]) {
        if(key >= a[l] && key < a[mid]) {
            return search(a,l,mid - 1,key);
        } else {
            return search(a,mid + 1,h,key);
        }
    } else {
        if(key >= a[mid+1] && key < a[h]) {
            return search(a,mid + 1,h,key);
        } else {
            return search(a,l,mid - 1,key);
        }
    }
}
