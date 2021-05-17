/*

Problem statement: Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers is maximum and no two chosen numbers are
adjacent horizontally, vertically or diagonally, and return it.

Note: You can choose more than 2 numbers.

Input Format:
The first and the only argument of input contains a 2d matrix, A.

Output Format:
Return an integer, representing the maximum possible sum.

Constraints:
1 <= N <= 20000
1 <= A[i] <= 2000

Example:

Input 1:
    A = [   [1]
            [2]    ]
Output 1: 2
Explanation 1: We will choose 2.

Input 2:
    A = [   [1, 2, 3, 4]
            [2, 3, 4, 5]    ]
    
Output 2: 8
Explanation 2: We will choose 3 and 5.

Approach: 
V : 
1 |  2  |  3  | 4
2 |  3  |  4  | 5

Lets first try to reduce it into a simpler problem. 
We know that within a column, we can choose at max 1 element. 
And choosing either of those elements is going to rule out choosing anything from the previous or next column. 
This means that choosing V[0][i] or V[1][i] has identical bearing on the elements which are ruled out. 
So, instead we replace each column with a single element which is the max of V[0][i], V[1][i].

Now we have the list as : 
2 3 4 5

Here we can see that we have reduced our problem into another simpler problem.
Now we want to find maximum sum of values where no 2 values are adjacent. 
Now our recurrence relation will depend only on position i and,
 a "include_current_element" which will denote whether we picked last element or not.
  
MAX_SUM(pos, include_current_element) = 
IF include_current_element = FALSE THEN   
	max | MAX_SUM(pos - 1, FALSE) 
	    | 
	    | MAX_SUM(pos - 1, TRUE)

ELSE    |
	MAX_SUM(pos - 1, FALSE) + val(pos) 

*/

int Solution::adjacent(vector<vector<int> > &A) 
{
    int n=A[0].size();//size of arr
    
    for(int i=0;i<n;i++) //store max for each coloum
        A[0][i]=max(A[0][i],A[1][i]);
        
    A[0][1]=max(A[0][0],A[0][1]); //for 2nd element choose max among first end second
    
    for(int i=2;i<n;i++)
        A[0][i]=max(A[0][i-1],A[0][i-2]+A[0][i]);
    
    return max(A[0][n-1],A[0][n-2]);
}
