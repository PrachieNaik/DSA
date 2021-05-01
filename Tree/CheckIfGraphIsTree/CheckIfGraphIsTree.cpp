/*

Problem statement: Write a function that returns true if a given undirected graph is tree and false otherwise. For example, the following graph is a tree.

An undirected graph is tree if it has following properties. 
1) There is no cycle. 
2) The graph is connected.

How to detect cycle in an undirected graph? 
We can either use BFS or DFS. For every visited vertex ‘v’, if there is an adjacent ‘u’ such that u is already visited and u is not parent of v, then there is a 
cycle in graph. If we don’t find such an adjacent for any vertex, we say that there is no cycle.
How to check for connectivity? 
Since the graph is undirected, we can start BFS or DFS from any vertex and check if all vertices are reachable or not. If all vertices are reachable, then graph is
connected, otherwise not.
   
*/

// A recursive function that uses visited[] and parent to
// detect cycle in subgraph reachable from vertex v.
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
    // Mark the current node as visited
    visited[v] = true;
  
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        // If an adjacent is not visited, then recur for 
        // that adjacent
        if (!visited[*i])
        {
           if (isCyclicUtil(*i, visited, v))
              return true;
        }
  
        // If an adjacent is visited and not parent of current
        // vertex, then there is a cycle.
        else if (*i != parent)
           return true;
    }
    return false;
}
  
// Returns true if the graph is a tree, else false.
bool Graph::isTree()
{
    // Mark all the vertices as not visited and not part of 
    // recursion stack
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
  
    // The call to isCyclicUtil serves multiple purposes.
    // It returns true if graph reachable from vertex 0 
    // is cyclcic. It also marks all vertices reachable 
    // from 0.
    if (isCyclicUtil(0, visited, -1))
             return false;
  
    // If we find a vertex which is not reachable from 0 
    // (not marked by isCyclicUtil(), then we return false
    for (int u = 0; u < V; u++)
        if (!visited[u])
           return false;
  
    return true;
}
