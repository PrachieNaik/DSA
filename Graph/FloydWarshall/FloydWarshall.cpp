/*

The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph. The Graph is represented as adjancency matrix, 
and the matrix denotes the weight of the edegs (if it exists) else -1. Do it in-place.
 

Example 1:

Input: matrix = {{0,25},{-1,0}}
Output: {{0,25},{-1,0}}
Explanation: The shortest distance between
every pair is already given(if it exists).
Example 2:

Input: matrix = {{0,1,43},{1,0,6},{-1,-1,0}}
Output: {{0,1,7},{1,0,6},{-1,-1,0}}
Explanation: We can reach 3 from 1 as 1->2->3
and the cost will be 1+6=7 which is less than 
43.

Constraints:
1 <= n <= 100

We initialize the solution matrix same as the input graph matrix as a first step. Then we update the solution matrix by considering all vertices as an intermediate 
vertex. The idea is to one by one pick all vertices and updates all shortest paths which include the picked vertex as an intermediate vertex in the shortest path. 
When we pick vertex number k as an intermediate vertex, we already have considered vertices {0, 1, 2, .. k-1} as intermediate vertices. For every pair (i, j) of the
source and destination vertices respectively, there are two possible cases. 

1) k is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is. 
2) k is an intermediate vertex in shortest path from i to j. We update the value of dist[i][j] as dist[i][k] + dist[k][j] if dist[i][j] > dist[i][k] + dist[k][j]

The following figure shows the above optimal substructure property in the all-pairs shortest path problem.

Time Complexity: O(V^3)
*/

void shortest_distance(vector<vector<int>> &dist){
    int v = dist.size();
    for (int k = 0;k < v;k++){
        for (int i = 0;i < v;i++){
            for(int j = 0;j < v;j++){
                if(dist[i][k] != -1 && dist[k][j] != -1 && dist[i][k] + dist[k][j] < dist[i][j] ){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
