/*

Problem statement: Given an undirected, connected and weighted graph, find Minimum Spanning Tree (MST) of the graph using Prim’s algorithm.

Input : Adjacency List representation of graph
Output :  Edges in MST

Note :  There can be multiple spanning trees

Algorithm: The idea is, not to insert all vertices in priority queue, but only those which are not MST and have been visited through a vertex that has included in 
MST. We keep track of vertices included in MST in a separate boolean array inMST[].

    1) Initialize keys of all vertices as infinite and 
       parent of every vertex as -1.
    
    2) Create an empty priority_queue pq.  Every item
       of pq is a pair (weight, vertex). Weight (or 
       key) is used used as first item  of pair
       as first item is by default used to compare
       two pairs.
    
    3) Initialize all vertices as not part of MST yet.
       We use boolean array inMST[] for this purpose.
       This array is required to make sure that an already
       considered vertex is not included in pq again. This
       is where Ptim's implementation differs from Dijkstra.
       In Dijkstr's algorithm, we didn't need this array as
       distances always increase. We require this array here 
       because key value of a processed vertex may decrease
       if not checked.
    
    4) Insert source vertex into pq and make its key as 0.
    
    5) While either pq doesn't become empty 
        a) Extract minimum key vertex from pq. 
           Let the extracted vertex be u.
    
        b) Include u in MST using inMST[u] = true.
    
        c) Loop through all adjacent of u and do 
           following for every vertex v.
    
               // If weight of edge (u,v) is smaller than
               // key of v and v is not already in MST
               If inMST[v] = false && key[v] > weight(u, v)
    
                   (i) Update key of v, i.e., do
                         key[v] = weight(u, v)
                   (ii) Insert v into the pq 
                   (iv) parent[v] = u
                   
    6) Print MST edges using parent array.

Time Complexity: time complexity remains O(E Log V) as there will be at most O(E) vertices in priority queue and O(Log E) is same as O(Log V).
Auxiliary Space: O(E).

 
*/

// Prints shortest paths from src to all other vertices
void primMST(vector<pair<int,int> > adj[], int V)
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
 
    int src = 0; // Taking vertex 0 as source
 
    // Create a vector for keys and initialize all
    // keys as infinite (INF)
    vector<int> key(V, INF);
 
    // To store parent array which in turn store MST
    vector<int> parent(V, -1);
 
    // To keep track of vertices included in MST
    vector<bool> inMST(V, false);
 
    // Insert source itself in priority queue and initialize
    // its key as 0.
    pq.push(make_pair(0, src));
    key[src] = 0;
 
    /* Looping till priority queue becomes empty */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum key
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted key (key must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();
 
        inMST[u] = true; // Include vertex in MST
 
        // Traverse all adjacent of u
        for (auto x : adj[u])
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = x.first;
            int weight = x.second;
 
            // If v is not in MST and weight of (u,v) is smaller
            // than current key of v
            if (inMST[v] == false && key[v] > weight)
            {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
 
    // Print edges of MST using parent array
    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
}
