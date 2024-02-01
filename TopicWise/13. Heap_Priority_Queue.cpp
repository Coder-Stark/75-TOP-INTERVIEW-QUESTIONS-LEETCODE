//HEAP / PRIORITY QUEUE

#include<bits/stdc++.h>
using namespace std;

//49. KTH LARGEST ELEMENT IN AN ARRAY                                      {T.C = O(N*LOGK), S.C = O(K)}
/*
Using min Heap put first k elements in heap, then for rest of element check if curr element is bigger than minHeap.top()
then pop top element and push curr element to minheap, finally return minHeap.top( k th largest element).
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //creating min heap (kth largest element on top of minHeap others node are greater then k)
        priority_queue<int, vector<int>, greater<int>>minHeap;

        //put first k elements to min heap
        for(int i = 0 ; i < k ; i++){
            minHeap.push(nums[i]);
        }

        //for rest of elements
        for(int i = k ; i < nums.size() ; i++){
            if(nums[i] > minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};
/*
Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
*/


//50. SMALLEST NUMBER IN INIFINITE SET                                   {T.C = O(N), S.C = O(N)}
class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>>minHeap;
    unordered_set<int>st;
    int currSmallest;
    SmallestInfiniteSet() {
        currSmallest = 1;
    }
    
    int popSmallest() {
        int ans;
        if(!minHeap.empty()){
            ans = minHeap.top();
            minHeap.pop();
            st.erase(ans);
        }else{
            ans = currSmallest;
            currSmallest++;
        }
        return ans;
    }
    
    void addBack(int num) {
        if(num >= currSmallest || st.find(num) != st.end()){
            return;
        }
        minHeap.push(num);
        st.insert(num);
    }
};
/*
Example 1:

Input
["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"]
[[], [2], [], [], [], [1], [], [], []]
Output
[null, null, 1, 2, 3, null, 1, 4, 5]

Explanation
SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
smallestInfiniteSet.addBack(2);    // 2 is already in the set, so no change is made.
smallestInfiniteSet.popSmallest(); // return 1, since 1 is the smallest number, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 2, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 3, and remove it from the set.
smallestInfiniteSet.addBack(1);    // 1 is added back to the set.
smallestInfiniteSet.popSmallest(); // return 1, since 1 was added back to the set and
                                   // is the smallest number, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 4, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 5, and remove it from the set.
*/


//51. MAXIMUM SUBSEQUENCE SCORE                                 {T.C = O(N*LOGN), S.C = O(N)}
/*
First store the vectors in single vector<pair> then sort in decreasing order on the basis of second vector, then make
minHeap and variable kSum(store first k elment sum). take maxi (final ans variable) = kSum * v[k-1].second(mini element)
after that traverse from k to n update kSum = v[i].first-minHeap.top() {add new element and remove top element(minimum)}
in ans = max(ans, kSum*v[i].second), finally return ans.
*/
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();                    //size is same for both nums1 and nums2
        vector<pair<int, int>>v(n);                 //{nums1[i], nums2[i]}
        for(int i = 0 ; i < n ; i++){
            v.push_back({nums1[i], nums2[i]});
        }

        auto lambda = [&](auto &pair1, auto &pair2){
            return pair1.second > pair2.second;
        };
        sort(v.begin(), v.end(), lambda);       //lambda = decreasing sort on the basis of second element in pair

        priority_queue<int, vector<int>, greater<int>>minHeap;
        long long kSum = 0;
        for(int i = 0 ; i < k ; i++){
            kSum += v[i].first;
            minHeap.push(v[i].first);
        }

        long long maxiAns = kSum * v[k-1].second;    //sum (nums1 range) * max(nums2 range which is k-1 th after sorting)

        for(int i = k ; i < n ; i++){
            kSum += v[i].first - minHeap.top();        //add next element and remove kth mini element
            minHeap.pop();
            minHeap.push(v[i].first);
            maxiAns = max(maxiAns, kSum * v[i].second);
        }

        return maxiAns;
    }
};
/*
Example 1:
Input: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
Output: 12
Explanation: 
The four possible subsequence scores are:
- We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
- We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6. 
- We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12. 
- We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
Therefore, we return the max score, which is 12.

Example 2:
Input: nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
Output: 30
Explanation: 
Choosing index 2 is optimal: nums1[2] * nums2[2] = 3 * 10 = 30 is the maximum possible score.
*/


//52. TOTAL COST TO HIRE K WORKERS                                 {T.C = O(K*LOGN), S.C = O(N)}
/*
Using 2 minHeap first for 1st k costs another for last k costs , while count < k , push costs in minHeap < candidates 
and if both pq is not empty then compare there top element and push the lowest cost in ans , finally return ans.
*/
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        int n = costs.size();
        int count = 0;
        priority_queue<int, vector<int>, greater<int>>minHeapFirst, minHeapLast;

        int i = 0;
        int j = n-1;
        while(count < k){
            while(minHeapFirst.size() < candidates && i <= j){    //push element in pq1 and pq2
                minHeapFirst.push(costs[i++]);
            }
            while(minHeapLast.size() < candidates && j >= i){
                minHeapLast.push(costs[j--]);
            }

            int cost1 = INT_MAX;
            int cost2 = INT_MAX;
            if(minHeapFirst.size() > 0){
                cost1 = minHeapFirst.top();
            }
            if(minHeapLast.size() > 0){
                cost2 = minHeapLast.top();
            }

            if(cost1 <= cost2){                                //add minimum cost to ans
                ans += cost1;
                minHeapFirst.pop();
            }else{
                ans += cost2;
                minHeapLast.pop();
            }
            count++;
        }
        return ans;
    }
};
/*
Example 1:
Input: costs = [17,12,10,2,7,2,11,20,8], k = 3, candidates = 4
Output: 11
Explanation: We hire 3 workers in total. The total cost is initially 0.
- In the first hiring round we choose the worker from [17,12,10,2,7,2,11,20,8]. The lowest cost is 2, and we break the tie by the smallest index, which is 3. The total cost = 0 + 2 = 2.
- In the second hiring round we choose the worker from [17,12,10,7,2,11,20,8]. The lowest cost is 2 (index 4). The total cost = 2 + 2 = 4.
- In the third hiring round we choose the worker from [17,12,10,7,11,20,8]. The lowest cost is 7 (index 3). The total cost = 4 + 7 = 11. Notice that the worker with index 3 was common in the first and last four workers.
The total hiring cost is 11.

Example 2:
Input: costs = [1,2,4,1], k = 3, candidates = 3
Output: 4
Explanation: We hire 3 workers in total. The total cost is initially 0.
- In the first hiring round we choose the worker from [1,2,4,1]. The lowest cost is 1, and we break the tie by the smallest index, which is 0. The total cost = 0 + 1 = 1. Notice that workers with index 1 and 2 are common in the first and last 3 workers.
- In the second hiring round we choose the worker from [2,4,1]. The lowest cost is 1 (index 2). The total cost = 1 + 1 = 2.
- In the third hiring round there are less than three candidates. We choose the worker from the remaining workers [2,4]. The lowest cost is 2 (index 0). The total cost = 2 + 2 = 4.
The total hiring cost is 4.
*/
