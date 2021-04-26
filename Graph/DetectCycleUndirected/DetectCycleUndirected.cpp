/*

Problem statement: Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

Constraints:
1 ≤ V, E ≤ 10^5

Approach: Run a DFS from every unvisited node. Depth First Traversal can be used to detect a cycle in a Graph. DFS for a connected graph produces a tree. There is 
a cycle in a graph only if there is a back edge present in the graph. A back edge is an edge that is joining a node to itself (self-loop) or one of its ancestor in
the tree produced by DFS. 
To find the back edge to any of its ancestor keep a visited array and if there is a back edge to any visited node then there is a loop and return true.

Algorithm: 

Create the graph using the given number of edges and vertices.
Create a recursive function that that current index or vertex, visited and recursion stack.
Mark the current node as visited and also mark the index in recursion stack.
Find all the vertices which are not visited and are adjacent to the current node. Recursively call the function for those vertices, If the recursive function 
returns true return true.
If the adjacent vertices are already marked in the recursion stack then return true.
Create a wrapper class, that calls the recursive function for all the vertices and if any function returns true, return true.
Else if for all vertices the function returns false return false.

Time Complexity: O(V+E). 
The program does a simple DFS Traversal of the graph which is represented using adjacency list. So the time complexity is O(V+E).
Space Complexity: O(V). 
To store the visited array O(V) space is required.

 */
 
bool cyclic(vector<int> g[],int u,int parent,vector<bool> &visited)
{
    visited[u] = true;
    
    for(int i=0;i<g[u].size();i++)
    {
        if(!visited[g[u][i]])
        {
            if(cyclic(g,g[u][i],u,visited))
                return true;
        }
        else if(parent != g[u][i])
                return true;
    }
    return false;
    
}

bool isCycle(int V, vector<int>adj[]){
    vector<bool> visited(V,false);

   for(int u=0;u<V;u++)
   {
       if(!visited[u])
       {
           if(cyclic(adj,u,-1,visited))
                return true;
       }
   }
   return false;
}
