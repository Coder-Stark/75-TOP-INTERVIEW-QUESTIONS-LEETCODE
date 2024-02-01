//BINARY SEARCH

#include<bits/stdc++.h>
using namespace std;

//53. GUESS NUMBER HIGHER OR LOWER                                  {T.C = O(LOGN), S.C = O(1)}
/*
First there is Pre defined guess function with output(0, 1, -1) , use binary search and find the location of guess number
and update accordingly finally return pick.
*/

//for remove error(line)
int guess(int a);
//--------------------
class Solution {
public:
    int guessNumber(int n) {
        int pick;
        int start = 1;                          //range [1, n]
        int end = n;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(guess(mid) == 0){
                pick = mid;
                break;
            }else if(guess(mid) == 1){
                start = mid+1;
            }else{ //guess(mid) == -1
                end = mid-1;
            }
        }
        return pick;
    }
};
/*
Example 1:
Input: n = 10, pick = 6
Output: 6

Example 2:
Input: n = 1, pick = 1
Output: 1

Example 3:
Input: n = 2, pick = 1
Output: 1
*/


//54. SUCCESSFUL PAIRS OF SPELLS AND POTIONS
//BRUTE FORCE                                                 {T.C = O(N*M), S.C = O(1)} 
/*
Use 2 loops first loop traverse on spells another on potions in which store products of both vector and if the product 
is equal or greater then success then increase the pairCount after that push paircount in ans and return ans.
*/
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        for(int i = 0 ; i < spells.size() ; i++){
            int pairCount = 0;
            for(int j = 0 ; j < potions.size() ; j++){
                // long long product = (long long)(spells[i]) * (long long)(potions[j]);
                int product = spells[i]*potions[j];
                if(product >= success){
                    pairCount++;
                }
            }
            ans.push_back(pairCount);
        }
        return ans;
    }
};

//OPTIMIZED APPROACH (BINARY SEARCH)                                           {T.C = O(N+M)LOGN, S.C = O(N)}
/*
First sort the potions vector then iteratre in spells and apply binary search by taking pointer on start(0) and end(n(potions)-1)
take long long x = potions[mid](value) if it * value < success start = mid+1 else end = mid-1 , after that push the count
of successful pairs(n-start), and return ans;
*/
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size();
        int n = potions.size();
        vector<int>ans;
        sort(potions.begin(), potions.end());
        for(auto it : spells){
            int start = 0;
            int end = n-1;         
            while(start <= end){
                int mid = end - (end-start)/2;
                long long x = potions[mid];
                if(it * x < success){
                    start = mid+1;
                }else{
                    end = mid-1;
                }
            }
            ans.push_back(n-start);                      //return difference
        }
        return ans;
    }
};
/*
Example 1:
Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
Output: [4,0,3]
Explanation:
- 0th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
- 1st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
- 2nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
Thus, [4,0,3] is returned.

Example 2:
Input: spells = [3,1,2], potions = [8,5,8], success = 16
Output: [2,0,2]
Explanation:
- 0th spell: 3 * [8,5,8] = [24,15,24]. 2 pairs are successful.
- 1st spell: 1 * [8,5,8] = [8,5,8]. 0 pairs are successful. 
- 2nd spell: 2 * [8,5,8] = [16,10,16]. 2 pairs are successful. 
Thus, [2,0,2] is returned.
*/


//55. FIND PEAK ELEMENT                                              {T.C = O(LOGN), S.C = O(1)}
/*
Use Simple binary search, check if(nums[mid] < nums[mid+1]) then start = mid+1, else end = mid and finally return start.
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while(start < end){
            int mid = start + (end-start)/2;
            if(nums[mid] < nums[mid+1]){              //peak may be in right side
                start = mid+1;
            }else{ //(nums[mid] > nums[start])        //peak may be in left side
                end = mid;
            }
        }
        return start;
    }
};
/*
Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
*/


//56. KOKO EATING BANANAS                                        {T.C = O(LOGN), S.C = O(1)}
/*
Iniitialize two pointer one is one start(piles) another on max element of piles vector , now apply binary search
if(hour >= counthours of getHours(piles, mid)) ans = mid, end = mid-1 else start = mid+1, and return ans, In get hour func
initialize count = 0, now iterate on piles count += it/mid for remaining(it%mid != 0) count++ finally return count.
*/
class Solution {
public:
    long long getHours(vector<int>&piles, int mid){
        long long count = 0;
        for(auto it : piles){
            count += it/mid;                    //4/3 for 3/3 count++
            if(it % mid != 0){                    //4%3 for rest 1 banana count++
                count++;
            }
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = start;

        while(start <= end){
            int mid = start + (end-start)/2;
            if(h >= getHours(piles, mid)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};
/*
Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23
*/
