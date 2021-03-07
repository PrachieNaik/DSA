/*

Problem statement: Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment 
each time is either x , y or z. Here x, y, and z are integers. After performing all the cut operations, your total number of cut segments must be maximum.

Input: N = 4, x = 2, y = 1, z = 1
Output: 4
Explanation:Total length is 4, and the cut lengths are 2, 1 and 1.  We can make maximum 4 segments each of length 1.


Constraints
1 <= N, x, y, z <= 10^4

Keywords: maximum

Approach: Dynamic Programming

Time complexity: O(N)
Space complexity: O(N)

*/

int maximizeTheCuts(int n, int x, int y, int z)
{
    int dp[n + 1];
    
    for (int i = 0; i < n + 1; i++)
    {        
        if(i==x || i==y || i==z)
            dp[i] = 1;
        else
            dp[i] = 0;
    }
    
    for(long long i=1;i <= n;i++)
    {
        if(i - x > 0 && dp[i - x]) 
            dp[i]=max(1 + dp[i - x],dp[i]);
            
        if(i - y > 0 && dp[i - y])
            dp[i]=max(1 + dp[i - y],dp[i]);
            
        if(i - z > 0 && dp[i - z])
            dp[i]=max(1 + dp[i - z],dp[i]);
    }
    return dp[n];
}
