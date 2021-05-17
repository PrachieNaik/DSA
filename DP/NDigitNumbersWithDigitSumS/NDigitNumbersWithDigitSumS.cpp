/*

Problem statement: Find out the number of N digit numbers, whose digits on being added equals to a given number S. Note that a valid number starts from
digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed.

Since the answer can be large, output answer modulo 1000000007

N = 2, S = 4
Valid numbers are {22, 31, 13, 40}
Hence output 4.
*/

int Solution::solve(int n, int s) {
    
    int dp[n+1][s+1];
    memset(dp,0,sizeof(dp));
    
    if(s < 1 || s > 9 * n) 
    return 0;
    
    for(int i = 1;i <= s;i++){
        dp[1][i] = i <= 9 ? 1 : 0;  //only 1 digit so only possible to have sum <= 9 and only in one way
    }
    for(int j = 1;j <= n;j++){
        dp[j][1] = 1;     //sum is 1 so only one way no matter how many digits as leading zeroes are not allowed i.e, 1,10,100...
    }
    for(int i = 2;i <= n;i++){
        for(int j = 2;j <= s;j++){
            for(int k = j - 9;k <= j;k++) {
                if(k >= 0) {
                    dp[i][j]=(dp[i][j] + dp[i - 1][k]) % 1000000007;
                }
            }
        }
    }
    return dp[n][s];
}
