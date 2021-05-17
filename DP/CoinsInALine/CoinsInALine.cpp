/*

Problem statement: There are A coins (Assume A is even) in a line. Two players take turns to take a coin from one of the ends of the line until there
are no more coins left. The player with the larger amount of money wins, Assume that you go first. Return the maximum amount of money you can win.

NOTE: You can assume that opponent is clever and plays optimally.

Problem Constraints
1 <= length(A) <= 500
1 <= A[i] <= 10^5

Input Format
The first and the only argument of input contains an integer array A.

Output Format
Return an integer representing the maximum amount of money you can win.

Example Input
Input 1: A = [1, 2, 3, 4]
Input 2: A = [5, 4, 8, 10]

Example Output
Output 1: 6
Output 2: 15

Example Explanation

Explanation 1:
 You      : Pick 4
 Opponent : Pick 3
 You      : Pick 2
 Opponent : Pick 1
Total money with you : 4 + 2 = 6

Explanation 2:

 You      : Pick 10
 Opponent : Pick 8
 You      : Pick 5
 Opponent : Pick 4
Total money with you : 10 + 5 = 15

Think of a function that goes deep and then returns your answer. At each subarray, you can wither pick left/right and the important part is to
realize that opponent also plays optimally. Hence we take minimum two possibilities.
*/

nt rec(vector<int> &A,int lind,int rind,vector<vector<int>> &dp) {
    if(lind > rind)
    return 0;
    
    if(dp[lind][rind] != -1)
    return dp[lind][rind];
    
    int left = A[lind] + min( rec(A,lind + 2,rind,dp), rec(A,lind + 1,rind - 1,dp)); //min here since opponent also plays optimally
    int right = A[rind] + min( rec(A,lind,rind - 2,dp), rec(A,lind + 1,rind - 1,dp)); //min here since opponent also plays optimally
    
    return dp[lind][rind] = max(left,right); //max here since I(player 1) get the first chance
    
}
int Solution::maxcoin(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return rec(A,0, n-1, dp);
}
