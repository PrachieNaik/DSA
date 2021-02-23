/*

Problem statement: Given a number N and a bit number K, check if Kth bit of N is set or not. A bit is called set if it is 1. Position of set bit '1' should be 
indexed starting with 0 from LSB side in binary representation of the number.

Constraints:
1 ≤ N ≤ 10^9
0 ≤ K ≤ floor(log2(N) + 1)

Approach: 
1) Left shift given number 1 by k (since the indexing is from 0) to create a number that has only set bit as k-th bit. 
    temp = 1 << k
2) If bitwise AND of n and temp is non-zero, then result is SET else result is NOT SET.

*/

bool checkKthBit(int n, int k){
    return (n & (1 << (k)));
}
