//BINARY TREE BFS

#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//39. BINARY TREE RIGHT SIDE VIEW                                          {T.C = O(N), S.C = O(N)}
/*
Take vector and call solve function in which NRL(Right view) {NLR(Left View)} if(level == ans.size(){size reached change level}), push root->val
in vector and level++.
*/
class Solution {
public:
    void solve(TreeNode* root, vector<int>&ans, int level){
        //base case
        if(!root){
            return;
        }

        //NRL        (for right view)  //for left view (NLR)
        if(level == ans.size()){                   //if level reach ends then change the level and push root->data in vector
            ans.push_back(root->val);           
        }
        solve(root->right, ans, level+1);
        solve(root->left, ans, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        solve(root, ans, 0);                      //0 == initial level
        return ans;
    }
};
/*
Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:
Input: root = [1,null,3]
Output: [1,3]

Example 3:
Input: root = []
Output: []
*/


//40. MAXIMUM LEVEL SUM OF A BINARY TREE                              {T.C = O(N), S.C = O(N)}
/*
Take resultLvl, currLvl, maxiSum and queue(bfs) push root in queue, then bfs(while(!q.empty())) traverse in queue
and update sum also check for left and right subtree after that currLvl++ and update result lvl.
*/
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int resultLvl = 0;
        int currLvl = 1;
        int maxiSum = INT_MIN;
        queue<TreeNode*>q;                             //bfs
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            int sum = 0;

            while(n--){                              //traverse in queue(stores level's nodes)
                TreeNode* frontNode = q.front();
                q.pop();
                sum += frontNode->val;

                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }
            if(sum > maxiSum){
                maxiSum = sum;
                resultLvl = currLvl;
            }
       
            currLvl++;
        }
        return resultLvl;
    }
};
/*
Example 1:
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.

Example 2:
Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2
*/
