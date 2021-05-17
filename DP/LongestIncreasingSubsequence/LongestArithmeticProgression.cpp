/*

Problem statement: Find longest Arithmetic Progression in an integer array A of size N, and return its length.

More formally, find longest sequence of indices, 0 < i1 < i2 < … < ik < ArraySize(0-indexed) such that sequence A[i1], A[i2], …, A[ik] is an Arithmetic
Progression.

Arithmetic Progression is a sequence in which all the differences between consecutive pairs are the same, i.e sequence B[0], B[1], B[2], …, B[m - 1] of
length m is an Arithmetic Progression if and only if B[1] - B[0] == B[2] - B[1] == B[3] - B[2] == … == B[m - 1] - B[m - 2]

Note: The common difference can be positive, negative or 0.

Input Format:
The first and the only argument of input contains an integer array, A.

Output Format:
Return an integer, representing the length of the longest possible arithmetic progression.

Constraints:

1 <= N <= 1000
1 <= A[i] <= 1e9
Examples:

Input 1: A = [3, 6, 9, 12]
Output 1: 4
Explanation 1: [3, 6, 9, 12] form an arithmetic progression.

Input 2: A = [9, 4, 7, 2, 10]
Output 2: 3
Explanation 2: [4, 7, 10] form an arithmetic progression.

This problem is similar to Longest Increasing Subsequence problem. The difference is that we need to consider the arithmetic difference in this problem.
How to keep track of the length as well as the difference? We can use a hashmap, whose key is the difference and value is the length. Then we can solve
the problem with dynamic programming:
As noted in the problem description, 2 <= A.length , so we don’t need to consider the edge case when there is no element or only one element in A . 
The base case is A.length == 2 , then A itself is the longest arithmetic subsequence because any two numbers meet the condition of arithmetic .
The optimization step is that for two elements A[i] and A[j] where j < i , the difference between A[i] and A[j] (name it diff ) is a critical condition.
If the hashmap at position j has the key diff , it means that there is an arithmetic subsequence ending at index j , with arithmetic difference diff and
length dp[j][diff] . And we just add the length by 1 . If hashmap does not have the key diff , then those two elements can form a 2-length arithmetic 
subsequence. And update the result if necessary during the iteration.
*/

int Solution::solve(const vector<int> &arr) {
    
    int n = arr.size(), res = 2;
    if(n <= 2)
        return n;
    vector<unordered_map<int, int>> dp(n);  
    
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            int diff = arr[j] - arr[i];
            dp[i][diff] = dp[j].find(diff) != dp[j].end() ? dp[j][diff] + 1 : 2;
            res = max(res, dp[i][diff]);
        }
    }
    return res;
}
