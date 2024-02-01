//INTERVALS

#include<bits/stdc++.h>
using namespace std;

//72. NON-OVERLAPPING INTERVALS                                        {T.C = O(N*LOGN), S.C = O(1)}
/*
First sort the intervals on the basis of upper bound, then take count(initial 1) and end (starting interval), traverse the 
intervals if curr is greater then end then update end = intervals and count++(count of unique intervals {not matched})
return n-count(gives matched or count of removal intervals).
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        auto lambda = [&](auto &a, auto &b){                 
            return a[1] < b[1];
        };
        sort(intervals.begin(), intervals.end(), lambda);       //sort on the basis of upper bound
        
        int count = 1;                                          //initial count should 1
        int end = intervals[0][1];
        for(int i = 1 ; i < n; i++){
            if(intervals[i][0] >= end){
                end = intervals[i][1];
                count++;
            }
        }
        return n-count;                                        //for count require removable element                   
    }
};
/*
Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Example 3:
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
*/


//73. MINIMUM NUMBER OF ARROWS TO BURST BALLOONS                    {T.C = O(N*LOGN), S.C = O(1)}
/*
First sort the points on the basis of upper bound, then take count of arrow(initial 1) and end (starting interval), traverse the 
intervals if curr is greater then end then update end = points and count++(count of unique intervals {not matched})
return count of arrow.
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //base case
        if(points.size() == 0){
            return 0;
        }

        auto lambda = [&](auto &a, auto &b){
            return a[1] < b[1];
        };
        sort(points.begin(), points.end(), lambda);     //sort on the basis of upper bound of each interval

        int arrow = 1;                                   //1 arrow always required to burst 1 or > ballon
        int end = points[0][1];                          //take 1st interval

        for(int i = 1 ; i < points.size() ; i++){
            if(points[i][0] > end){                     //lower bound of interval  > end
                arrow++;
                end = points[i][1];
            }
        }
        return arrow;
    }
};
/*
Example 1:
Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].

Example 2:
Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.

Example 3:
Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
*/
