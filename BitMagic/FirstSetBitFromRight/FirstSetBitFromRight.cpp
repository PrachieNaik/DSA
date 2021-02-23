/*

Problem statement: Given an integer an N. The task is to return the position of first set bit found from the right side in the binary representation of the number.
Note: If there is no set bit in the integer N, then return 0 from the function.  

Constraints:
0 <= N <= 10^6

Approach: Initialize pos=1 . Iterate till number>0,  at each step check if the last bit is set. If last bit is set , return current position, else increment pos by
1 and right shift n by 1.

*/

unsigned int getFirstSetBit(int n){
    
    int position = 1;
    while(n > 0) {
        if(n & 1 == 1)
        return position;
        
        position++;
        n = n >> 1;
    }
}
