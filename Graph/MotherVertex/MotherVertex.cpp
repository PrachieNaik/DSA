/*

Problem statement: Find a Mother Vertex in a Graph
What is a Mother Vertex? 
A mother vertex in a graph G = (V,E) is a vertex v such that all other vertices in G can be reached by a path from v.
A Naive approach : 
A trivial approach will be to perform a DFS/BFS on all the vertices and find whether we can reach all the vertices from that vertex. This approach takes
O(V(E+V)) time, which is very inefficient for large graphs.

Can we do better? 
We can find a mother vertex in O(V+E) time. The idea is based on Kosaraju’s Strongly Connected Component Algorithm. In a graph of strongly connected 
components, mother vertices are always vertices of source component in component graph. The idea is based on below fact.
If there exist mother vertex (or vertices), then one of the mother vertices is the last finished vertex in DFS. (Or a mother vertex has the maximum 
finish time in DFS traversal).
A vertex is said to be finished in DFS if a recursive call for its DFS is over, i.e., all descendants of the vertex have been visited. 

How does the above idea work? 
Let the last finished vertex be v. Basically, we need to prove that there cannot be an edge from another vertex u to v if u is not another mother 
vertex (Or there cannot exist a non-mother vertex u such that u-→v is an edge). There can be two possibilities.

Recursive DFS call is made for u before v. If an edge u-→v exists, then v must have finished before u because v is reachable through u and a vertex
finishes after all its descendants.
Recursive DFS call is made for v before u. In this case also, if an edge u-→v exists, then either v must finish before u (which contradicts our 
assumption that v is finished at the end) OR u should be reachable from v (which means u is another mother vertex).
Algorithm : 

Do DFS traversal of the given graph. While doing traversal keep track of last finished vertex ‘v’. This step takes O(V+E) time.
If there exist mother vertex (or vertices), then v must be one (or one of them). Check if v is a mother vertex by doing DFS/BFS from v. This step also 
takes O(V+E) time.

*/

// A recursive function to print DFS starting from v
void Graph::DFSUtil(int v, vector<bool> &visited)
{
    // Mark the current node as visited and print it
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
// Returns a mother vertex if exists. Otherwise returns -1
int Graph::findMother()
{
    // visited[] is used for DFS. Initially all are
    // initialized as not visited
    vector <bool> visited(V, false);
 
    // To store last finished vertex (or mother vertex)
    int v = 0;
 
    // Do a DFS traversal and find the last finished
    // vertex 
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            DFSUtil(i, visited);
            v = i;
        }
    }
 
    // If there exist mother vertex (or vetices) in given
    // graph, then v must be one (or one of them)
 
    // Now check if v is actually a mother vertex (or graph
    // has a mother vertex).  We basically check if every vertex
    // is reachable from v or not.
 
    // Reset all values in visited[] as false and do
    // DFS beginning from v to check if all vertices are
    // reachable from it or not.
    fill(visited.begin(), visited.end(), false);
    DFSUtil(v, visited);
    for (int i=0; i<V; i++)
        if (visited[i] == false)
            return -1;
 
    return v;
}
