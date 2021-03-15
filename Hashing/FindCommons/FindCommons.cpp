/*

Problem statement: Given two lists V1 and V2 of sizes n and m respectively. Return the list of elements common to both the lists and return the list in sorted order.
Duplicates may be there in the output list.

Input:
5
3 4 2 2 4
4
3 2 2 7

Output:
2 2 3

Constraints: 1 <= n, m <= 10^5, 1 <= Vi <= 10^5

Time Complexity: O(N + M + CLogC). C = Common elements
Auxiliary Space: O(N).

*/

vector<int> common_element(vector<int>v1,vector<int>v2)
{
    unordered_map<int,int> m;
    vector<int> ans;
    for(int i = 0;i < v1.size();i++) {
        m[v1[i]] ++;
    }
    for(int i = 0;i < v2.size();i++) {
        if(m[v2[i]] != 0) {
            ans.push_back(v2[i]);
            m[v2[i]]--;
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
