//BACKTRACKING

#include<bits/stdc++.h>
using namespace std;

//57. LETTER COMBINATIONS OF A PHONE NUMBER                             {T.C = O(EXP), S.C = O(N)}
/*
Use brute force recursive solution and apply backtracking to it. first store all the strings of keypad in a map, then
in solve function if index >= digits.length() . ans.push_back(output) , extract number (digits[index]-'0') now traverse value
(mapping[number]) push value[i] i output then make recursive call and pop back(backtrack).
*/
class Solution {
private : 
    void solve(string digits ,vector<string> &ans ,string output ,string mapping[], int index){
        //base case
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';      //char to number
        string value = mapping[number];

        for(int i = 0 ; i <  value.length() ; i++){
            output.push_back(value[i]);
            solve(digits ,ans, output, mapping, index+1);
            output.pop_back();                //to backtrack and explore other combos
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output = "";

        if(digits.length() == 0){
            return ans;
        }

        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};   //0 to 9 (10)
        
        solve(digits ,ans ,output ,mapping, 0);         //0 = starting index
        return ans;
    }
};
/*
Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]
*/


//58. COMBINATION SUM III                                       {T.C = O(EXP), S.C = O(N^2)}
/*
Take combo(combination) vector and ans(vector of vector) and make solve call(recursion) with 1 = idx and 0 = sum , in solve
if(k == 0 && sum == n) ans.push_back combo, take a for loop from currindex to 9 and push curr i and make recursive call
and pop back for backtracking.
*/
class Solution {
public:
    void solve(int k ,int n, vector<int>&combo, vector<vector<int>>&ans, int idx, int sum){
        //base case
        if(k == 0 && sum == n){
            ans.push_back(combo);
            return;
        }
        if(sum > n){
            return;
        }
        for(int i = idx ; i <= 9 ; i++){                    //i = idx (unique number required)
            combo.push_back(i);
            solve(k-1, n, combo, ans, i+1, sum+i);
            combo.pop_back();                                  //backtracking
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {     //n = required sum
        vector<int>combo;
        vector<vector<int>>ans;
        solve(k, n, combo, ans, 1, 0);                 //1 = index(1 to 9) , 0 = sum
        return ans;
    }
};
/*
Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.

Example 2:
Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.

Example 3:
Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
*/
