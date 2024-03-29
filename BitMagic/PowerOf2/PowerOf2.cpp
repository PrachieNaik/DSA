/*

Problem statement: Given a positive integer N. The task is to check if N is a power of 2. More formally, check if N can be expressed as 2^x for some x.

Constraints:
0 <= N <= 1018

Approaches: 

Method 1: All power of two numbers has only a one-bit set. So count the no. of set bits and if you get 1 then the number is a power of 2.

Method 2: If we subtract a power of 2 numbers by 1 then all unset bits after the only set bit become set; and the set bit becomes unset.

    For example for 4 ( 100) and 16(10000), we get the following after subtracting 1 
    3 –> 011 
    15 –> 01111
    
    So, if a number n is a power of 2 then bitwise & of n and n-1 will be zero. We can say n is a power of 2 or not based on the value of n & (n-1). The expression 
    n & (n-1) will not work when n is 0. To handle this case also, our expression will become n && (! n & (n-1))

*/

bool isPowerOfTwo (int x) 
{ 
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1))); 
} 
