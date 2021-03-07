/*

Problem statement: Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } and a target value N. Find the
minimum number of coins and/or notes needed to make the change for Rs N.

Input: N = 43
Output: 20 20 2 1
Explanation: Minimum number of coins and notes needed to make 43. 

Constraints: 1 <= N <= 10^6

Keywords: Minimum, choose from each denomination of Indian currency

Approach: Dynamic Programming

Time complexity: O(N)
Space complexity: O(N)

*/

vector<int> minPartition(int N)
{
    vector<int> result;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    
    //to store the minimum number of coins needed to reach the number i
    int dp[N+1];
    dp[0] = 0;
    
    //to store the coin that was selected last to reach the number i
    int coin_used[N+1];
    coin_used[0] = 0;
    
    //initializing the dp array to max int value
    for(int i = 1;i <= N;i++) {
        dp[i] = INT_MAX;
    }
    
    //fill the 1d table starting from 1, save the coin which was used 
    for(int i = 1;i <= N;i++) {
        int coin = 0;
        
        for(int j = 9;j >= 0; j--) {
            if(i - coins[j] >= 0 && dp[i] > dp[i - coins[j]] + 1) {
                
                //save min number of coins used
                dp[i] = dp[i - coins[j]] + 1;  
                
                //save the coin used
                coin = coins[j];
                
                //breaking here picks the biggest valid coin, might fail for some case??? 
                break;
            }
        }
        
        coin_used[i] = coin;
    }
    
    // this is to find the coins which were used
    int temp = N;
    while(temp > 0) {
        result.push_back(coin_used[temp]);
        temp -= coin_used[temp];
    }
    return result;
}
