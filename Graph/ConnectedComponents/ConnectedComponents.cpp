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
The idea is to use a variable count to store the number of connected components and do the following steps: 

Initialize all vertices as unvisited.
For all the vertices check if a vertex has not been visited, then perform DFS on that vertex and increment the variable count by 1.

*/

int vis[100001];
vector<int >vec[100001];

void dfs(int node)
{
    vis[node] = 1;
    for(int i = 0;i < vec[node].size();i++)
    {
        int child = vec[node][i];
        if(vis[child] == 0)
            dfs(child);
    }
}
int main(){
    int n,e,a,b;
    cin>>n>>e;
    while(e--)
    {
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        if(vis[i] == 0)
        {
            ans++;
            dfs(i);
        }
    }
    cout<<ans;
}
