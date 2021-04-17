/*

Problem statement: Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, vertex u comes before
v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

The approach is based on the below fact:

A DAG G has at least one vertex with in-degree 0 and one vertex with out-degree 0.

Proof: There’s a simple proof to the above fact is that a DAG does not contain a cycle which means that all paths will be of finite length. Now let S be the longest
path from u(source) to v(destination). Since S is the longest path there can be no incoming edge to u and no outgoing edge from v, if this situation had occurred 
then S would not have been the longest path => indegree(u) = 0 and outdegree(v) = 0

Algorithm: Steps involved in finding the topological ordering of a DAG:
Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.

Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)

Step-3: Remove a vertex from the queue (Dequeue operation) and then.
        Increment count of visited nodes by 1.
        Decrease in-degree by 1 for all its neighboring nodes.
        If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.
        
Step 5: Repeat Step 3 until the queue is empty.

Step 6: If count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not possible for the given graph.

Complexity Analysis:

Time Complexity: O(V+E).
The outer for loop will be executed V number of times and the inner for loop will be executed E number of times.
Auxillary Space: O(V).
The queue needs to store all the vertices of the graph. So the space required is O(V)

*/

void Graph::topologicalSort()
{
    // Create a vector to store indegrees of all vertices. Initialize all indegrees as 0.
    vector<int> in_degree(V, 0);
  
    // Traverse adjacency lists to fill indegrees of vertices.  This step takes O(V+E) time
    for (int u = 0; u < V; u++) {
        list<int>::iterator itr;
        for (itr = adj[u].begin();
             itr != adj[u].end(); itr++)
            in_degree[*itr]++;
    }
  
    // Create an queue and enqueue all vertices with indegree 0
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0)
            q.push(i);
  
    // Initialize count of visited vertices
    int cnt = 0;
  
    // Create a vector to store result (A topological ordering of the vertices)
    vector<int> top_order;
  
    // One by one dequeue vertices from queue and enqueue adjacents if indegree of adjacent becomes 0
    while (!q.empty()) {
        // Extract front of queue (or perform dequeue) and add it to topological order
        int u = q.front();
        q.pop();
        top_order.push_back(u);
  
        // Iterate through all its neighbouring nodes of dequeued node u and decrease their in-degree by 1
        list<int>::iterator itr;
        for (itr = adj[u].begin();
             itr != adj[u].end(); itr++)
  
            // If in-degree becomes zero,add it to queue
            if (--in_degree[*itr] == 0)
                q.push(*itr);
  
        cnt++;
    }
  
    // Check if there was a cycle
    if (cnt != V) {
        cout << "There exists a cycle in the graph\n";
        return;
    }
  
    // Print topological order
    for (int i = 0; i < top_order.size(); i++)
        cout << top_order[i] << " ";
    cout << endl;
}
