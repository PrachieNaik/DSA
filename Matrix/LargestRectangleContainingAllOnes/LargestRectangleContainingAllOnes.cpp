/*

Problem statement: Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :

A : [  1 1 1
       0 1 1
       1 0 0 
    ]

Output : 4 

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)

*/

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int ans = 0;
    for(int top = 0;top < A.size();top++) {
        
        vector<int> v(A[0].size(),0);
        for(int bottom = top;bottom < A.size();bottom++) {
            
            for(int i = 0; i < A[0].size();i++) {
                
                if(A[bottom][i] == 0) {
                    v[i] = INT_MIN;
                } else {
                    v[i] += A[bottom][i];
                }
            }
            int max_so_far = INT_MIN, max_ending_here = 0;
 
            for (int i = 0; i < v.size(); i++)
            {
                max_ending_here = max_ending_here + v[i];
                if (max_so_far < max_ending_here)
                    max_so_far = max_ending_here;
         
                if (max_ending_here < 0)
                    max_ending_here = 0;
            }
            ans = max(ans,max_so_far);
        }
    }
    return ans;
}
