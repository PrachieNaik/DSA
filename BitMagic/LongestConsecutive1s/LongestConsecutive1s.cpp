/*

Problem statement: Given a number N. Find the length of the longest consecutive 1s in its binary representation.

Input: N = 14
Output: 3
Explanation: Binary representation of 14 is 1110, in which 111 is the longest consecutive set bits of length is 3.

Constraints: 1 <= N <= 10^6

Time Complexity: O(log N).
Auxiliary Space: O(1).

*/

int maxConsecutiveOnes(int N)
{
    int count = 0;
    int ans = 0;
    while(N) {
        if(N & 1) {
            count++;
        } else {
            count = 0;
        }
        N = N >> 1;
        ans = max(ans,count);
    }
    return ans;
}

