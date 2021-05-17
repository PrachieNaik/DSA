/*

Problem statement: A message containing letters from A-Z is being encoded to numbers using the following mapping:

 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
Given an encoded message A containing digits, determine the total number of ways to decode it modulo 109 + 7.

Problem Constraints
1 <= |A| <= 10^5

Input Format
The first and the only argument is a string A.

Output Format
Return a single integer denoting the total number of ways to decode it modulo 10^9 + 7.

Example Input
Input 1: A = "8"
Input 2: A = "12"

Example Output
Output 1: 1
Output 2: 2

Example Explanation
Explanation 1: Given encoded message "8", it could be decoded as only "H" (8). The number of ways decoding "8" is 1.
Explanation 2: Given encoded message "12", it could be decoded as "AB" (1, 2) or "L" (12). The number of ways decoding "12" is 2.

Approach:

Lets first look at the bruteforce solution.
It only makes sense to look at 1 digit or 2 digit pairs ( as 3 digit sequence will be greater than 26 ).
So, when looking at the start of the string, we can either form a one digit code, and then look at the ways of forming the rest of the string of length L - 1,
or we can form 2 digit code if its valid and add up the ways of decoding rest of the string of length L - 2.
This obviously is exponential.

The code would go something like the following :

 int ways(string &s, int startIndex) {
    
 // BASE CASES
 int answer = 0;
 if (isValid(s[startIndex])) answer += ways(s, startIndex + 1);
    if (isValid(s[startIndex] + s[startIndex + 1])) answer += ways(s, startIndex + 2);
    return answer;
 }
 
Note that in this case, startIndex can only take L number of values. Can you use the fact to store the result so that the function processing does not happen
so many times ?

*/

int Solution::numDecodings(string A) {
    vector<int> dp(A.size()+1,0);
    
    dp[0] = 1;
    dp[1] = (A[0] == '0') ? 0 : 1;
    
    for(int i = 2;i <= A.size();i++)
    {
        if(A[i - 1] > '0')
        dp[i] = dp[i - 1];
        
        if((A[i - 2] == '1') || (A[i - 2] == '2' && A[i - 1] < '7'))
        dp[i]=(dp[i - 2] + dp[i]) % 1000000007;
    }
    return dp[A.size()];
}
