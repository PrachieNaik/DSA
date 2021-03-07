/*

Problem statement: Given a grid consisting of '0's(Water) and '1's(Land). Find the number of islands. Note: An island is surrounded by water and is formed by 
connecting adjacent lands horizontally or vertically or diagonally i,e in all 8 directions.

Input: grid = {{0,1},{1,0},{1,1},{1,0}}
Output: 1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.

Constraints:
1 <= n, m <= 500

Approach: A group of connected 1s forms an island. A cell in 2D matrix can be connected to 8 neighbours. So, unlike standard DFS(), where we recursively call for 
all adjacent vertices, here we can recursively call for 8 neighbours only. We keep track of the visited 1s so that they are not visited again.

*/
bool vis[500][500];

bool isSafe(vector<vector<char>>& grid, int row, int col) {
    
    return (row >= 0) && (row < grid.size()) && 
            (col >= 0) && (col < grid[0].size()) && 
            (grid[row][col] == '1' && !vis[row][col]); 

}

void DFS(vector<vector<char>>& grid, int row, int col) {
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
    
    vis[row][col] = true;
    
    for(int k = 0;k < 8;k++) {
        if(isSafe(grid, row + rowNbr[k], col + colNbr[k])) {
            DFS(grid, row + rowNbr[k], col + colNbr[k]);
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    memset(vis,0,sizeof(vis));
    int count = 0;
    
    for(int i = 0;i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(!vis[i][j] && grid[i][j] == '1') {
                DFS(grid, i, j);
                ++count;
            }
        }
    }
    
    return count;
}
