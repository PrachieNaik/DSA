/*

Problem statement: Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

Approaches:

Method 1: Traverse through all oranges in multiple rounds. In every round, rot the oranges to the adjacent position of oranges which were rotten in the last round.

    Algorithm: 
    Create a variable no = 2 and changed = false
    Run a loop until there is no cell of the matrix which is changed in an iteration.
    Run a nested loop and traverse the matrix. If the element of the matrix is equal to no then assign the adjacent elements to no + 1 if the adjacent element’s value is equal to 1, i.e. not rotten, and update changed to true.
    Traverse the matrix and check if there is any cell which is 1. If 1 is present return -1
    Else return no – 2

    Complexity Analysis: 
    Time Complexity : O(max(R,C) * R *C). 
    The matrix needs to be traversed again and again until there is no change in the matrix, that can happen max(R,C) times. So time complexity is O(max(R,C) * R *C).
    Space Complexity:O(1). 
    No extra space is required.
    
Method 2: The idea is to use Breadth First Search. The condition of oranges getting rotten is when they come in contact with other rotten oranges. This is similar to breadth-first search where the graph is divided into layers or circles and the search is done from lower or closer layers to deeper or higher layers. In the previous approach, the idea was based on BFS but the implementation was poor and inefficient. To find the elements whose values are no the whole matrix had to be traversed. So that time can be reduced by using this efficient approach of BFS. 

    Algorithm: 
    Create an empty queue Q. 
    Find all rotten oranges and enqueue them to Q. Also, enqueue a delimiter to indicate the beginning of the next time frame.
    Run a loop While Q is not empty
    Do following while delimiter in Q is not reached
    Dequeue an orange from the queue, rot all adjacent oranges. While rotting the adjacent, make sure that the time frame is incremented only once. And the time frame is not incremented if there are no adjacent oranges.
    Dequeue the old delimiter and enqueue a new delimiter. The oranges rotten in the previous time frame lie between the two delimiters.

    Complexity Analysis: 
    Time Complexity: O( R *C). 
    Each element of the matrix can be inserted into the queue only once so the upper bound of iteration is O(R*C), i.e. the number of elements. So time complexity is O(R *C).
    Space Complexity: O(R*C). 
    To store the elements in a queue O(R*C) space is needed

*/

int orangesRotting(vector<vector<int>>& mat) {
    
    int row = mat.size();
    int col = mat[0].size();
    
    queue<pair<int,int>>q;
    for(int i = 0 ; i < row ; i++) {
        for(int j = 0 ; j < c ; j++) {
            if(mat[i][j] == 2) {
                q.push({i,j});
            }
        }
    }
    q.push({-1,-1});
    
    int time=0;
    vector<int>rowOffset={-1,0,1,0};
    vector<int>colOffset={0,1,0,-1};
    
    while(!q.empty()) {
        
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        if(x == -1 && y == -1) {
            if(q.empty()) {
                break;
            } else {
                time++;
                q.push({-1,-1});
            }
        } else {
            for(int i = 0 ; i < 4 ; i++) {
                
                int u = x + rowOffset[i];
                int v = y + colOffset[i];
                
                if( u >= 0 && u <r && v >= 0 && v < c) {
                    if(mat[u][v] == 1) {
                      mat[u][v] = 2;
                      q.push({u,v});
                    }
                }
            }
        }
    }
    
    int flag=0;
    for(int i = 0 ; i < row ; i++) {
        for(int j = 0 ; j < c ; j++) {
            
            if(mat[i][j] == 1) {
                flag = 1;
                break;
            }
        }
        if(flag)
         break;
    }
    
    if(!flag)
        return time;
    else
        return -1;
}
