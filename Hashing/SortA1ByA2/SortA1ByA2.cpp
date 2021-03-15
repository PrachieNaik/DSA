/*

Problem statement: Given two integer arrays A1[ ] and A2[ ] of size N and M respectively. Sort the first array A1[ ] such that all the relative positions of the
elements in the first array are the same as the elements in the second array A2[ ].
Note: If elements are repeated in the second array, consider their first occurance only.

Input: N = 11 ,M = 4, A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}, A2[] = {2, 1, 8, 3}
Output: 2 2 1 1 8 8 3 5 6 7 9
Explanation: Array elements of A1[] are sorted according to A2[]. So 2 comes first then 1 comes, then comes 8, then finally 3 comes, now we append remaining 
elements in sorted order.

Constraints: 1 ≤ N, M ≤ 10^6, 1 ≤ A1[i], A2[i] ≤ 10^6

Approach:
Loop through A1[], store the count of every number in a HashMap (key: number, value: count of number)
Loop through A2[], check if it is present in HashMap, if so, put in output array that many times and remove the number from HashMap.
Sort the rest of the numbers present in HashMap and put in the output array.

Time Complexity: O(N * Log(N)).
Auxiliary Space: O(N).

*/

vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
{
    map<int,int> mp;
    for(int i=0;i<N;i++)
    {
        mp[A1[i]]++;
    }
    int index = 0;
    for(int i = 0;i < M;i++) {
        while(mp[A2[i]] != 0)
        {
            A1[index++] = A2[i];
            mp[A2[i]]--;
        }
    }
    map<int, int>::iterator it; 
    for(it = mp.begin();it != mp.end(); it++) {
        while(it -> second != 0)
        {
           A1[index++] = it -> first;
           mp[it -> first]--;
        }
    }
    return A1;
 } 
