/*

Problem statement: Given a connected undirected graph. Perform a Depth First Traversal of the graph. Note: Use recursive approach to find the DFS traversal of the 
graph starting from the 0th vertex from left to right according to the graph..

Constraints: 1 ≤ V, E ≤ 10^4

Approach: Depth-first search is an algorithm for traversing or searching tree or graph data structures. The algorithm starts at the root node (selecting some 
arbitrary node as the root node in the case of a graph) and explores as far as possible along each branch before backtracking. So the basic idea is to start from 
the root or any arbitrary node and mark the node and move to the adjacent unmarked node and continue this loop until there is no unmarked adjacent node. Then 
backtrack and check for other unmarked nodes and traverse them. Finally print the nodes in the path.

    Algorithm: 
    Create a recursive function that takes the index of node and a visited array.
    Mark the current node as visited and print the node.
    Traverse all the adjacent and unmarked nodes and call the recursive function with index of adjacent node.

Complexity Analysis: 

Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V). Since, an extra visited array is needed of size V.

*/

void dfstraversal(vector<int> g[], int s, vector<bool> &v,vector<int> &ans)
{
    // add current index to answer
    ans.push_back(s);
    
    // mark current index as visitec
    v[s] = 1;
    
    //traverse all the connected node if they are not already visited
    for(int i = 0;i < g[s].size();i++)
    {
        if(!v[g[s][i]])
            dfstraversal(g,g[s][i],v,ans);
    }
}
vector <int> dfs(vector<int> g[], int N)
{
    vector <int> ans;
    vector <bool> vis;
    
    //assigning visited array to default value
    for(int i = 0;i < N;i++)
        vis.push_back(0);
        
    //utility functtion for dfs traversal, will save answer in ans vector
    dfstraversal(g,0,vis,ans);
    
    return ans;
}
