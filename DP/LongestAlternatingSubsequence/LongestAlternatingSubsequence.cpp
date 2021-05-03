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
    This problem is an extension of longest increasing subsequence problem, but requires more thinking for finding optimal substructure property in this.
    We will solve this problem by dynamic Programming method, Let A is given array of length n of integers. We define a 2D array las[n][2] such that las[i][0] 
    contains longest alternating subsequence ending at index i and last element is greater than its previous element and las[i][1] contains longest alternating
    subsequence ending at index i and last element is smaller than its previous element, then we have following recurrence relation between them,  
    
    las[i][0] = Length of the longest alternating subsequence 
              ending at index i and last element is greater
              than its previous element
    las[i][1] = Length of the longest alternating subsequence 
              ending at index i and last element is smaller
              than its previous element
    
    Recursive Formulation:
       las[i][0] = max (las[i][0], las[j][1] + 1); 
                 for all j < i and A[j] < A[i] 
       las[i][1] = max (las[i][1], las[j][0] + 1); 
                 for all j < i and A[j] > A[i]
    The first recurrence relation is based on the fact that, If we are at position i and this element has to bigger than its previous element then for this
    sequence (upto i) to be bigger we will try to choose an element j ( < i) such that A[j] < A[i] i.e. A[j] can become A[i]’s previous element and las[j][1] + 1
    is bigger than las[i][0] then we will update las[i][0]. 
    Remember we have chosen las[j][1] + 1 not las[j][0] + 1 to satisfy alternate property because in las[j][0] last element is bigger than its previous one and
    A[i] is greater than A[j] which will break the alternating property if we update. So above fact derives first recurrence relation, similar argument can be made
    for second recurrence relation also.
    
Time Complexity: O(n^2) 
Auxiliary Space: O(n)

*/

// Function to return longest alternating
// subsequence length
int zzis(int arr[], int n)
{
     
    /*las[i][0] = Length of the longest
        alternating subsequence ending at
        index i and last element is greater
        than its previous element
    las[i][1] = Length of the longest
        alternating subsequence ending
        at index i and last element is
        smaller than its previous element */
    int las[n][2];
  
    // Initialize all values from 1
    for(int i = 0; i < n; i++)
        las[i][0] = las[i][1] = 1;
     
    // Initialize result
    int res = 1;
  
    // Compute values in bottom up manner
    for(int i = 1; i < n; i++)
    {
         
        // Consider all elements as
        // previous of arr[i]
        for(int j = 0; j < i; j++)
        {
             
            // If arr[i] is greater, then
            // check with las[j][1]
            if (arr[j] < arr[i] &&
                las[i][0] < las[j][1] + 1)
                las[i][0] = las[j][1] + 1;
  
            // If arr[i] is smaller, then
            // check with las[j][0]
            if(arr[j] > arr[i] &&
               las[i][1] < las[j][0] + 1)
                las[i][1] = las[j][0] + 1;
        }
  
        // Pick maximum of both values at index i
        if (res < max(las[i][0], las[i][1]))
            res = max(las[i][0], las[i][1]);
    }
    return res;
}
