/*

Problem statement: Given an array of positive elements, you have to flip the sign of some of its elements such that the resultant sum of the elements of array
should be minimum non-negative(as close to zero as possible). Return the minimum no. of elements whose sign needs to be flipped such that the resultant sum
is minimum non-negative.

Constraints:

1 <= n <= 100
Sum of all the elements will not exceed 10,000.

Example:

A = [15, 10, 6]
ans = 1 (Here, we will flip the sign of 15 and the resultant sum will be 1 )

A = [14, 10, 4]
ans = 1 (Here, we will flip the sign of 14 and the resultant sum will be 0)

Note that flipping the sign of 10 and 4 also gives the resultant sum 0 but flippings there are not minimum 

Approach: 
Let the sum of all the given elements be S.
This problem can be reduced to a Knapsack problem where we have to fill a Knapsack of capacity (S/2) as fully as possible and using the minimum no. of 
elements. We will fill the Knapsack with the given elements. Sign of all the elements which come into the knapsack will be flipped.

As sum of all the elements in the Knapsack will be as close to S/2 as possible, we are indirectly calculating minimum non-negative sum of all the elements
after flipping the sign. 

*/

int Solution::solve(const vector<int> &A) {
    
    int n = A.size();
    int sum = 0;
    for(int i = 0;i < n;i++) {
        sum += A[i];
    }
    sum /= 2;
    int dp[n + 1][sum + 1];
    for(int i = 0;i <= n;i++) {
        dp[i][0] = 0;
    }
    for(int j = 1;j <= sum;j++) {
        dp[0][j] = INT_MAX;
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= sum;j++) {
            dp[i][j] = dp[i - 1][j];
            if(A[i - 1] <= j && dp[i - 1][j - A[i - 1]] != INT_MAX){
                dp[i][j] = min(1 + dp[i - 1][j - A[i - 1]] , dp[i][j]);
            }
            
        }
    }
    int ans = 0;
    for(int i = sum;i >= 0 ;i--){
        if(dp[n][i] != INT_MAX) {
            ans = dp[n][i];
            break;
        }
    }
    return ans;
}
