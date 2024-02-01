//DYNAMIC PROGRAMMING(DP)-MULTIDIMENSIONAL

#include<bits/stdc++.h>
using namespace std;

//63. UNIQUE PATHS                                                 {T.C = O(N*M), S.C = O(N*M)}
/*
Use simple recursion + memoization function code and keep left and down value and finally stores its sum in ans.
*/
class Solution {
public:
    int solveMem(int n, int m, vector<vector<int>>&dp, int i, int j){
        //base case
        if(i == n-1 && j == m-1){
            return 1;
        }
        //boundary case
        if(i >= n || j >= m){
            return 0;
        }
        
        //step3 if ans already present retur it
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int down = solveMem(n, m, dp, i+1, j);
        int right = solveMem(n, m, dp, i, j+1);

        //step2 store ans in dp
        dp[i][j] = down + right;
        return dp[i][j];
    }
    int uniquePaths(int n, int m) {
        //step1 create a dp vector
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solveMem(n, m, dp, 0, 0);              //initial index = 0, 0 , 0 = counts(ways)
    }
};
/*
Example 1:
Input: m = 3, n = 7
Output: 28

Example 2:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/


//64. LONGEST COMMON SUBSEQUENCE                                      {T.C = O(N*M), S.C = O(N*M)}
/*
Use simple recursion + memoization function code and if char match of both string then (1{count} + call) else take 
max of skipped element and finally return count.
*/
class Solution {
public:
    int solveMem(string &a, string &b, vector<vector<int>>&dp, int i , int j){
        //base case
        if(i == a.size() || j == b.size()){
            return 0;
        }

        //step3 if answer already present return it
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int count = 0;
        if(a[i] == b[j]){
            count = 1 + solveMem(a, b, dp, i+1, j+1);
        }else{  //a[i] != b[j]
            count = max(solveMem(a, b, dp, i+1, j), solveMem(a, b, dp, i, j+1));
        }

        //step2 store ans in dp
        dp[i][j] = count;
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solveMem(text1, text2, dp, 0, 0);                     //0, 0 = starting index of both strings
    }
};
/*
Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
*/


//65a. BEST TIME TO BUY AND SELL STOCK WITH COOLDOWN                     {T.C = O(N), S.C = O(N)}
/*
Use simple recursion + memoization function code and take bool buy(true) variable and initial index(0), in solveMem func
if(buy == true) then we have two choice buy(mark next buy{false} and i+1) or skip(mark as it is true and i+1) similarly for
if(buy != false(sell)) then we have 2 choice sell(mark next buy true and i+2{cooldown period}) or skip(mark next buy false and i+1) store
max value of both and return it. 
*/
class Solution {
public:
    int solveMem(vector<int>&prices, vector<vector<int>>&dp, bool buy, int i){
        //base case
        if(i >= prices.size()){
            return 0;
        }

        //step3 if ans already present return it
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int ans = 0;
        if(buy){
            int buyKaro = -prices[i] + solveMem(prices, dp, false, i+1);    //SP-CP = PROFIT {-CP + SP = PROFIT}
            int skipKaro = 0 + solveMem(prices, dp, true, i+1);
            ans = max(buyKaro, skipKaro);
        }else{  //sell
            int sellKaro = +prices[i] + solveMem(prices, dp, true, i+2);       //cooldown period (i+2)
            int skipKaro = 0 + solveMem(prices, dp, false, i+1);
            ans = max(sellKaro, skipKaro);
        }

        //step2 store ans in dp
        dp[i][buy] = ans;
        return dp[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        //step1 create a dp vector
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return solveMem(prices, dp, true, 0);               //0 = initial index
    }
};
/*
Example 1:
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:
Input: prices = [1]
Output: 0
*/


//65b. BEST TIME TO BUY AND SELL STOCK WITH TRANSACTION FEE                {T.C = O(N), S.C = O(N)}
/*
Use simple recursion + memoization function code and take bool buy(true) variable and initial index(0), in solveMem func
if(buy == true) then we have two choice buy(mark next buy{false} and i+1) or skip(mark as it is true and i+1) similarly for
if(buy != false(sell)) then we have 2 choice sell(mark next buy true and i+1) - fee(reduces after selling) 
or skip(mark next buy false and i+1) store max value of both and return it. 
*/
class Solution {
public:
    int solveMem(vector<int>&prices, int fee, vector<vector<int>>&dp, bool buy, int i){
        //base case
        if(i >= prices.size()){
            return 0;
        }

        //step3 if ans already present return it
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int ans = 0;
        if(buy){
            int buyKaro = - prices[i] + solveMem(prices, fee, dp, false, i+1);    //after buying totalPrice will reduce
            int skipKaro = 0 + solveMem(prices, fee, dp, true, i+1);
            ans = max(buyKaro, skipKaro);
        }else{   //sell
            int sellKaro = +prices[i] + solveMem(prices, fee, dp, true, i+1) - fee; //after selling totalPrice will increase with pay(minus) small fee
            int skipKaro = 0 + solveMem(prices, fee, dp, false, i+1);
            ans = max(sellKaro, skipKaro);
        }

        //step2 store ans in dp
        return dp[i][buy] = ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        //step1 create a dp vector
        vector<vector<int>>dp(n+1, vector<int>(2, -1));    //{fee, buy}  // col(2) is always fixed
        return solveMem(prices, fee, dp, true, 0);             //true = buy(first), 0 = initial index
    }
};
/*
Example 1:
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Example 2:
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
*/


//66. EDIT DISTANCE                                                      {T.C = O(N*M), S.C = O(N*M)}
/*
First check base cases then if word1[i] == word[j] then move both pointers else perform insert(i, j+1{add}),
delete(i+1{skip}, j), replace operations(i+1, j+1).
*/
class Solution {
public:
    int solveMem(string &word1, string &word2, vector<vector<int>>& dp, int i, int j) {
        int m = word1.length();
        int n = word2.length();

        // Base case
        if (i == m) {                      //string1 is fully traversed now rest(n-j length is ans)
            return n - j;
        }
        if (j == n) {                      //string2 is fully traversed now rest(m-i length is ans)
            return m - i;
        }

        //step3 if answer already present, return it
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int mini = INT_MAX;
        // Recursive call
        if (word1[i] == word2[j]) {
            mini = solveMem(word1, word2, dp, i + 1, j + 1);
        } else { // Min of insert, delete, replace
            int insertOp = solveMem(word1, word2, dp, i, j + 1);   //It increments the index j of word2 while keeping the index i of word1 the same
            int deleteOp = solveMem(word1, word2, dp, i + 1, j);   //It increments the index i of word1 while keeping the index j of word2 the same
            int replacOp = solveMem(word1, word2, dp, i + 1, j + 1);//It increments the index i of word1 as well as index j of word2

            mini = 1 + min({insertOp, deleteOp, replacOp});         //1 (current operation + other)         
        }

        //step2 store ans in dp
        return dp[i][j] = mini;
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        //step1 create a dp vector
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solveMem(word1, word2, dp, 0, 0);                  //0, 0 = starting index of both strings
    }
};
/*
Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/
