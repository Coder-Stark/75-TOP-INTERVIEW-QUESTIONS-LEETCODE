//BINARY TREE DFS

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

//33. MAXIMUM DEPTH OF BINARY TREE                                         {T.C = O(N), S.C = O(H)}
/*
First check if root == NULL return 0, else recursive call to left and right of subtree and return max(left, right) + 1(current level).
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //base case
        if(!root){
            return 0;
        }

        //LRN
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int ans = max(left, right) + 1;                  //1 = current level (add)

        return ans;
    }
};
/*
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:
Input: root = [1,null,2]
Output: 2
*/


//34. LEAF SIMILAR TREES                                                    {T.C = O(N), S.C = O(N)}
/*
Take 2 vectors for storing leaf nodes, then call inorder , search for leaf node and push in vector then make recursive call of left and right
if v1 == v2 ? true : false.
*/
class Solution {
public:
    void inOrder(TreeNode* root, vector<int>&v){
        //base case
        if(!root){
            return;
        }

        //NLR
        if(!root->left && !root->right){
            v.push_back(root->val);
        }
        inOrder(root->left, v);
        inOrder(root->right, v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1, v2;
        inOrder(root1, v1);
        inOrder(root2, v2);

        return v1 == v2 ? true : false;
    }
};
/*
Example 1:
Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true

Example 2:
Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false
*/


//35. COUNT GOOD NODES IN BINARY TREE                                {T.C = O(N), S.C = O(H)}
/*
Take count variable, make dfs calls(root, root->val, count) , if(root->val > maxVal)  update maxValue and make left
and right calls. after that return count.
*/
class Solution {
public:
    void dfs(TreeNode* root, int maxValue , int &count){
        //base case
        if(!root){
            return;
        }
        if(root->val >= maxValue){
            count++;
            maxValue = root->val;
        }
        dfs(root->left, maxValue, count);
        dfs(root->right, maxValue, count);
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        dfs(root, root->val, count);                    //root->val = max(current)
        return count;
    }
};
/*
Example 1:
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.

Example 2:
Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.

Example 3:
Input: root = [1]
Output: 1
Explanation: Root is considered as good.
*/


//36. PATH SUM III                                          {T.C = O(N^2), S.C = O(1)}
/*
First we have to find the paths from Node , then make recursive call for left and right subtree, for finding count of 
paths we have another function in which if root->val == target sum then count path++ and make recursive call for 
left and right subtree by targetSum-root->val.
*/
class Solution {
public:
    int countPaths(TreeNode* root, long long targetSum){
        int count = 0;
        //base case
        if(!root){
            return 0;
        }

        if(root->val == targetSum){
            count++;
        }
        //recursive call(backtracking)
        count += countPaths(root->left, targetSum - root->val);  //if there's a path with the remaining target sum starting from the left and right subtrees
        count += countPaths(root->right, targetSum - root->val);

        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        //base case
        if(!root){
            return 0;
        }

        int pathSumFromNode = countPaths(root, targetSum);

        //left and right recursive call
        int pathSumFromLeft = pathSum(root->left, targetSum);
        int pathSumFromRight = pathSum(root->right, targetSum);

        return pathSumFromNode + pathSumFromLeft + pathSumFromRight;
    }
};
/*
Example 1:
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.

Example 2:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
*/


//37. LONGEST ZIGZAG PATH IN A BINARY TREE                           {T.C = O(N), S.C = O(H)}
/*
we have to check both the left and rigth subtree for that make two fun call each, then in func update maxi = max(maxi, steps)
if(left) check for 2 condition if left to right (steps+1) or left to left(steps == 1) simialar for right subtree.
*/
class Solution {
public:
    void maxZigZag(TreeNode* root, bool goLeft, int steps, int &maxi){
        //base case
        if(!root){
            return;
        }
        maxi = max(maxi, steps);

        if(goLeft){
            maxZigZag(root->left, false, steps+1, maxi);   //if go left then next step is right with steps++.
            maxZigZag(root->right, true, 1, maxi);         //if go left and still go left then path reinitialize( steps == 1)
        }else{  //(goRight)
            maxZigZag(root->right, true, steps+1, maxi);   //if go right then next step is left(true) with steps++.
            maxZigZag(root->left, false, 1, maxi);         //if go right and still go rigth(false) then path reinitialize(steps == 1).
        }
    }
    int longestZigZag(TreeNode* root) {
        int maxi = 0;
        maxZigZag(root, true, 0, maxi);          //0 = steps    , goLeft (first check for left subtree)
        maxZigZag(root, false, 0, maxi);          //0 = steps   , !goLeft(first check for right subtree)

        return maxi;
    }
};
/*
Example 1:
Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).

Example 2:
Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).

Example 3:
Input: root = [1]
Output: 0
*/


//38. LOWEST COMMON ANCESTOR OF A BINARY TREE                          {T.C = O(N), S.C = O(H)}
/*
Check if one of node is same as root->val then return root (ownself is an ancestor), make left and right call, 
if(both left and right exist return root(lca answer)), else if left exist return left vice versa and if no one exist 
return NULL.
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(!root){
            return NULL;
        }
        if((root->val == p->val) || (root->val == q->val)){      //ownself is an ancestor
            return root;
        }

        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

        if(leftAns && rightAns){                                //both left and right call not null (thats the lca answer)
            return root;
        }
        else if(!leftAns && rightAns){
            return rightAns;
        }
        else if(leftAns && !rightAns){
            return leftAns;
        }
        else{  //!leftAns && !rightAns
            return NULL;
        }
    }
};
/*
Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [1,2], p = 1, q = 2
Output: 1
*/
