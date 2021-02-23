/*

Problem statement: Given two numbers M and N. The task is to find the position of the rightmost different bit in the binary representation of numbers.

Constraints:
1 <= M <= 103
1 <= N <= 103

Approach: The bitwise xor operation produces a number which has set bits only at the positions where the bits of m and n differ. Thus, the position of the 
rightmost set bit in xor_value gives the position of the rightmost different bit. 

*/

int posOfRightMostDiffBit(int m, int n)
{
    int mxorn = m ^ n;
    int position = 1;
    while(mxorn > 0) {
        if(mxorn & 1 == 1)
        return position;
        
        position++;
        mxorn = mxorn >> 1;
    }
}
