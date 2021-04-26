/*

Problem statement: Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

Constraints:
1 ≤ V, E ≤ 10^5

Approach: This is another method based on Union-Find. This method assumes that the graph doesn’t contain any self-loops. 
We can keep track of the subsets in a 1D array, let’s call it parent[].

Time Complexity: O(V + E)
Space Complexity: O(V)
 
*/
 
int findSet(int currentVertex, int parent[]) {
    if(parent[currentVertex]==-1) {
        return currentVertex;
    }
    findSet(parent[currentVertex], parent);
}

bool isCycle(int V,vector<int> g[] )
{
    int parent[V];
    for(int i=0;i<V;i++) {
        parent[i] = -1;
    }

    int s1,s2;
    for(int i=0;i<V;i++) {
        vector<int>::iterator it;
        for(it=g[i].begin(); it!=g[i].end(); it++) {
            s1 = findSet(i, parent);
            s2 = findSet(*it, parent);
            if(s1!=s2) {
                parent[*it] = i;
            } else {
                if(parent[i]!=*it) {
                    return true;
                }
            }
        }
    }
    return false;
}
