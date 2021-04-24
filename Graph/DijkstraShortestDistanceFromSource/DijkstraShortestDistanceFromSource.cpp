/*

Problem statement: Given a weighted, undirected and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source 
vertex S.
Note: The Graph doesn't contain any negative weight cycle.

Constraints:
1 ≤ V ≤ 1000
0 ≤ adj[i][j] ≤ 1000
0 ≤ S < V

Algorithm:

    1) Initialize distances of all vertices as infinite.
    
    2) Create an empty priority_queue pq.  Every item of pq is a pair (weight, vertex). Weight (or  distance) is used used as first item  of pair as first item is
       by default used to compare two pairs
    
    3) Insert source vertex into pq and make its distance as 0.
    
    4) While either pq doesn't become empty
        a) Extract minimum distance vertex from pq. Let the extracted vertex be u.
        b) Loop through all adjacent of u and do following for every vertex v.
    
               // If there is a shorter path to v through u. 
               If dist[v] > dist[u] + weight(u, v)
    
                   (i) Update distance of v, i.e., do dist[v] = dist[u] + weight(u, v)
                   (ii) Insert v into the pq (Even if v is already there)
                   
    5) Print distance array dist[] to print all shortest paths. 

Time Complexity: The time complexity remains O(ELogV)) as there will be at most O(E) vertices in priority queue and O(Log E) is same as O(Log V)
Auxiliary Space: O(E).

 
*/

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    vector<int> vis(V,0);
    vector<int> dist(V,INT_MAX);
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    dist[S] = 0;
    pq.push({0,S});
    
    while(!pq.empty()) {
        int vertex = pq.top().second;
        int distance = pq.top().first;
        vis[vertex] = 1;
        pq.pop();
        
        for(auto j:adj[vertex]) {
            int node = j[0];
            int curDis = j[1];
            if(!vis[node] && dist[node] > curDis + dist[vertex]) {
                dist[node] = curDis + dist[vertex];
                pq.push({dist[node],node});
            }
        }
    }
    return dist;
}
