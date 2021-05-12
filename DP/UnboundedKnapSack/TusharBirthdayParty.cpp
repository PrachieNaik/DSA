/*

Problem statement: As it is Tushar’s Birthday on March 1st, he decided to throw a party to all his friends at TGI Fridays in Pune.
Given are the eating capacity of each friend, filling capacity of each dish and cost of each dish. A friend is satisfied if the sum of the filling capacity of
dishes he ate is equal to his capacity. Find the minimum cost such that all of Tushar’s friends are satisfied (reached their eating capacity).

NOTE:

Each dish is supposed to be eaten by only one person. Sharing is not allowed.
Each friend can take any dish unlimited number of times.
There always exists a dish with filling capacity 1 so that a solution always exists.
Input Format

Friends : List of integers denoting eating capacity of friends separated by space.
Capacity: List of integers denoting filling capacity of each type of dish.
Cost :    List of integers denoting cost of each type of dish.

Constraints:
1 <= Capacity of friend <= 1000
1 <= No. of friends <= 1000
1 <= No. of dishes <= 1000

Example:

Input:
    2 4 6
    2 1 3
    2 5 3

Output:
    14

Explanation: 
    First friend will take 1st and 2nd dish, second friend will take 2nd dish twice.  Thus, total cost = (5+3)+(3*2)= 14

*/

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int maxCapacity=0;
    //calculate maxCapacity
    for(int i=0;i<A.size();++i) maxCapacity=max(maxCapacity,A[i]);
    long long int dp[maxCapacity+1];
    dp[0]=0;
    //minimum price per person is independent of number of people
    //so we can calculate minimum price for all possible capacity
    //all possible capacity =dp[0.....maxCapacity]
    
    
    //initialise every price to max value
    for(int i=1;i<=maxCapacity;++i) dp[i]=INT_MAX;
    
    //capacity i can be fullfilled by B[j] requiring cost C[j]
    //so capacity is i-> i-B[j] ; cost =dp[i] -> cost for i-B[j] +C[j]
    //we minimise it for all possible previous capacities i-B[j] j 0 -> B.size
    for(int i=1;i<=maxCapacity;++i){
        for(int j=0;j<B.size();++j){
            dp[i]=min(dp[i],((B[j]<=i)? dp[i-B[j]] +C[j] : dp[i]));
        }
    }
    ///calculate price for all
    int ans=0;
    for(int i=0;i<A.size();++i){
        ans+=dp[A[i]];
    }
    return ans;
    
}
