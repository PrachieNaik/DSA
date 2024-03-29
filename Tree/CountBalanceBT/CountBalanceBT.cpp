/*

Problem statement: Given a height h, count and return the maximum number of balanced binary trees possible with height h. A balanced binary tree is one in which 
for every node, the difference between heights of left and right subtree is not more than 1.

Examples :

Input : h = 3
Output : 15

Input : h = 4
Output : 315

 
Height of tree, h = 1 + max(left height, right height)

Since the difference between the heights of left and right subtree is not more than one, possible heights of left and right part can be one of the following:
(h-1), (h-2)
(h-2), (h-1)
(h-1), (h-1)

count(h) = count(h-1) * count(h-2) + count(h-2) * count(h-1) + count(h-1) * count(h-1)
        = 2 * count(h-1) * count(h-2) +  count(h-1) * count(h-1)
        = count(h-1) * (2 * count(h - 2) + count(h - 1))

Time Complexity: O(N)
Space Complexity: O(N)
*/

long long int countBT(int h) { 
    long long int dp[h + 1];
    dp[0] = dp[1] = 1;
    
    for(int i = 2; i <= h; i++) {
        dp[i] = (dp[i - 1] * ((2 * dp [i - 2]) % mod + dp[i - 1]) % mod) % mod;
    }
    return dp[h];
}
