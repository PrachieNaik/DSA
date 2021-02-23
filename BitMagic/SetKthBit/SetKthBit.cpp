/*

Problem statement: Given a number N and a value K. From the right, set the Kth bit in the binary representation of N. The position of Least Significant Bit(or last 
bit) is 0, the second last bit is 1 and so on. 

Input:
N = 10 
K = 2
Output:
14
Explanation:
Binary representation of the given number 10 is: 1 0 1 0, number of bits in the binary reprsentation is 4. Thus 2nd bit from right is 0. The number after changing 
this bit to 1 is: 14(1 1 1 0).

Constraints:
1 <= N <= 10^9
0 <= K < X, where X is the number of bits in the binary representation of N.

Approach: To set any bit we use bitwise OR | operator. As we already know bitwise OR | operator evaluates each bit of the result to 1 if any of the operand’s 
corresponding bit is set (1). In-order to set kth bit of a number we need to shift 1 k times to its left and then perform bitwise OR operation with the number and 
result of left shift performed just before.

*/

int setKthBit(int N, int K)
{
    return N | (1 << K);
}
