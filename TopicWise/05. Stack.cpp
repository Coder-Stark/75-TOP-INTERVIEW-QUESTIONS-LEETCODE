//STACK 

#include<bits/stdc++.h>
using namespace std;

//24. REMOVING STARS FROM A STRING                                     {T.C = O(N), S.C = O(N)}
/*
Take a stack and push the element != * otherwise pop (!stk.empty) after that pop element from stack and push to string after that reverse the
string(stack is LIFO) then finally return ans string.
*/
class Solution {
public:
    string removeStars(string s) {
        string ans;
        stack<char>stk;

        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '*' && !stk.empty()){
                stk.pop();
            }else{
                stk.push(s[i]);
            }
        }
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());           //Stack Using LIFO (reverse printing)
        return ans;
    }
};
/*
Example 1:
Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".

Example 2:
Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.
*/


//25. ASTEROID COLLISION                                           {T.C = O(N), S.C = O(N)}
/*
Check the condition (collision case) if stack not empty, it < 0 and st.top > 0 find sum of each iteration, check if 
sum > 0{Stack's asteroid is big, reinitialse it = 0 }, sum < 0 {incoming asteroid is big(destroys other) pop up the elemnt}
sum == 0 both pop element and reinitialize it , and push element into stack after that return stack's popped elemnt in
vector and reverse answer printed.
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>stk;

        for(auto it : asteroids){
            while(!stk.empty() && it < 0 && stk.top() > 0){       //collision case (only one case -><-)
                int sum = it + stk.top();
                if(sum < 0){               //incoming asteroid is big
                    stk.pop();
                }else if(sum > 0){         //stack's asteroid is big
                    it = 0;
                }else{ //sum == 0
                    stk.pop();
                    it = 0;
                }
            }
            if(it != 0){
                stk.push(it);
            }
        }

        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse (ans.begin(), ans.end());

        return ans;
    }
};
/*
Example 1:
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Example 2:
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

Example 3:
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
*/


//26. DECODE STRINGS                                                 {T.C = O(N), S.C = O(N)}
/*
Use two stacks(string, int), 2 var(string, int) iterate string , handle cases opening bracket= push curr string and 
curr number in respective stacks, closing brackets = pops the previous string and number from their respective stacks
isdigit() = currNum = currNum * 10 + (it - '0'), else add rest of char and return currStr.
*/
class Solution {
public:
    string decodeString(string s) {
        string currStr="";
        int currNum = 0;
        stack<string>strStk;
        stack<int>numStk;

        for(auto it : s){
            if(it == '['){
                strStk.push(currStr);
                numStk.push(currNum);
                currStr = "";              //reset after pushing
                currNum = 0;               //reset after pushing
            }else if(it == ']'){           //pops the previous string and number from their respective stacks
                int num = numStk.top();    
                numStk.pop();
                string outPut = "";
                while(num--){
                    outPut += currStr;
                }

                string prevStr = strStk.top();
                strStk.pop();
                currStr = prevStr + outPut;
            }else if(isdigit(it)){
                currNum = currNum * 10 + (it - '0');
            }else{
                currStr += it;
            }
        }
        return currStr;
    }
};
/*
Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
*/
