/*

Problem statement:Given a 2D matrix M of dimensions RxC. Find the maximum sum subarray in it.

Example 1:

Input:
R=4
C=5
M=[[1,2,-1,-4,-20],
[-8,-3,4,2,1],
[3,8,10,1,3],
[-4,-1,1,7,-6]]
Output:
29

Constraints:
1<=R,C<=500
-1000<=M[i][j]<=1000

Kadane’s algorithm for 1D array can be used. The idea is to fix the top and bottom columns one by one and find the maximum sum contiguous columns for every top and
bottom column pair. We basically find left and right col numbers (which have maximum sum) for every fixed top and bottom row pair. To find the left and right col 
numbers, calculate the sum of elements in every col from top to bottom and store these sums in an array say temp[]. So temp[i] indicates sum of elements from top 
to bottom in col i. If we apply Kadane’s 1D algorithm on temp[], and get the maximum sum subarray of temp, this maximum sum would be the maximum possible sum with 
top and bottom as boundary columns. To get the overall maximum sum, we compare this sum with the maximum sum so far.

Time Complexity: O(n^3)
Space Complexity: O(n)

*/
int kandene(vector<int>ans,int c)
{
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    for(int i=0;i<c;i++) {
        max_ending_here += ans[i];
        
        max_so_far = max(max_so_far,max_ending_here);
        
        if(max_ending_here < 0)
            max_ending_here = 0;
            
        
    }
    return max_so_far;
  
}
int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
    int maxi=INT_MIN;
    for(int top=0;top<R;top++)
    {
        vector<int>ans(C,0);
        for(int bottom=top;bottom<R;bottom++)
        {
            for(int col=0;col<C;col++)
            {
                ans[col]+=M[bottom][col];
            }
            maxi=max(maxi,kandene(ans,C));
        }
    }
    return maxi;
    
}
