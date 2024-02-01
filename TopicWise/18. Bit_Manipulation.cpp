//BIT MANIPULATION

#include<bits/stdc++.h>
using namespace std;

//67. COUNT BITS (counting 1's in a binary representation of any number)           {T.C = O(N*LOGN), S.C = O(N)}
//USING STL
/*
simply take vector of (n+1) length then take a for loop from 0 to <= n , put ans[i] = __builtinpopcount(i) gives count of 1.
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i = 0 ; i <= n ; i++){
            ans[i] = __builtin_popcount(i);             //builtin_popcount gives count of 1 bits (LOGN { a number have logn bits})
        }
        return ans;
    }
};

//INTUTIVE APPROACH                                             {T.C = O(N), S.C = O(N)}
/*
Take vector of (n+1) size , firstly check for base case if n == 0 return ans, then initialize ans[0] = 0 , apply for loop 1
to <= n now, if it is odd */
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        //base case
        if(n == 0){
            return ans;
        }
        ans[0] = 0;
        for(int i = 1 ; i <= n ; i++){
            if(i%2 != 0){                                 //odd
                ans[i] = ans[i/2] + 1;
            }else{                                        //even
                ans[i] = ans[i/2];
            }
        }
        return ans;
    }
};
/*
Example 1:
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Example 2:
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
*/


//68. SINGLE NUMBER (ALL TWICE EXCEPT ONE(ANS))                                                {T.C = O(N), S.C = O(1)}
/*
Just simple take xor of all elements all same element cancel out and left is your ans.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {             //xor = different element != 0 else 0 
        int xorAns = 0;
        for(int i = 0 ; i < nums.size(); i++){
            xorAns = xorAns^nums[i];
        }
        return xorAns;
    }
};
/*
Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1
*/


//69. MINIMUM FLIPS TO MAKE (A) OR (B) EQUAL TO (C)
//BRUTE FORCE APPROACH(INTUTIVE)                                            {T.C = O(N), S.C = O(1)}
/*
Check the bits one by one whether they need to be flipped. basically we have to check for all the numbers untill all will 0
and check for right most bit of c if it is 1 then flips++ (one of a or b should 0)  else it is 0, then (both should 0) and
make right shift of all a, b, c , finally return flips.
*/
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while( a != 0 || b != 0 || c != 0){        //break only a,b,c=0,0,0
            if((c & 1) == 1){                      //for c's right most bit 1 (one of  a or b should 0)
                if((a & 1) == 0 && (b & 1) == 0){
                    flips++;
                }
            }else if((c & 1) == 0){                //for c's right most bit 0 (both should be 0)
                if((a & 1) == 1){
                    flips++;
                }
                if((b & 1) == 1){
                    flips++;
                }
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return flips;
    }
};

//USING STL                                            {T.C = O(N), S.C = O(1)}
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int temp = (a|b)^c;                //flips
        int extra = ((a&b) & temp);          //handle extra case
        return __builtin_popcount(temp) + __builtin_popcount(extra);   //gives count of 1 bits(ans)
    }
};
/*
Example 1:
Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)

Example 2:
Input: a = 4, b = 2, c = 7
Output: 1

Example 3:
Input: a = 1, b = 2, c = 3
Output: 0
*/
