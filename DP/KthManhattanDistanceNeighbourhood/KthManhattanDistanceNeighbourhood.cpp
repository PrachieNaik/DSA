/*

Problem statement: Given a matrix M of size nxm and an integer K, find the maximum element in the K manhattan distance neighbourhood for all elements in 
nxm matrix.
In other words, for every element M[i][j] find the maximum element M[p][q] such that abs(i-p)+abs(j-q) <= K.

Note: Expected time complexity is O(N*N*K)

Constraints:

1 <= n <= 300
1 <= m <= 300
1 <= K <= 300
0 <= M[i][j] <= 1000
Example:

Input:
M  = [[1,2,4],[4,5,8]] , K = 2

Output:
ans = [[5,8,8],[8,8,8]]

Approach: If you have answer for (K-1)th manhtaan distance of all the elements, can you use those values to find the answer for Kth manhattan distance.
*/

vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<vector <int>> ans;
    int n=B.size();
    int m=B[0].size();
    
    if(m==0 || n==0)
        return {};
    if(A==0)
        return B;
    
    // 3D DP
    int dp[n][m][2];
    
    // manhattan distance = 0
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dp[i][j][0]=B[i][j];
    
    
    for(int k=1;k<=A;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j][k % 2]=dp[i][j][(k-1) % 2];
                
                if(i>0){
                    dp[i][j][k % 2] = max(dp[i][j][k % 2],dp[i-1][j][(k-1) % 2]);
                }
                if(i<n-1){
                    dp[i][j][k % 2] = max(dp[i][j][k % 2],dp[i+1][j][(k-1) % 2]);
                }
                if(j>0){
                    dp[i][j][k % 2] = max(dp[i][j][k % 2],dp[i][j-1][(k-1) % 2]);
                }
                if(j<m-1){
                    dp[i][j][k % 2] = max(dp[i][j][k % 2],dp[i][j+1][(k-1) % 2]);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=0;j<m;j++){
            v.push_back(dp[i][j][A % 2]);
        }
        ans.push_back(v);
    }
    return ans;
}
