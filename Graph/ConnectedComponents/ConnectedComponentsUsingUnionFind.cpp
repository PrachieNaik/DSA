/*
Problem statement: Given n, i.e. total number of nodes in an undirected graph numbered from 1 to n and an integer e, i.e. total number of edges in
the graph. Calculate the total number of connected components in the graph. A connected component is a set of vertices in a graph that are linked to
each other by paths.

Input Format:
First line of input line contains two integers n and e. Next e line will contain two integers u and v meaning that node u and node v are connected to 
each other in undirected fashion. 
Output Format:
For each input graph print an integer x denoting total number of connected components.

Constraints:
All the input values are well with in the integer range.

Sample Input
8 5
1 2
2 3
2 4
3 5
6 7
Sample Output
3

Approach:
The problem can be solved using Disjoint Set Union algorithm. Follow the steps below to solve the problem:

In DSU algorithm, there are two main functions, i.e. connect() and root() function.
connect(): Connects an edge.
root(): Recursively determine the topmost parent of a given edge.
For each edge {a, b}, check if a is connected to b or not. If found to be false, connect them by appending their top parents.
After completing the above step for every edge, print the total number of the distinct top-most parents for each vertex.
*/

// Stores the parent of each vertex
int parent[1000000];
 
// Function to find the topmost
// parent of vertex a
int root(int a)
{
    // If current vertex is
    // the topmost vertex
    if (a == parent[a]) {
        return a;
    }
 
    // Otherwsie, set topmost vertex of
    // its parent as its topmost vertex
    return parent[a] = root(parent[a]);
}
 
// Function to connect the component
// having vertex a with the component
// having vertex b
void connect(int a, int b)
{
    // Connect edges
    a = root(a);
    b = root(b);
 
    if (a != b) {
        parent[b] = a;
    }
}
 
// Function to find unique top most parents
void connectedComponents(int n)
{
    set<int> s;
 
    // Traverse all vertices
    for (int i = 0; i < n; i++) {
 
        // Insert all topmost
        // vertices obtained
        s.insert(parent[i]);
    }
 
    // Print count of connected components
    cout << s.size() << '\n';
}
 
// Function to print answer
void printAnswer(int N, vector<vector<int> > edges)
{
 
    // Setting parent to itself
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }
 
    // Traverse all edges
    for (int i = 0; i < edges.size(); i++) {
        connect(edges[i][0], edges[i][1]);
    }
 
    // Print answer
    connectedComponents(N);
}
