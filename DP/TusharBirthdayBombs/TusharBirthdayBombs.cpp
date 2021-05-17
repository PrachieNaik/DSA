/*

Problem statement: It’s Tushar’s birthday today and he has N friends. Friends are numbered [0, 1, 2, ...., N-1] and ith friend have a positive strength B[i]. 
Today being his birthday, his friends have planned to give him birthday bombs (kicks). Tushar's friends know Tushar's pain bearing limit and would hit 
accordingly. If Tushar’s resistance is denoted by A (>=0) then find the lexicographically smallest order of friends to kick Tushar so that the cumulative
kick strength (sum of the strengths of friends who kicks) doesn’t exceed his resistance capacity and total no. of kicks hit are maximum. Also note that each
friend can kick unlimited number of times (If a friend hits x times, his strength will be counted x times) Return the lexicographically smallest array of
maximum length where the ith index represents the index of the friend who will hit.

NOTE: [a1, a2, ...., am] is lexicographically smaller than [b1, b2, .., bm] if a1 < b1 or (a1 = b1 and a2 < b2) ... .Input cases are such that the length 
of the answer does not exceed 100000.

Problem Constraints
1 <= N <= 100
1 <= A <= 15 * 106
1 <= B[i] <= 105

Input Format
The first argument contains an integer, A of length N.
The second argument contains an array of integers B.

Output Format
Return an array of integer, as described in the problem statement.

Example Input
Input 1: A = 12, B = [3, 4]
Input 2: A = 11, B = [6, 8, 5, 4, 7]

Example Output
Output 1: [0, 0, 0, 0]
Output 2: [0, 2]

In the first test case A = 12 and the array of friends is [ 3, 4]
So the output is 4 times the first friend that is [ 3, 3, 3, 3]
Since the index of 3 is 0 so output is [ 0, 0, 0, 0]

Similarly for second testcase A = 11 B = [6, 8, 5, 4, 7]
So the answer is the sequence [6, 5] is written in the form of their indices [0, 2]
*/

vector<int> Solution::solve(int S, vector<int> &wt) {
    
    int n=wt.size();
    vector<int> dp(S + 1,-1),back(S + 1);
    
    for(int i = 0;i <= S;i++){ // in normal unbounded we iterate over every Sum by including item one by one
        
        for(int j = 0;j < n;j++){//this order is changed for lexographically minimum
            
            if(i >= wt[j] && dp[i] < dp[i - wt[j]] + 1){
                dp[i] = dp[i - wt[j]] + 1;
                back[i] = j;
            }
        }
    }
    
    vector<int> r;
    while(S >= 0 && S - wt[back[S]] >= 0){
        r.push_back(back[S]);
        S -= wt[back[S]];
    }
    return r;
}
