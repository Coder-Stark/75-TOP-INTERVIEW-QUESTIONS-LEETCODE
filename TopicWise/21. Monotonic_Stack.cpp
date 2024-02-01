//MONOTONIC STACK(INCREASING STACK)

#include<bits/stdc++.h>
using namespace std;

//74. DAILY TEMPRATURES                                          {T.C = O(N*LOGN), S.C = O(N)}
/*
Take an stack, traverse the vector(tempratures) , while(st.empty() && element > element[stk.top{index}]) , prevIdx = st.top()
put ans[prevIdx] = i-prevIdx, then push i in stack finally return ans.
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n);
        int count = 0;
        stack<int>stk;
        for(int i = 0 ; i < n ; i++){
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()]){
                int prevIdx = stk.top();
                stk.pop();
                ans[prevIdx] = i - prevIdx;
            }
            stk.push(i);
        }
        return ans;
    }
};
/*
Example 1:
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:
Input: temperatures = [30,60,90]
Output: [1,1,0]
*/


//75. ONLINE STOCK SPAN                                        {T.C = O(N), S.C = O(N)}
/*
Take an stack(pair{price, span}) initialize span 1 (always) then traverse stack untill the !st.empty() && top <= price
span += top.second(curr span) , push {price , span } in stack and finally return span.
*/
class StockSpanner {
public:
    stack<pair<int, int>>stk;                          //{price, span}
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;                   //current span(minimum value before curr) is 1 
        while(!stk.empty() && stk.top().first <= price){
            span += stk.top().second;
            stk.pop();
        }
        stk.push({price, span});
        return span;
    }
};
/*
Example 1:
Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6
*/


/*------------------------------------------------== THE END ---------------------------------------------------------*/