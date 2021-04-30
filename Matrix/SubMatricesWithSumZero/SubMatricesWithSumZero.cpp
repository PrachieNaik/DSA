/*

Problem statement: Given a 2D matrix, find the number non-empty sub matrices, such that the sum of the elements inside the sub matrix is equal to 0. (note: elements
might be negative).

Example:

Input

-8 5  7
3  7 -8
5 -8  9
Output
2

The idea is to reduce the problem to 1 D array by fixing the top and bottom pointers and then solve it using presum method. save the total number of maxtrix whose
sum is zero. 

Time Complexity: O(n^3)
Space Complexity: O(n)

*/
int Solution::solve(vector<vector<int> > &A) {
    int ans = 0;
    int row = A.size();
    if(row<=0)
        return 0;
        
    int col = A[0].size();
    
    for(int top = 0;top < row;top++) {
        vector<int> v(col,0);
        for(int bottom = top;bottom < row;bottom++) {
            for(int i = 0; i < col;i++) {
                v[i] += A[bottom][i];
            }
            
            vector<int> presum(col,0);
            presum[0] = v[0];
            if(presum[0] == 0)
                ans++;
            for(int i = 1; i < col;i++) {
                presum[i] = presum[i-1] + v[i];
                if(presum[i] == 0) {
                    ans++;
                }
            }
            
            for(int i = 1; i < col;i++) {
                for(int j = 0; j < i;j++) {
                    if(presum[i] - presum[j] == 0) {
                        ans++;
                    }
                }
            }
        }
    }
    return ans;
}
