/*

Problem statement: Given an array of integers. We are required to write a program to print the number of factors of every element of the given array.
Examples: 
 

Input: 10 12 14 
Output: 4 6 4 
Explanation: There are 4 factors of 10 (1, 2, 
5, 10) and 6 of 12 and 4 of 14.

Input: 100 1000 10000
Output: 9 16 25 
Explanation: There are 9 factors of 100  and
16 of 1000 and 25 of 10000.

Approach: Dynamic programming

*/

int main() {
    int n;
    cin>>n;
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2;i <= n;i++) {
        dp[i] = 2;
    }
    for(int i = 2;i <= n/2 ;i++) {
        for(int j = i + i;j <= n;j = j + i) {
            dp[j]++;
        }
    }
    cout<<dp[n];
}
