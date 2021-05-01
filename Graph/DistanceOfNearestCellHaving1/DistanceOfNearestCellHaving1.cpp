/*

Problem statement: Given a binary grid. Find the distance of nearest 1 in the grid for each cell.
The distance is calculated as |i1 – i2| + |j1 – j2|, where i1, j1 are the row number and column number of the current cell and i2, j2 are the row number and column
number of the nearest cell having value 1.
 

Example 1:

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0 
1 1 0 0 
0 0 1 1 
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and (2,1) are at a distance of 1 from 1's at (0,1), (0,2), (0,2), (2,3), (1,0) and (1,1) respectively.
   
Constraints:
1 ≤ n, m ≤ 500

Approach: The idea is to use multisource Breadth-First Search. Consider each cell as a node and each boundary between any two adjacent cells be an edge. Number
each cell from 1 to N*M. Now, push all the node whose corresponding cell value is 1 in the matrix in the queue. Apply BFS using this queue to find the minimum 
distance of the adjacent node.
Algorithm: 
Create a graph with values assigned from 1 to M*N to all vertices. The purpose is to store position and adjacent information.
Create an empty queue.
Traverse all matrix elements and insert positions of all 1s in queue.
Now do a BFS traversal of graph using above created queue.
Run a loop till the size of the queue is greater than 0 then extract the front node of the queue and remove it and insert all its adjacent and unmarked elements.
Update the minimum distance as distance of current node +1 and insert the element in the queue.

Complexity Analysis: 

Time Complexity: O(N*M). 
In BFS traversal every element is traversed only once so time Complexity is O(M*N).
Space Complexity: O(M*N). 
To store every element in the matrix O(M*N) space is required.
*/

vector<vector<int>>nearest(vector<vector<int>>grid){
    int row = grid.size();
    int col = grid[0].size();
    
    vector<vector<int>> dist(grid.size(),vector<int>(grid[0].size(),0));
    queue<pair<int,int>> q;
    
    for(int i = 0; i < row;i++) {
        for(int j = 0;j < col;j++) {
            if(grid[i][j] == 1) {
                q.push({i,j});
            }
        }
    }
    
    int dx[]={1,0,-1,0};
    int dy[]={0,-1,0,1};
    
    while(!q.empty()) {
        pair<int,int> t = q.front();
        q.pop();
        
        for(int i = 0; i < 4;i++) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];
            
            if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 0) {
                dist[nx][ny] = dist[t.first][t.second] + 1;
                grid[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
    return dist;
}
