/*

Problem statement: Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0. Note: One can move from node u to 
node v only if there's an edge from u to v and find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the graph.
Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

Constraints: 1 ≤ V, E ≤ 10^4

Complexity Analysis: 

Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.
Auxiliary Space: O(V)

*/

vector<int>bfsOfGraph(int V, vector<int> adj[]){
    vector<int> ans;
    vector<bool> vis;
    
    //assign default value to visited array
    for(int i = 0; i < V;i++) {
        vis.push_back(0);
    }
    
    queue<int> q;
    q.push(0);
    
    while(!q.empty()) {
        
        if(!vis[q.front()]) {
            vis[q.front()] = 1;
            ans.push_back(q.front());
            for(int i = 0;i < adj[q.front()].size();i++) {
                if(!vis[adj[q.front()][i]]) {
                    q.push(adj[q.front()][i]);
                }
            }
        }
        
        q.pop();
    }
    return ans;
}
