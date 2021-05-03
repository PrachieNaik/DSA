/*

Problem statement: Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the
least number of multiplications. 
The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions 
(arr[i-1] x arr[i]).

Input: N = 5
arr = {40, 20, 30, 10, 30}

Output: 26000
Explaination: There are 4 matrices of dimension 40x20, 20x30, 30x10, 10x30. Say the matrices are named as A, B, C, D. The efficient way is (A*(B*C))*D.
The number of operations are 20*30*10 + 40*20*10 + 40*10*30 = 26000.

Approach: A simple solution is to place parenthesis at all possible places, calculate the cost for each placement and return the minimum value. 
      In a chain of matrices of size n, we can place the first set of parenthesis in n-1 ways. For example, if the given chain is of 4 matrices. 
      let the chain be ABCD, then there are 3 ways to place first set of parenthesis outer side: (A)(BCD), (AB)(CD) and (ABC)(D). 
      So when we place a set of parenthesis, we divide the problem into subproblems of smaller size. Therefore, the problem has optimal substructure property 
      and can be easily solved using recursion.
      Minimum number of multiplication needed to multiply a chain of size n = Minimum of all n-1 placements (these placements create subproblems of smaller size)

*/

int matrixMultiplicationUtil(int arr[], int i, int j) {
    if(i >= j)
    return 0;
    int ans = INT_MAX;
    for(int k = i; k<= j-1; k++) {
        int temp = matrixMultiplicationUtil(arr,i,k) + matrixMultiplicationUtil(arr,k+1,j)
                    + arr[i-1] * arr[j] * arr[k];
        ans = min(ans,temp);
    }
    return ans;
}
int matrixMultiplication(int N, int arr[])
{
    return matrixMultiplicationUtil(arr,1,N-1);
}
