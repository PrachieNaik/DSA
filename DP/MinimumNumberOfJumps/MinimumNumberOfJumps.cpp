/*

Problem statement: Given an array of integers where each element represents the max number of steps that can be made forward from that element. Find the minimum 
number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.

Input:
N=11 
arr=1 3 5 8 9 2 6 7 6 8 9 

Output: 3 

Explanation: 
First jump from 1st element to 2nd element with value 3. Now, from here we jump to 5th element with value 9, and from here we will jump to last. 

Constraints:
1 ≤ N ≤ 10^7
0 <= ai <= 10^7

Keywords: Minimum

Approach: Dynamic Programming

Time complexity: O(N^2)
Space complexity: O(N)

*/

int minJumps(int arr[], int n){
    
    int dp[n];
    dp[n - 1] = 0;
    
    for(int i = n - 2;i >= 0; i--) {
        //this is to handle overflow condition
        dp[i] = INT_MAX - 1;
    }
    
    for(int i = n - 2;i >= 0; i--) {
        
        //keep track of max index can be jumped from current index
        int jump_till = i + arr[i];
        
        while(jump_till > 0) {
            
            //for the case when last index can be reach directly from current index
            if(jump_till >= n - 1) {
                dp[i] = 1;
                break;
            }
            //loop to find min index
            else if(dp[jump_till] + 1 <= dp[i]) {
                dp[i] = dp[jump_till] + 1;
            }
            
            jump_till --;
        }
    }
    // for the case when last index is not reachable
    if(dp[0] == INT_MAX || dp[0] == INT_MAX - 1)
    return -1;
    
    return dp[0];
}
