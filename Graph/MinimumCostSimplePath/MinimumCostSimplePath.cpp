/*

Problem statement: Given a directed graph, which may contain cycles, where every edge has weight, the task is to find the minimum cost of any simple path from a 
given source vertex ‘s’ to a given destination vertex ‘t’. Simple Path is the path from one vertex to another such that no vertex is visited more than once. If 
there is no simple path possible then return INF(infinite).

Examples: 

Input : V = 5, E = 6
        s = 0, t = 2
    graph[][] =      0   1   2   3   4  
                 0  INF -1  INF  1  INF
                 1  INF INF -2  INF INF
                 2  -3  INF INF INF INF
                 3  INF INF -1  INF INF
                 4  INF INF INF  2  INF
 
Output : -3 
Explanation : 
The minimum cost simple path between 0 and 2 is given by:
0 -----> 1 ------> 2 whose cost is (-1) + (-2) = (-3). 

Approach :
The main idea to solve the above problem is to traverse through all simple paths from s to t using a modified version of Depth First Search and find the minimum 
cost path amongst them. One important observation about DFS is that it traverses one path at a time, hence we can traverse separate paths independently using DFS
by marking the nodes as unvisited before leaving them.
A simple solution is to start from s, go to all adjacent vertices, and follow recursion for further adjacent vertices until we reach the destination. 
This algorithm will work even when negative weight cycles or self edges are present in the graph.

*/

// Function to do DFS through the nodes
int minimumCostSimplePath(int u, int destination,
                    bool visited[], int graph[][V])
{
 
    // check if we find the destination
    // then further cost will be 0
    if (u == destination)
        return 0;
 
    // marking the current node as visited
    visited[u] = 1;
 
    int ans = INF;
 
    // traverse through all
    // the adjacent nodes
    for (int i = 0; i < V; i++) {
        if (graph[u][i] != INF && !visited[i]) {
 
            // cost of the further path
            int curr = minimumCostSimplePath(i,
                        destination, visited, graph);
 
            // check if we have reached the destination
            if (curr < INF) {
 
                // Taking the minimum cost path
                ans = min(ans, graph[u][i] + curr);
            }
        }
    }
 
    // unmarking the current node
    // to make it available for other
    // simple paths
    visited[u] = 0;
 
    // returning the minimum cost
    return ans;
}
 
