//GRAPHS BFS

#include<bits/stdc++.h>
using namespace std;

//47. NEAREST EXIT FROM ENTRANCE IN MAZE                                   {T.C = O(N*M), S.C = O(N)}
/*
We use simple BFS approach, take queue initialize with entrance position , take count of minSteps =0, mark grid visited (grid[en[0]][en[1]] = '+')
while !q.empty() take sz of queue in that while (que sze--) simply extract top element and check the condition if exit find return minSteps else
return -1;
*/
class Solution {
public:
    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});                 //push initial position(entrance of maze)
        int minSteps = 0;

        // mark the entrance cell as visited
        grid[entrance[0]][entrance[1]] = '+';

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto frontNode = q.front();
                q.pop();
                int i = frontNode.first;
                int j = frontNode.second;

                // if exit cell is found return minSteps
                if(!(i == entrance[0] && j == entrance[1]) && (i == 0 || j == 0 || i == n - 1 || j == m - 1)){
                    return minSteps;
                }

                //explore all neighbours
                vector<vector<int>>directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                for(auto it : directions){
                    int new_i = i + it[0];
                    int new_j = j + it[1];

                    if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] != '+'){
                        grid[new_i][new_j] = '+';
                        q.push({new_i, new_j});
                    }
                }
            }
            minSteps++;
        }
        return -1;
    }
};
/*
Example 1:
Input: maze = [["+","+",".","+"],
               [".",".",".","+"],
               ["+","+","+","."]], 
       entrance = [1,2]
Output: 1
Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
Initially, you are at the entrance cell [1,2].
- You can reach [1,0] by moving 2 steps left.
- You can reach [0,2] by moving 1 step up.
It is impossible to reach [2,3] from the entrance.
Thus, the nearest exit is [0,2], which is 1 step away.

Example 2:
Input: maze = [["+","+","+"],
               [".",".","."],
               ["+","+","+"]],
       entrance = [1,0]
Output: 2
Explanation: There is 1 exit in this maze at [1,2].
[1,0] does not count as an exit since it is the entrance cell.
Initially, you are at the entrance cell [1,0].
- You can reach [1,2] by moving 2 steps right.
Thus, the nearest exit is [1,2], which is 2 steps away.

Example 3:
Input: maze = [[".","+"]],
       entrance = [0,0]
Output: -1
Explanation: There are no exits in this maze.
*/


//48. ROTTING ORANGES                                                         {T.C = O(N*M), S.C = O(N)}
/*
Take queue{{row, col}, time} traverse in a grid if its 2 (rotten) push in queue with 0 time and mark vis = 2, else vis = 0(not rotten) , if element
is 1 then cntFreshOranges++, intitialze variable time and count = 0, apply bfs and check for neighbours , finally return time.
*/
class Solution {
  public:
    int orangesRotting(vector<vector<int>>&grid) {
      int n = grid.size();
      int m = grid[0].size();

      queue<pair<pair<int, int>,int>>q;                // store {{row, column}, time}
      int vis[n][m];
      int cntFresh = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (grid[i][j] == 2) {                      // if cell contains rotten orange push in queue with time 0 and mark vis(rotten {2})
            q.push({{i, j}, 0}); 
            vis[i][j] = 2;                            
          }
          else {                                      // if not rotten
            vis[i][j] = 0;
          }
          if (grid[i][j] == 1){                       // count fresh oranges
            cntFresh++;
          } 
        }
      }

      int tm = 0;
      int cnt = 0;
      vector<vector<int>>directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

      // bfs traversal (until the queue becomes empty)
      while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();

        //explore neighbours
        for (auto it : directions) {
          int nrow = r + it[0];
          int ncol = c + it[1];
          if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
            q.push({{nrow, ncol}, t + 1});                // push in queue with timer increased
            vis[nrow][ncol] = 2;                          // mark as rotten
            cnt++;
          }
        }
      }
      
      if (cnt != cntFresh){                              // if all oranges are not rotten
        return -1;                     
      } 
      return tm;
    }
};
/*
Example 1:
Input: grid = [[2,1,1],
               [1,1,0],
               [0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],
               [0,1,1],
               [1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
*/
