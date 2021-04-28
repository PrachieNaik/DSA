/*

Problem statement: Given K sorted lists of integers of size N each, find the smallest range that includes at least one element from each of the K lists. If more
than one such range's are found, find the first such range found.

Example 1:

Input:
N = 5, K = 3
KSortedArray[][] = {{1 3 5 7 9},
                    {0 2 4 6 8},
                    {2 3 5 7 11}}
Output: 1 2
Explanation: K = 3
A:[1 3 5 7 9]
B:[0 2 4 6 8]
C:[2 3 5 7 11]
Smallest range is formed by number 1 present in first list and 2 is present in both 2nd and 3rd list.

Constraints:
1 <= K,N <= 500

Min heap can be used to find the maximum and minimum value in logarithmic time or log k time instead of linear time. Rest of the approach remains the same.

Algorithm:
create an Min heap to store k elements, one from each array and a variable minrange initilized to a maximum value and also keep a variable max to store the maximum
integer.
Initially put the first element of each element from each list and store the maximum value in max.
Repeat the following steps until atleast one list exhausts :
To find the minimum value or min, use the top or root of the Min heap which is the minimum element.
Now update the minrange if current (max-min) is less than minrange.
remove the top or root element from priority queue and insert the next element from the list which contains the min element and upadate the max with the new element
inserted.

Complexity Analysis:
Time complexity : O(n * k *log k).
To find the maximum and minimum in an Min Heap of length k the time required is O(log k), and to traverse all the k arrays of length n (in worst case), the time
complexity is O(n*k), then the total time complexity is O(n * k *log k).
Space complexity: O(k).
The priority queue will store k elements so the space complexity os O(k)

*/
typedef pair<int,pair<int,int>> ppi;
pair<int,int> findSmallestRange(int arr[][N], int n, int k)
{
      int mini = INT_MAX, maxi = INT_MIN; //global maximum and minimum
      int range = INT_MAX;
      int curmin = INT_MAX, curmax = INT_MIN; //current maximum and minimum
      priority_queue<ppi,vector<ppi>,greater<ppi>> pq; // element, listnumber, nextindex
      for(int i = 0;i < k;i++) {
          pq.push({arr[i][0],{i,1}}); //push all first column elements
          if(arr[i][0] > curmax) {
              curmax = arr[i][0];
          }
      }
      
      while(1) {
          ppi tp = pq.top(); //fetch the minimum element in heap
          curmin = tp.first;
          int listnumber = tp.second.first;
          int nextIndex = tp.second.second;
          pq.pop();
          
          if(range > curmax - curmin + 1) { //check if the range is shrinked
              range = curmax - curmin + 1;
              mini = curmin;
              maxi = curmax;
          }
          if(nextIndex < n) {
              pq.push({arr[listnumber][nextIndex],{listnumber,nextIndex + 1}}); //push the next element from the same list from which current minimum was extracted
              if(arr[listnumber][nextIndex] > curmax) {
                  curmax = arr[listnumber][nextIndex];
              }
          } else {
              break; //when one of the list reached the end
          }
      }
    return {mini,maxi};
}
