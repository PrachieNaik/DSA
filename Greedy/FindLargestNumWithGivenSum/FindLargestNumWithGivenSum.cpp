/*

Problem statement: Given two numbers 'N' and 'S' , find the largest number that can be formed with 'N' digits and whose sum of digits should be equals to 'S'.

Input: N = 2, S = 9
Output: 90
Explaination: It is the biggest number with sum of digits equals to 9.

Constraints: 1 ≤ N ≤ 10^4, 1 ≤ S ≤ 10^5

Approach:

There is a Greedy approach to solve the problem. The idea is to one by one fill all digits from leftmost to rightmost (or from most significant digit to least 
significant). We compare the remaining sum with 9 if the remaining sum is more than 9, we put 9 at the current position, else we put the remaining sum. Since we 
fill digits from left to right, we put the highest digits on the left side, hence get the largest number.

Time Complexity: O(N)
Auxiliary Space: O(N)

*/

string findLargest(int N, int S){
    string ans;
    
    //corner cases
    if(S == 0) {
        if(N == 1) 
            return "0";
        else
            return "-1";
    }
    //when sum is more then what is possible with max digits
    if(S > 9 * N)
        return "-1";
        
    while(S >= 9 && N) {
        S = S-9;
        N--;
        ans += '9';
    }
    
    if(N) {
        char c = S + '0';
        ans = ans + c;
        N--;
    }
    
    while(N) {
        ans += '0';
        N--;
    }
    
    return ans;
}
