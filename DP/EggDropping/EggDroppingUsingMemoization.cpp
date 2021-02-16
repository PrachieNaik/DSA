/*

Problem statement: Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.There are few rules given below. 

    An egg that survives a fall can be used again.
    A broken egg must be discarded.
    The effect of a fall is the same for all eggs.
    If the egg doesn't break at a certain floor, it will not break at any floor below.
    If the eggs breaks at a certain floor, it will break at any floor above.

Constraints:
1<=N<=10
1<=K<=50

Approach: Memoization

*/
int dp[11][51];

int eggDropUtil(int eggs, int floors) 
{
    if(dp[eggs][floors] != -1)
    return dp[eggs][floors];
    
    if(floors == 1 || floors == 0)
    return floors;
    
    if(eggs == 1)
    return floors;
    
    int ans = INT_MAX;
    for(int i = 1;i <= floors;i++) {
        int temp = 1 + max(eggDropUtil(eggs - 1,i - 1), eggDropUtil(eggs, floors - i));
        ans = min(temp,ans);
    }
    dp[eggs][floors] = ans;
    return ans;
}

int eggDrop(int n, int k) {
    memset(dp,-1,sizeof(dp));
    return eggDropUtil(n,k);
}
