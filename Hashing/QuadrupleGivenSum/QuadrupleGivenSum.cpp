/*

Problem statement: Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.

Input: N = 5, K = 3, A[] = {0,0,2,1,1}
Output: 0 0 1 2 $
Explanation: Sum of 0, 0, 1, 2 is equal to K.

Constraints: 1 <= N <= 100, -1000 <= K <= 1000, -100 <= A[] <= 100

Approach: 
1) Sort the input array.
2) Fix the first element as A[i] where i is from 0 to n–3. After fixing the first element of quadruple, fix the second element as A[j] where j varies from i+1 to 
n-2. Find remaining two elements in O(n) time, using the method of 2 pointers.

Time Complexity: O(N^3).
Auxiliary Space: O(N^2).

*/

vector<vector<int> > fourSum(vector<int> &arr, int k) {
    
    int n = arr.size();
    vector<vector<int> > ans;
    sort(arr.begin(),arr.end());
    
    for(int first = 0;first < n - 3;first++) {
        if (first > 0 && arr[first] == arr[first - 1])
                continue;
                
        for(int second = first + 1; second < n - 2; second++) {
            if ( second - 1 != first && arr[second] == arr[second - 1] )
                    continue;
                    
            int sum = arr[first]+arr[second];
            int left = second + 1;
            int right = n - 1;
            while(left < right) {
                
                if((arr[left] + arr[right] + sum) == k) {
                    vector<int> temp;
                    temp.push_back(arr[first]);
                    temp.push_back(arr[second]);
                    temp.push_back(arr[left++]);
                    temp.push_back(arr[right--]);
                    ans.push_back(temp);
                    while (left < right && arr[left] == arr[left - 1])
                        left++;
                    while (left < right && arr[right] == arr[right + 1])
                        right++;
                } else if((arr[left] + arr[right] + sum) < k) {
                    left++;
                } else {
                    right--;
                }
                
            }
        }
    }
    return ans;
}
