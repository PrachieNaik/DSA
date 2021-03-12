/*

Problem statement: In operating systems that use paging for memory management, page replacement algorithm are needed to decide which page needs to be replaced when 
the new page comes in. Whenever a new page is referred and is not present in memory, the page fault occurs and Operating System replaces one of the existing pages 
with a newly needed page. Given a sequence of pages and memory capacity, your task is to find the number of page faults using Least Recently Used (LRU) Algorithm.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains n number of pages and next line contains space seaprated 
sequence of pages. The following line consist of the capacity of the memory.

Note: Pages are referred in the order left to right from the array (i.e index 0 page is referred first then index 1 and so on). Memory is empty at the start.

Output: The number of page faults.

Constraints: 1<=T<=100, 1<=n<=1000, 4<=capacity<=100

Example:
Input:
2
9
5 0 1 3 2 4 1 0 5
4
8
3 1 0 2 5 4 1 2
4

Output:
8
7

Approach:

Let capacity be the number of pages that memory can hold.  Let set be the current set of pages in memory.

    1- Start traversing the pages.
     i) If set holds less pages than capacity.
       a) Insert page into the set one by one until the size  of set reaches capacity or all page requests are processed.
       b) Simultaneously maintain the recent occurred index of each page in a map called indexes.
       c) Increment page fault
     ii) Else 
       If current page is present in set, do nothing.
       Else 
         a) Find the page in the set that was least recently used. We find it using index array. We basically need to replace the page with minimum index.
         b) Replace the found page with current page.
         c) Increment page faults.
         d) Update index of current page.
    
    2. Return page faults.

Time Complexity : O(N * logN), where N is the size of cost array.

*/

#include <bits/stdc++.h>
using namespace std;
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int pages[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>pages[i];
	    }
	    int capacity;
	    cin>>capacity;
	    
	    unordered_set<int> s; 
  
        // To store least recently used indexes 
        // of pages. 
        unordered_map<int, int> indexes; 
      
        // Start from initial page 
        int page_faults = 0; 
        for (int i=0; i<n; i++) 
        { 
            // Check if the set can hold more pages 
            if (s.size() < capacity) 
            { 
                // Insert it into set if not present 
                // already which represents page fault 
                if (s.find(pages[i])==s.end()) 
                { 
                    s.insert(pages[i]); 
      
                    // increment page fault 
                    page_faults++; 
                } 
      
                // Store the recently used index of 
                // each page 
                indexes[pages[i]] = i; 
            } 
      
            // If the set is full then need to perform lru 
            // i.e. remove the least recently used page 
            // and insert the current page 
            else
            { 
                // Check if current page is not already 
                // present in the set 
                if (s.find(pages[i]) == s.end()) 
                { 
                    // Find the least recently used pages 
                    // that is present in the set 
                    int lru = INT_MAX, val; 
                    for (auto it=s.begin(); it!=s.end(); it++) 
                    { 
                        if (indexes[*it] < lru) 
                        { 
                            lru = indexes[*it]; 
                            val = *it; 
                        } 
                    } 
      
                    // Remove the indexes page 
                    s.erase(val); 
      
                    // insert the current page 
                    s.insert(pages[i]); 
      
                    // Increment page faults 
                    page_faults++; 
                } 
      
                // Update the current page index 
                indexes[pages[i]] = i; 
            } 
        } 
        cout<<page_faults<<endl;
    }
	return 0;
}
