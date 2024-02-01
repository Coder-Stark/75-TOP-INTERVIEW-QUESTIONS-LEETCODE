//BINARY SEARCH TREE

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

//41. SEARCH IN A BINARY SEARCH TREE                                      {T.C = O(N), S.C = O(H)}
/*
Simply check base case if root not exist return null if (root->val == val) return root(return corresponding tree).
if(root->val > val) recursion right else left.
*/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root){
            return NULL;
        }
        if(root->val == val){
            return root;
        }

        if(root->val > val){
            return searchBST(root->left, val);
        }else{
            return searchBST(root->right, val);
        }
    }
};
/*
Example 1:
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]

Example 2:
Input: root 
Output : []
*/


//42. DELETE NODE IN A BST                                            {T.C = O(N), S.C = O(H)}
/*
Before deleting the node we have to chech number or child does deleting node have, if zero child simply delete and return 
NULL, if 1 child (left or right) return non deleted (root->left) or root->right, if 2 child then we have to check minimum
value (which find in right side of BST), if(root->val > key) left call else right call.
*/
class Solution {
public:
    TreeNode* minValue(TreeNode* root){
        TreeNode* temp = root;
        while(temp->left){
            temp = temp->left;
        }
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        //base case
        if(!root){
            return NULL;
        }

        if(root->val == key){
            //0 child /leaf node delete
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }

            //1 child either left or right node delete
            if(root->left && !root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            if(!root->left && root->right){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            //2 child node delete
            TreeNode* temp = minValue(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
            return root;
        }
        else if(root->val > key){           //val present in left subtree
            root->left = deleteNode(root->left, key);
            return root;
        }else{ //root->val < key            //val present in right subtree
            root->right = deleteNode(root->right,  key);
            return root;
        }
        return root;
    }
};
/*
Example 1:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.

Example 3:
Input: root = [], key = 0
Output: []
*/
