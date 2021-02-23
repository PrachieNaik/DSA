/*

Problem statement: You are given two numbers A and B. The task is to count the number of bits needed to be flipped to convert A to B.

Constraints:
1 ≤ A, B ≤ 10^6

Approaches: 

Find xor of the given numbers. Find set bits.

*/

int countBitsFlip(int a, int b){
    
    int axorb = a ^ b;
    unsigned int count = 0;
    while (axorb) {
        axorb &= (axorb - 1);
        count++;
    }
    return count;
    
}
