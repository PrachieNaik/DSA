/*

Problem statement: Say you have an array, A, for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Return the maximum possible profit.

Problem Constraints
0 <= len(A) <= 7e5
1 <= A[i] <= 1e7

Input Format
The first and the only argument is an array of integers, A.

Output Format
Return an integer, representing the maximum possible profit.

Example Input
Input 1: A = [1, 2]
Input 2: A = [1, 4, 5, 2, 4]

Example Output
Output 1: 1
Output 2: 4

Example Explanation
Explanation 1: Buy the stock on day 0, and sell it on day 1.
Explanation 2: Buy the stock on day 0, and sell it on day 2.

*/

int Solution::maxProfit(const vector &A) {

    int n = A.size();    
    if(n == 0)
      return 0;
    int localMin = A[0];   //Local min stores the min value of share till now.
    
    int res=0;  //this stores the result
    for(int i = 1;i < n;i++)
    {
        localMin=min(localMin,A[i]);   //here we check if this stock price at ith index is min or not
        res=max(res,A[i]-localMin);   //if we decide to sell this stock at this day then we get max profit when we subtract  from min stock price day till 
                                      //date(which is stored in localMin var.)
    }
    
    return res;
}
