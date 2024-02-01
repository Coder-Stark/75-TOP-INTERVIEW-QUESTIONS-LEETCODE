//HASHMAP AND SETS

#include<bits/stdc++.h>
using namespace std;

//20. FIND THE DIFFERENCE OF TWO ARRAYS                                   {T.C = O(N), S.C = O(N)}
/*
Take 2 vectors and 2 sets , push given vector's in set then iterate the set and push in vector the non match element same to next set
finally return {ans1, ans2}.
*/
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans1;
        vector<int>ans2;
        unordered_set<int>st1(nums1.begin(), nums1.end());        //insert vector in a set
        unordered_set<int>st2(nums2.begin(), nums2.end());

        for(auto it : st1){                      //search 1st set's element in 2nd sets then push element and viceversa
            if(st2.count(it) == 0){        //or if (st2.find(it) == st2.end())
                ans1.push_back(it);
            }
        }
        for(auto it : st2){
            if(st1.count(it) == 0){
                ans2.push_back(it);
            }
        }
        
        return {ans1, ans2};
    }
};
/*
Example 1:
Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].

Example 2:
Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
*/


//21. UNIQUE NUMBER OF OCCURENCES                                    {T.C = O(N), S.C = O(N)}
/*
Using Map (number, count) & set (unique count) , first store arr in map then , iterate map and check if count is unique
after inserting count in set.
*/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int ,int>mp;             //store <number, count>
        unordered_set<int>unq;                 //store<unique-count>
        for(auto it : arr){                    //insert arr element in mp
            mp[it]++;
        }
        for(auto it : mp){
            // if(unq.count(it.second) > 0){        //or
            if(unq.find(it.second) != unq.end()){        //check for unique count
                return false;
            }
            unq.insert(it.second);
        }
        return true;
    }
};
/*
Example 1:
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

Example 2:
Input: arr = [1,2]
Output: false

Example 3:
Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
*/


//22. DETERMINE IF TWO STRINGS ARE CLOSE                                          {T.C = O(N*LOGN), S.C = O(N)}
/*
Take 2 vectors and 2 map ,store word1 and word2 in a map, now iterate 1st map and check if all char is matched with mp2 then push all mp1 and mp2
char in vectors then sort the vector and check v1 == v2.
*/
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>v1,v2;
        unordered_map<char, int>mp1;
        for(auto it : word1){
            mp1[it]++;
        }
        unordered_map<char, int>mp2;
        for(auto it : word2){
            mp2[it]++;
        }

        for(auto it : mp1){
            if(mp2.find(it.first) == mp2.end()){           //mp1 char not found in mp2
                return false;
            }
            v1.push_back(mp1[it.first]);
            v2.push_back(mp2[it.first]);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        return v1 == v2;
    }
};
/*
Example 1:
Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"

Example 2:
Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.

Example 3:
Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"
*/


//23. EQUAL ROW AND COLUMN PAIRS                                             {T.C = O(N^2), S.C = O(N)}
/*
First convert row vector element into a string then , mp<string, count> , now initialize count = 0 check particular col with matching row
then increase count.
*/
class Solution {
public: 
    string mpStr(vector<int>&n){               //convert vector of number to string
        string str = "";
        for(auto it : n){
            str += to_string(it);
            str += "#";                        //for creating uniquness of particular string
        }
        return str;
    }
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string, int>mp;

        for(auto it : grid){                   //inserting <string(row), count>
            mp[mpStr(it)]++;
        }

        int count = 0;
        for(int j = 0 ; j < n ; j++){                   //now check for particluar col with row
            string finder = "";
            for(int i = 0 ; i < n ; i++){
                finder += to_string(grid[i][j]);
                finder += "#";
            }        
            count += mp[finder];
        }
        return count;               
    }
};
/*
Example 1:
Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]

Example 2:
Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]
*/
