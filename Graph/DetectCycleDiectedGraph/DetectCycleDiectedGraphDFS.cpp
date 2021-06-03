/*
Problem statement: Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

Approach: Depth First Traversal can be used to detect a cycle in a Graph. DFS for a connected graph produces a tree. There is a cycle in a graph 
only if there is a back edge present in the graph. A back edge is an edge that is from a node to itself (self-loop) or one of its ancestors in the 
tree produced by DFS.

Algorithm: 
Create the graph using the given number of edges and vertices.
Create a recursive function that initializes the current index or vertex, visited, and recursion stack.
Mark the current node as visited and also mark the index in recursion stack.
Find all the vertices which are not visited and are adjacent to the current node. Recursively call the function for those vertices, If the recursive 
function returns true, return true.
If the adjacent vertices are already marked in the recursion stack then return true.
Create a wrapper class, that calls the recursive function for all the vertices and if any function returns true return true. Else if for all vertices
the function returns false return false.

Refer: https://www.youtube.com/watch?v=dc5Pn-YEPVY
*/

bool cycle(int i,int V,vector<int>adj[],bool visited[],bool inr[])
{   visited[i] = true;
    inr[i] = true;
    for(int j = 0;j < adj[i].size();j++)
    {   if(!visited[adj[i][j]] && cycle(adj[i][j],V,adj,visited,inr))
        {   return true;
        }
        else
        {   if(inr[adj[i][j]])
                return true;
        }
    }
    inr[i] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{           
    bool visited[V];
    bool inr[V];
    for(int i = 0;i < V;i++)
    {   visited[i] = false;
        inr[i] = false;
    }
    for(int i = 0;i < V;i++)
    {   if(visited[i] == false)
        {   if(cycle(i,V,adj,visited,inr))
                return true;
        }
    }
    return false;

}
