//DYNAMIC PROGRAMMING(DP)-1D

#include<bits/stdc++.h>
using namespace std;

//59. NTH TRIBONACCI NUMBER                                         {T.C = O(N), S.C = O(N)}
/*
Bottom up(initial index = n) approach in TOP DOWN (DP) first check for base cases , then follow standardise dp steps
and store(dp[i] = solve(i-3)+solve(i-2)+solve(i-1)).
*/
class Solution {
public:
    int solve(int n, vector<int>&dp, int i){
        //base case
        if(i == 0){
            return 0;
        }
        if(i == 1 || i == 2){
            return 1;
        }
        //step3 if ans already present return it
        if(dp[i] != -1){
            return dp[i];
        }

        //step2 store ans in dp
        dp[i] = solve(n, dp, i-3)+solve(n, dp, i-2) + solve(n, dp, i-1);
        return dp[i];
    }
    int tribonacci(int n) {
        if(n == 0){
            return 0;
        }
        vector<int>dp(n+1, -1);
        int ans = solve(n, dp, n);                         //n = initial index = n
        return ans;
    }
};
/*
Example 1:
Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

Example 2:
Input: n = 25
Output: 1389537
*/


//60. MIN COST CLIMBING STAIRS                                       {T.C = O(N), S.C = O(N)}
/*
Use dp and take min(n-1 and n-2) , in solveMem handle base case if(n == 0) return cost[0] similarly for 1 , store ans in
dp = cost[i] + min(solveMem(n-1), solveMem(n-2))
*/
class Solution {
public:
    int solveMem(vector<int>&cost , int n , vector<int>&dp){
        //base case
        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return cost[1];
        }

        //step-3 if answer already present retur it.
        if(dp[n] != -1){
            return dp[n];
        }

        //step2 store ans in dp
        dp[n] = cost[n] + min(solveMem(cost, n-1, dp), solveMem(cost, n-2, dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        //step-1 create dp array
        vector<int>dp(n+1, -1);
        int ans = min(solveMem(cost, n-1, dp), solveMem(cost, n-2, dp));
        return ans;
    }
};
/*
Example 1:
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
*/


//61. HOUSE ROBBER                                                    {T.C = O(N), S.C = O(N)}
/*
Use simple dp and use concept of take(incl) or nontake(excl) , for include = nums[n] + solveMem(nums, n-2, dp) {adjacnt cant include}
for exclude = 0 + solveMem(n-1, dp), after that return max of it.
*/
class Solution {
public:
    int solveMem(vector<int>&nums,int n, vector<int>&dp){
        //base case
        if(n < 0){
            return 0;
        }

        //step3 if ans already present return it
        if(dp[n] != -1){
            return dp[n];
        }

        //step2 recursive call
        int incl = nums[n] + solveMem(nums,n-2, dp);         //adjacent element cant include
        int excl = 0 + solveMem(nums, n-1, dp);

        dp[n] = max(incl, excl);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        //step1 create a dp vector
        vector<int>dp(n+1, -1);
        return solveMem(nums, n-1, dp);                      //traverse from last element (n-1)
    }
};
/*
Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
*/


//62. DOMINO AND TROMINO TILING                                           {T.C = O(N), S.C = O(N)}
/*
We have to use formula ans = 2*(n-1) + (n-3) and store ans n dp , finally return it.
*/
class Solution {
public:
    int solveMem(int n, vector<int>&dp){
        int mod = 1e9+7;
        //base case
        if(n == 1 || n == 2){
            return n;
        }
        if(n == 3){
            return 5;
        }

        //step3 if ans already present return it
        if(dp[n] != -1){
            return dp[n];
        }

        //step2 store ans in dp
        dp[n] = (2*solveMem(n-1, dp)%mod + solveMem(n-3, dp)%mod ) % mod;    //formula = 2*(n-1) + (n-3)

        return dp[n];
    }
    int numTilings(int n) {
        //step1 create a dp vector
        vector<int>dp(n+1, -1);
        return solveMem(n, dp);                         //n = traverse from last
    }
};
/*
Example 1:
Input: n = 3
Output: 5
Explanation: The five different ways are show above.

Example 2:
Input: n = 1
Output: 1
*/
