/*

Problem statement:Given a string s of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of ‘k’ characters. 
The value of a string is defined as the sum of squares of the count of each distinct character.
 
Example 1:

Input: s = abccc, k = 1
Output: 6
Explaination:
We remove c to get the value as 1^2 + 1^2 + 2^2

Constraints:
1 ≤ k ≤ |string length| ≤ 100

Approach 1: Using max heap
Initialize empty priority queue.
Count frequency of each character and Store into temp array.
Remove K characters which have highest frequency from queue.
Finally Count Sum of square of each element and return it.

Time Complexity: O(k*logn)

Approach 2: Using sorting and frequency array

Time Complexity: O(n) since the size of frequency array is constant
Space Complexity: O(1)

*/

int minValue(string s, int k){
    // code here
    vector<int> freq(26,0);
    for(int i = 0;i < s.length();i++) {
        freq[s[i] - 'a']++;
    }
    while(k--) {
        sort(freq.begin(),freq.end());
        freq[25] --;
    }
    int ans = 0;
    for(int i = 0;i < 26;i++) {
        ans += freq[i]*freq[i];
    }
    return ans;
}
