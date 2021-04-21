/*

Problem statement: Given a sorted matrix mat[n][m] and an element ‘x’. Find the position of x in the matrix if it is present, else print -1. Matrix is sorted in a 
way such that all elements in a row are sorted in increasing order and for row ‘i’, where 1 <= i <= n-1, the first element of row ‘i’ is greater than or equal to 
the last element of row ‘i-1’. 

Examples: 

Input : mat[][] = { {1, 5, 9},
                    {14, 20, 21},
                    {30, 34, 43} }
        x = 14
Output : Found at (1, 0)

Input : mat[][] = { {1, 5, 9, 11},
                    {14, 20, 21, 26},
                    {30, 34, 43, 50} }
        x = 42
Output : -1

Approach: We can observe that any number (say k) that we want to find, must exist within a row, including the first and last elements of the row (if it exists at 
all). So we first find the row in which k must lie using binary search ( O(logn) ) on first column and then use binary search again to search in that row( O(logm) ).

Time Complexity: O(log(m) + log(n)) 
Auxiliary Space: O(1)

*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
    int rowSize = matrix.size();
    if(rowSize == 0) 
        return false;
    
    int colSize = matrix[0].size();
    int start = 0, end = rowSize-1, mid;
    
    while(start < end){
        mid = start + (end-start)/2;
        if(matrix[mid][colSize-1] < target) 
            start = mid+1;
        else if(matrix[mid][0] > target) 
            end = mid-1;
        else {
            start = mid;
            break;
        }
    }
    
    int left = 0, right = colSize-1;
    while(left <= right){
        mid = left + (right-left)/2;
        
        if(matrix[start][mid] < target) 
            left = mid+1;
        else if(matrix[start][mid] > target)
            right = mid-1;
        else 
            return true;
    }
    return false;
}
