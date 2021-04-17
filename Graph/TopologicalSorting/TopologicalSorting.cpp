/*

Problem statement: Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes
before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

In DFS, we start from a vertex, we first print it and then recursively call DFS for its adjacent vertices. In topological sorting, we use a temporary stack. 
We don’t print the vertex immediately, we first recursively call topological sorting for all its adjacent vertices, then push it to a stack. Finally, print 
contents of the stack. Note that a vertex is pushed to stack only when all of its adjacent vertices (and their adjacent vertices and so on) are already in the stack.

Here, we can also use vector instead of the stack. If the vector is used then print the elements in reverse order to get the topological sorting.

Applications: 
Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs. In computer science, applications of this type arise in instruction 
scheduling, ordering of formula cell evaluation when recomputing formula values in spreadsheets, logic synthesis, determining the order of compilation tasks to 
perform in make files, data serialization, and resolving symbol dependencies in linkers

Complexity Analysis: 

Time Complexity: O(V+E). 
The above algorithm is simply DFS with an extra stack. So time complexity is the same as DFS which is.
Auxiliary space: O(V). 
The extra space is needed for the stack.

*/

void topoSortUtil(vector<int> &ans,vector<int> &vis, vector<int> adj[],int index) {
    vis[index] = 1;
    for(auto i = adj[index].begin(); i != adj[index].end(); ++i) {
        if(vis[*i] == 0) {
            topoSortUtil(ans,vis,adj,*i);
        }
    }
    ans.push_back(index);
}
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<int> vis;
    for(int i = 0 ;i < V;i++) {
        vis.push_back(0);
    }
    for(int i = 0 ;i < V;i++) {
        if(vis[i] == 0) {
            topoSortUtil(ans,vis,adj,i);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
