/*

Problem statement: Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.

Example 1:

Input:
n = 1
Output: 5
Explanation : 5! = 120 which has at
least 1 trailing 0.

Constraints:
1 <= n <= 10^4

Trailing 0s in x! = Count of 5s in prime factors of x!
                  = floor(x/5) + floor(x/25) + floor(x/125) + ....
                  
We can notice that, the minimum value whose factorial contain n trailing zeroes is 5*n.
So, to find minimum value whose factorial contains n trailing zeroes, use binary search on range from 0 to 5*n. And, find the smallest number whose factorial 
contains n trailing zeroes. 

Time Complexity: O(log2 N * log5 N).
Auxiliary Space: O(1).

*/

// Return true if number's factorial contains
// at least n trailing zero else false.
bool check(int p, int n)
{
    int temp = p, count = 0, f = 5;
    while (f <= temp)
    {
        count += temp/f;
        f = f*5;
    }
    return (count >= n);
}
 
// Return smallest number whose factorial
// contains at least n trailing zeroes
int findNum(int n)
{
    // If n equal to 1, return 5.
    // since 5! = 120.
    if (n == 1)
        return 5;
 
    // Initalising low and high for binary
    // search.
    int low = 0;
    int high = 5 * n;
 
    // Binary Search.
    while (low < high)
    {
        int mid = (low + high) / 2;
 
        // Checking if mid's factorial contains
        // n trailing zeroes.
        if (check(mid, n))
            high = mid;
        else
            low = mid+1;
    }
 
    return low;
}
