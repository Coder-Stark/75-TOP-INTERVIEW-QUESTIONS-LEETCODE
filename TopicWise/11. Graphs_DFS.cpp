//GRAPHS DFS

#include<bits/stdc++.h>
using namespace std;

//GRAPH
//MINIMUM DISTANCE FINDING ALGORITHM
/*
1. DIJKSTRA'S ALGO                  {not work for -ve weighted graph}
2. BELLMANFORD ALGO                 {work for -ve weighted graph}
3. FLOYD WARSHALL ALGO              {brute force algo}
*/
//MINIMUM SPANNING TREE ALGORITHM
/*
1. KRUSKAL'S ALGO          {intermediate result may be or may be not connected}
2. PRIM'S ALGO             {intermediate result always connected} 
*/

//BFS OF GRAPH                                                      {T.C = O(N+M/ V+E), S.C = O(N+M / V+E)}   //N = nodes, E = edges
/*
We required 3 DS (ans, vis(bool), queue) and also initialize nodeindex = 0, push node in queue and mark vis[node] = 1 and push node in ans
now traverse queue, take out frontNode and push in ans, after that traverse adj[frontNode] , if (!vis[it]) then push it and mark vis[it]=1.
*/
class Solution {
  public:
    void BFS(vector<int>adj[], vector<int>&ans, vector<bool>&vis, int node){
        queue<int>q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            for(auto it : adj[frontNode]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<bool>vis(V, 0);
        BFS(adj, ans, vis, 0);                        //node index = 0
        return ans;
    }
};
/*
Example 1:
Input:
V = 5, E = 4
adj = {{1,2,3},{},{4},{},{}}
Output: 
0 1 2 3 4
Explanation: 
0 is connected to 1 , 2 , 3.
2 is connected to 4.
so starting from 0, it will go to 1 then 2
then 3. After this 2 to 4, thus bfs will be
0 1 2 3 4.

Example 2:
Input:
V = 3, E = 2
adj = {{1,2},{},{}}
Output: 
0 1 2
Explanation:
0 is connected to 1 , 2.
so starting from 0, it will go to 1 then 2,
thus bfs will be 0 1 2. 
*/


//DFS OF GRAPH                                                        {T.C = O(N+M / V+E), S.C = O(N+M / V+E)}
/*
We required 2 DS (ans, vis(bool)) and also initialize nodeindex = 0,  mark vis[node] = 1 and push node in ans,  now traverse adj[node],
if (!vis[it]) then push it and mark vis[it]=1 and make recursive call to DFS.
*/
class Solution {
  public:
    void DFS(vector<int>adj[], vector<int>&ans, vector<bool>&vis, int node){
        vis[node] = 1;
        ans.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                DFS(adj, ans, vis, it);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<bool>vis(V, 0);
        DFS(adj, ans, vis, 0);                       //0 = nodeindex
        return ans;

        /*
        //handle disconnected components
        for(int i = 0 ; i < V ; i++){
            dfs(0, adj, ans, vis);                                  //0 = starting index or node
        }
        */
    }
};
/*
Example 1:
Input: V = 5 , adj = [[2,3,1] , [0], [0,4], [0], [2]]
Output: 0 2 4 3 1
Explanation: 
0 is connected to 2, 3, 1.
1 is connected to 0.
2 is connected to 0 and 4.
3 is connected to 0.
4 is connected to 2.
so starting from 0, it will go to 2 then 4,
and then 3 and 1.
Thus dfs will be 0 2 4 3 1.

Example 2:
Input: V = 4, adj = [[1,3], [2,0], [1], [0]]
Output: 0 1 2 3
Explanation:
0 is connected to 1 , 3.
1 is connected to 0, 2. 
2 is connected to 1.
3 is connected to 0. 
so starting from 0, it will go to 1 then 2
then back to 0 then 0 to 3
thus dfs will be 0 1 2 3. 
*/


/*----------------------------------------------------- GRAPHS DFS ------------------------------------------------*/
//43. KEYS AND ROOMS                                             {T.C = O(N+M), S.C = O(N+M)}
/*
Simple dfs , take bool vector and call dfs if after dfs any room is left or(vis == false) then return false else true.
*/
class Solution {
public:
    void dfs(vector<vector<int>>&rooms, vector<bool>&vis, int node){
        vis[node] = true;
        for(auto it : rooms[node]){
            if(!vis[it]){
                dfs(rooms, vis, it);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n, false);
        dfs(rooms, vis, 0);                      //0 = nodeindex
        for(auto it : vis){                      //if there is single false then ans not possible
            if(it ==  false){
                return false;
            }
        }
        return true;
    }
};
/*
Example 1:
Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.

Example 2:
Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.
*/


//44. NUMBER OF PROVINCES                                       {T.C = O(N^2), S.C = O(N+M)}
/*
Actually We are finding the components(islands) in this , we use simple dfs and take for loop for handling disconnected
components and in dfs Call we checks for index(for(int i = 0 ; i < n ; i++)) not for value(auto it : isConnected[node])
*/
class Solution {
public:
    void dfs(vector<vector<int>>&isConnected, vector<bool>&vis, int node){
        int n = isConnected.size();
        vis[node] = 1;
        for(int i = 0 ; i < n ; i++){                           //checks for index not value(auto it : isConnected[node])
            if(!vis[i] && isConnected[node][i] == 1){           //checks there is direct connnection.
                dfs(isConnected, vis, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int uniqueNodes = 0;
        vector<bool>vis(n, 0);
        for(int i = 0 ; i < n ; i++){                       //for disconnected components
            if(!vis[i]){
                dfs(isConnected, vis, i);                           //0 = nodeIndex
                uniqueNodes++;
            }
        }
        return uniqueNodes;
    }
};
/*
Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
*/


//45. REORDER ROUTES TO MAKE ALL PATHS LEAD TO THE CITY ZERO              {T.C = O(N+M), S.C = O(N+M)}
/*
Initialize a count variable = 0, make and adj list, with pair<value, 1or0(real path or imaginary path)> and vised array
then make dfs call in dfs call simple dfs mark vis[node] = 1 then iterate over adjcency list and if not vis[node / v] ,
if(it.second == 1) real path(means it is real and moving away from 0 so we have to flip) count++ finally return count.
*/
class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>&adj, vector<bool>&vis, int &count, int node){
        vis[node] = 1;
        for(auto it : adj[node]){              //pair<int, int>it    {value, (1 or 0)}
            int v = it.first;
            int check = it.second;             //1 = real, 0 = imaginary
            if(!vis[v]){                       //node's value or node is not visited
                if(check == 1){                //means it is real and moving away from 0 so we have to flip
                    count++;
                }
                dfs(adj, vis, count, v);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        int count = 0;                                //no. of flips
        vector<vector<pair<int, int>>>adj(n);
        vector<bool>vis(n, 0);
        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            adj[u].push_back({v, 1});                 //real path(1)
            adj[v].push_back({u, 0});                 //imaginary path(0)
        }

        dfs(adj, vis, count, 0);                             //0 = starting/node index
        return count;
    }
};
/*
Example 1:
Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 2:
Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 3:
Input: n = 3, connections = [[1,0],[2,0]]
Output: 0
*/


//46. EVALUATE DIVISION                                       {T.C = O(N+M), S.C = O(N+M)}
/*
similar question to graph with with weight or graph traversal
*/
class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string, double>>> &adj, string src, string dst, double &ans, double prod, unordered_set<string>&vis){
        if(vis.find(src) != vis.end()){
            return;
        }
        vis.insert(src);       //mark visited
        if(src == dst){
            ans = prod;
            return;
        }
        for(auto it : adj[src]){
            string v = it.first;
            double val = it.second;
            dfs(adj, v, dst, ans, prod*val, vis);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //similar question to graph with with weight or graph traversal
        int n = equations.size();

        //create adjacency list
        // unordered_map<int, int>mp;
        unordered_map<string, vector<pair<string, double>>>adj;
        for(int i = 0 ; i < n ; i++){
            string u = equations[i][0];       //"a"
            string v = equations[i][1];       //"b"
            double val = values[i];            //2

            adj[u].push_back({v, val});     //a/b
            adj[v].push_back({u, 1.0/val}); //b/a
        }

        vector<double>result;

        for(auto it : queries){
            string src = it[0];
            string dst = it[1];

            double ans = -1.0;
            double prod = 1.0;


            if(adj.find(src) != adj.end()){
                unordered_set<string>vis;                 //vis set created each time 
                dfs(adj, src, dst, ans, prod, vis);
            }
            result.push_back(ans);
        }
        return result;
    }
};
/*
Example 1:
Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0

Example 2:
Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]

Example 3:
Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
*/
