/*

Problem statement: Given a binary string of 0s and 1s. The task is to find the maximum difference between the number of 0s and number of 1s in any
sub-string of the given binary string. That is maximize ( number of 0s – number of 1s ) for any sub-string in the given binary string. 

Examples: 
Input : S = "11000010001"
Output : 6
From index 2 to index 9, there are 7 0s and 1 1s, so number of 0s - number of 1s is 6.

Input : S = "1111"
Output : -1

Approach: 
If we convert all zeros into 1 and all ones into -1.now our problem reduces to find out the maximum sum sub_array Using Kadane’s Algorithm. 
 

Input : S = "11000010001"
After converting '0' into 1 and '1' into -1 our S Look Like S  = -1 -1 1 1 1 1 -1 1 1 1 -1
Now we have to find out Maximum Sum sub_array that is  : 6 is that case 
    
Output : 6

Time Complexity : O(n) 
Space complexity : O(1)

*/

// Returns the length of substring with
// maximum difference of zeroes and ones
// in binary string
int findLength(string str, int n)
{
    int current_sum = 0;
    int max_sum = 0;
 
    // traverse a binary string from left
    // to right
    for (int i = 0; i < n; i++) {
 
        // add current value to the current_sum
        // according to the Character
        // if it's '0' add 1 else -1
        current_sum += (str[i] == '0' ? 1 : -1);
 
        if (current_sum < 0)
            current_sum = 0;
 
        // update maximum sum
        max_sum = max(current_sum, max_sum);
    }
 
    // return -1 if string does not contain
    // any zero that means all ones
    // otherwise max_sum
    return max_sum == 0 ? -1 : max_sum;
}
