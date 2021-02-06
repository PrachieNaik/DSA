/*

Problem statement: Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in the array. Elements for which no greater element exist, consider next greater element as -1. 

Approaches:

Method 1: Use two loops: The outer loop picks all the elements one by one. The inner loop looks for the first greater element for the element picked by the outer loop. If a greater element is found then that element is printed as next, otherwise -1 is printed.

    Complexity Analysis:  
 
    Time Complexity: O(n^2).
    
Method 2: Traverse the array in reverse order, while current element is greater then top element on auxillary stack, keep removing the elements from stack. If stack is empty, there is no greater element, if not, top element is greater. At last, push current element to stack.

    Complexity Analysis:  

    Space Complexity: O(N)
    Time Complexity: O(N).
     
    
*/

vector<long long> nextLargerElement(vector<long long> arr, int n){
    
    stack<long long> st;
    vector<long long> ans;
    for(int i=n-1;i>=0;i--) {
        if(st.empty()) {
            ans.push_back(-1);
            st.push(arr[i]);
        } else {
            while(!st.empty() && st.top()<arr[i]) {
                st.pop();
            }
            if(st.empty()) {
                 ans.push_back(-1);
            } else {
                ans.push_back(st.top());
            }
            st.push(arr[i]);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
