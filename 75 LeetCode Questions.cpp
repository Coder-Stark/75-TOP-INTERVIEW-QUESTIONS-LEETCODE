//75 TOP INTERVIEW QUESTIONS LEETCODE
#include<bits/stdc++.h>
using namespace std;

/*----------------------------------------------ARRAY/STRING------------------------------------------------------------------*/
//01. MERGE STRINGS ALTERNATELY                                                 {T.C = O(N), S.C = O(N)}
/*
simply take 2 pointers initialize to both strings if both smaller then total length ans += strings(1, 2) , if 1 is bigger(exhaust other) 
simply return rest of string.
*/
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n = word1.length();
        int m = word2.length();

        int i = 0, j = 0;                        //initial pointers for both strings
        while(i < n && j < m){
            ans += word1[i];
            ans += word2[j];
            i++, j++;
        }
        while(i < n){                           //if string 2 exhausted
            ans += word1[i];
            i++;
        }
        while(j < m){                           //if string 1 exhausted
            ans += word2[j];
            j++;
        }

        return ans;
    }
};
/*
Example 1:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r

Example 2:
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s

Example 3:
Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
*/


//02. GREATEST COMMON DIVISOR OF STRINGS                                           {T.C = O(N), S.C = O(N)}
/*
Using Commutative property of math (3+6 = 9 == 6+3 = 9) ,it implies that the strings have a common divisor ,then extracts a substring from
str1 starting from index 0 with a length determined by the gcd of the lengths of str1 and str2.
*/
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 == str2+str1){
            return str1.substr(0, gcd(str1.size(), str2.size()));  //where gcd(3, 6) = 3
        }
        return "";
    }
};
/*
Example 1:
Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"

Example 2:
Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"

Example 3:
Input: str1 = "LEET", str2 = "CODE"
Output: ""
*/


//03. KIDS WITH THE GREATEST NUMBER OF CANDIES                                 {T.C = O(N), S.C = O(N)}
/*
First find maximum element of vector of candies then iterate again and check if candies[i] + extracandies >= maxi then push true else false
to ans vector.
*/
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int maxi = INT_MIN;
        for(int i = 0 ; i < candies.size() ; i++){
            maxi = max(maxi, candies[i]);
        }
        for(int i = 0 ; i < candies.size() ; i++){
            if(candies[i]+extraCandies >= maxi){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
/*
Example 1:
Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 
Explanation: If you give all extraCandies to:
- Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
- Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
- Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
- Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
- Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.

Example 2:
Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false] 
Explanation: There is only 1 extra candy.
Kid 1 will always have the greatest number of candies, even if a different kid is given the extra candy.
*/


//04. CAN PLACE FLOWERS                                                       {T.C = O(N), S.C = O(1)}
/*
First check base case if n == 0 then always true, check left and right empty with boundary condition if its empty we can place flower else not.
*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = flowerbed.size();

        if(n == 0){                                  //if flower 0 then always true
            return true;
        }

        for(int i = 0 ; i < l ; i++){
            if(flowerbed[i] == 0){
                bool left = (i == 0) || (flowerbed[i-1] == 0);
                bool right = (i == l-1) || (flowerbed[i+1] == 0);

                if(left && right){
                    flowerbed[i] = 1;                   //place flower and decrease count of flower
                    n--;
                    if(n == 0){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
/*
Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
*/


//05. REVERSE VOWELS OF A STRING                                              {T.C = O(N), S.C = O(1){constant space(10 char)}}
/*
First store all the vowels in a set then initialize two pointers (start, end) while(i < j) , inner i < j && vowels not find move i and j
if find then swap initial and final characters(vowel).
*/
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int n = s.size();
        int j = n-1;

        unordered_set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');

        while(i < j){
            while(i < j && st.find(s[i]) == st.end()){
                i++;
            }
            while(i < j && st.find(s[j]) == st.end()){
                j--;
            }
            if(i < j){
                swap(s[i], s[j]);
                i++, j--;
            }
        }
        return s;
    }
};
/*
Example 1:
Input: s = "hello"
Output: "holle"

Example 2:
Input: s = "leetcode"
Output: "leotcede"
*/


//06. REVERSE WORDS IN A STRING
/*
*/
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans;
        int i = 0;
        while(i < n){
            while(i < n && s[i] == ' '){               //continue beginning spaces
                i++;
            }
            if(i >= n){
                break;
            }
            int j = i+1;                              //just next space's word
            while(j < n && s[j] != ' '){              //word encounter
                j++;
            }
            string sub = s.substr(i, j-i);            //find substring = substr(initial, lenght (substring))
            if(ans.empty()){
                ans = sub;
            }else{
                ans = sub + " " + ans;                //reverse push 
            }
            i = j+1;
        }
        return ans;
    }
};
/*
Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
*/


//07. PRODUCT OF ARRAY EXCEPT SELF
/*
First find the prefix product (before current element product) then find the suffix product (after the current element 
product ) by both ans we get total product except own self.
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 1);
        int leftProd = 1;                                //prefix
        for(int i = 0 ; i < n ; i++){
            ans[i] *= leftProd;
            leftProd *= nums[i];
            
        }
        int rightProd = 1;                              //suffix
        for(int i = n-1 ; i >= 0 ; i--){
            ans[i] *= rightProd;
            rightProd *= nums[i];
        }
        return ans;
    }
};
/*
Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/


//08. INCREASING TRIPLET SUBSEQUENCE                                 {T.C = O(N), S.C = O(1)}
/*
First check the base case if n < 3 then return false(not possible triplet) initialize firstMin and secondMin and
store the first min and second min element and 3rd element return true , else false.
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        //base case
        if(n < 3){
            return false;
        }
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] <= firstMin){
                firstMin = nums[i];
            }else if(nums[i] <= secondMin){       //check for second min element
                secondMin = nums[i];
            }else{
                return true;                      //third element is greater
            }
        }
        return false;
    }
};
/*
Example 1:
Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.

Example 2:
Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.

Example 3:
Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
*/


//09. STRING COMPRESSION                                               {T.C = O(N), S.C = O(1)}
/*
First find the count if char is same to next char, then handle case count > 1 && count > 9 {10 = '1' '0'} put it into string.
*/
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int index = 0;
        
        while(i < n){
            //find count
            int count = 0;
            char currChar = chars[i];
            while(i < n && chars[i] == currChar ){
                count++;
                i++;
            }

            //now do asssign operation
            chars[index] = currChar;
            index++;
            // chars[index] = count;                 //we cant use directly handle (10 = '1' '0' & count > 1)
            if(count > 1){
                string countStr = to_string(count);          //10 = '1' '0'
                for(char it : countStr){
                    chars[index] = it;
                    index++;
                }
            }
        }
        return index;                               //index points to end of required (compressed)string (length)
    }
};
/*
Example 1:
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

Example 2:
Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.

Example 3:
Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
*/


/*---------------------------------------- TWO POINTERS --------------------------------------------------------*/
//10. MOVE ZEROES                                                          {T.C = O(N), S.C = O(1)}
/*
Two pointer appraoch 1st pointer use to keep track of non zero element another when is simple iteration , if(nums[j] is not 0) then it will swap
with nums[i] it ensures that nonzero element shift ot front.
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;                                  //placing non zero element to front
        int j = 0;                                  //for iteration
        while(j < n){
            if(nums[j] != 0){                      
                swap(nums[i], nums[j]);            //nonzero element shift to front
                i++;
            }
            j++;
        }
    }
};
/*
Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]
*/


//11. IS SUBSEQUENCE                                                    {T.C = O(N), S.C = O(1)}
/*
Initialize pointer to both string and iterate if same char then move first and second pointer else move second pointer at last check the
first string is completed or not.
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i = 0;                      //initial pointer of s
        int j = 0;                      //initial pointer of t
        while(i < n && j < m){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }
        return i == s.size();           //string s is exhausted or not
    }
};
/*
Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false
*/


//12. CONTAINER WITH MOST WATER                                                     {T.C = O(N), S.C = O(1)}
/*
Intiailize two pointers first and last then find height(min(left, right)) and width = right-left thnen find area = l*b
take maxArea = max(maxArea, currArea), if(h[left] <= h[right]) left++ else r--.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int maxWaterArea = 0;
        while(left < right){
            int h = min(height[left], height[right]);         //water can fill only lowest height of container
            int width = right-left;
            int currWaterArea = h * width;                    //area = l * b
            maxWaterArea = max(maxWaterArea, currWaterArea);
            if(height[left] <= height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxWaterArea;
    }
};
/*
Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1
*/


//13. MAX NUMBER OF K-SUM PAIRS                                            {T.C = O(N*LOGN), S.C = O(1)}
/*
First sort the array then use two pointer approach if sum of nums[i]+nums[j] == k then increase count else if less then i++ else j--.
*/
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0; 
        int j = n-1;
        int opCount = 0;

        sort(nums.begin(), nums.end());
        
        while(i < j){
            if(nums[i]+nums[j] == k){
                opCount++;
                i++, j--;
            }else if(nums[i]+nums[j] < k){
                i++;
            }else{
                j--;
            }
        }
        return opCount;
    }
};
/*
Example 1:
Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.

Example 2:
Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
*/


/*-------------------------------------------SLIDING WINDOW ------------------------------------------*/
//14. MAXIMUM AVERAGE SUBARRAY I                                            {T.C = O(N), S.C = O(1)}
/*
First find the window then maxAvg = max(maxAvg, sum/k(avg)) and shrink move window by shrinking from left(sum -= nums[i])
and increasing right side (j++).
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        double maxiAvg = INT_MIN;
        double sum = 0;
        double avg = 0;
        while(j < n){
            sum += nums[j];
            if(j-i+1 < k){                  //find k size window
                j++;
            }else if(j-i+1 == k){
                maxiAvg = max(maxiAvg, sum/k);
                sum -= nums[i];            //shrink window
                i++, j++;
            }
        }
        return maxiAvg;
    }
};
/*
Example 1:
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:
Input: nums = [5], k = 1
Output: 5.00000
*/


//15. MAXIMUM NUMBER OF VOWELS IN A SUBSTRING OF GIVEN LENGTH                      {T.C = O(N), S.C = O(1)}
/*
First store the all vowels in map(char, bool) , then first check if char matches to mp's char then count++, then expend the window,
when the window length reach to k then shrink window from left and match the char to mp if same the count--. return maxi(window).
*/
class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        //unordered_map<char, bool> isVowel = {{'a', true}, {'e', true}, {'i', true}, {'o', true}, {'u', true}};
        unordered_map<char, bool>mp;
        mp['a'] = true;
        mp['e'] = true;
        mp['i'] = true;
        mp['o'] = true;
        mp['u'] = true;

        int i = 0, j = 0;
        int maxi = 0;
        int count = 0;
        while(j < n){
            if(mp.find(s[j]) != mp.end()){
                if(mp[s[j]]){                         //if char is found(true)
                    count++;
                }
            }
            if(j-i+1 < k){
                j++;
            }else if(j-i+1 == k){
                maxi = max(maxi, count);
                if(mp.find(s[i]) != mp.end()){             //shrinking window
                    if(mp[s[i]]){
                        count--;
                    }
                }
                i++, j++;
            }
        }
        return maxi;
    }
};
/*
Example 1:
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

Example 2:
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.

Example 3:
Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
*/


//16. MAX CONSECUTIVE ONES III                                                  {T.C = O(N), S.C = O(1)}
/*
Using Variable Size Sliding window approach, take variable of zeroCount and store it if it is > K then shrink the window and at last 
return max length.(we can swap only those 0s whose count is less then k only)
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int zeroCount = 0;
        int maxi = 0;

        while (j < n) {
            if (nums[j] == 0) {
                zeroCount++;
            }
            while (zeroCount > k) {         // If zeroCount exceeds k, move the window's starting position (i)
                if (nums[i] == 0) {
                    zeroCount--;
                }
                i++;
            }
            maxi = max(maxi, j - i + 1);   // Update the maximum length of the subarray
            j++;
        }

        return maxi;
    }
};
/*
Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/


//17. LONGEST SUBARRAY OF 1'S AFTER DELETING ONE ELEMENT                          {T.C = O(N), S.C = O(1)}
/*
Using Variable Size Sliding window, take zero count for first zero occur in subarray zeroCount++, then for next shrink window(j-i) 1 is deleted
always, after that return maxi(length of subarray).
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int maxi = 0;
        int zeroCount = 0;

        while(j < n){
            if(nums[j] == 0){
                zeroCount++;
            }
            while(zeroCount > 1){
                if(nums[i] == 0){
                    zeroCount--;
                }
                i++;
            }
            maxi = max(maxi, j-i);          //j-i (1 deleted {j-i+1 - 1 = j-i})
            j++;
        }
        return maxi;
    }
};
/*
Example 1:
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

Example 2:
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

Example 3:
Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
*/


/*------------------------------------------------------------PREFIX SUM--------------------------------------------------------------*/
//18. FIND THE HIGHEST ALTITUDE                                                  {T.C = O(N), S.C = O(N)}
/*
Take a vector then store prefix sum of there by pushing element and prefix.back() after that return max of the prefix vector
*/
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int>prefixSum(n, 0);
        for(auto it : gain){
            prefixSum.push_back(prefixSum.back() + it);
        }
        return *max_element(prefixSum.begin(), prefixSum.end());
    }
};
/*
Example 1:
Input: gain = [-5,1,5,0,-7]
Output: 1
Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.

Example 2:
Input: gain = [-4,-3,-2,-1,4,3,2]
Output: 0
Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.
*/


//19. FIND PIVOT INDEX                                                {T.C = O(N), S.C = O(1)}
/*
First find the total sum of the array, then iterate again decrease sum = sum-a[i] if it is equal to prefix sum then return the index else
increase the prefix sum else return -1.
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int prefixSum = 0;

        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
        }

        for(int i = 0 ; i < n ; i++){
            sum = sum-nums[i];
            if(sum == prefixSum){                   //left sum == right sum (return index)
                return i;
            }
            prefixSum += nums[i];
        }
        return -1;
    }
};
/*
Example 1:
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

Example 2:
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.

Example 3:
Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
*/


/*------------------------------------------------------ HASH MAP / SET ----------------------------------------------------*/
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


/*---------------------------------------------------------- STACK ----------------------------------------------*/
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


/*--------------------------------------------------- QUEUE ----------------------------------------------------*/
//27. NUMBER OF RECENT CALLS                                             {T.C = O(N), S.C = O(1)}
/*
Take an queue, first find the margin(t-3000) push the element(t) in queue, pop the element from queue until top element lesser then margin
after that return size of queue.
*/
class RecentCounter {
public:
    queue<int>q;
    RecentCounter() {
        
    }
    int ping(int t) {
        int margin = t - 3000;
        q.push(t);
        while(q.front() < margin){
            q.pop();
        }
        return q.size();
    }
};
/*
Example 1:

Input
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]
Output
[null, 1, 2, 3, 3]

Explanation
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [1], range is [-2999,1], return 1
recentCounter.ping(100);   // requests = [1, 100], range is [-2900,100], return 2
recentCounter.ping(3001);  // requests = [1, 100, 3001], range is [1,3001], return 3
recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002], range is [2,3002], return 3
*/


//28. DOTA2 SENAT
//BRUTE FORCE                                                         {T.C = O(N^2), S.C = O(1)}
/*
First store count of R and D, initialize idx = 0, if (R) remove nearest D vice versa,
idx-- when we deleted someone at index < idx.
idx+1 % (length of updated strings) for round.
*/
class Solution {
public:
    bool removeSenator(string &senate, char ch, int i){
        bool checkRemoveLeftSide = false;

        while(true){
            if(i == 0){              //1 round completed
                checkRemoveLeftSide = true;
            }
            if(senate[i] == ch){
                senate.erase(senate.begin() + i);  //shift
                break;
            }
            (i+1) % senate.length();
        }
        return checkRemoveLeftSide;
    }
    string predictPartyVictory(string senate) {
        int rCount = count(senate.begin(), senate.end(), 'R');
        int dCount = senate.length()-rCount;

        int idx = 0;
        while(rCount > 0 && dCount > 0){
            if(senate[idx] == 'R'){
                bool checkRemoveLeftSide = removeSenator(senate, 'D',(idx+1) % senate.length());
                dCount--;
                if(checkRemoveLeftSide){
                    idx--;
                }
            }else{ //(senate[idx] == 'D')
                bool checkRemoveLeftSide = removeSenator(senate, 'R', (idx+1) % senate.length());
                rCount--;
                if(checkRemoveLeftSide){
                    idx--;
                }
            }
            idx = (idx+1) % senate.length();
        }

        return rCount == 0 ? "Dire" : "Radiant";
    }
};

//OPTIMIZED APPROACH                                                       {T.C = O(N), S.C = O(N)}
/*
Similar to above just not shifting element,by taking extra space of vector <bool>removed.
*/
class Solution {
public:
    void removeSenator(string &senate, char ch, int i, vector<bool>&removed){
        while(true){
            if(senate[i] == ch && removed[i] == false){
                removed[i] = true;
                break;
            }
            i = (i+1) % senate.length();
        }
    }
    string predictPartyVictory(string senate) {
        int rCount = count(senate.begin(), senate.end(), 'R');
        int dCount = senate.length()-rCount;
        int n = senate.length();
        vector<bool>removed(n, false);

        int idx = 0;
        while(rCount > 0 && dCount > 0){
            if(removed[idx] == false){
                if(senate[idx] == 'R'){
                    removeSenator(senate, 'D',(idx+1) % senate.length(), removed);
                    dCount--;
                }else{ //(senate[idx] == 'D')
                    removeSenator(senate, 'R', (idx+1) % senate.length(), removed);
                    rCount--;
                }
            }
            idx = (idx+1) % senate.length();
        }

        return rCount == 0 ? "Dire" : "Radiant";
    }
};
/*
Example 1:
Input: senate = "RD"
Output: "Radiant"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And in round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.

Example 2:
Input: senate = "RDD"
Output: "Dire"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And the third senator comes from Dire and he can ban the first senator's right in round 1. 
And in round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.
*/


/*----------------------------------------------------------------- LINKED LIST --------------------------------------------*/
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//29. DELETE THE MIDDLE NODE OF A LINKED LIST                                  {T.C = O(N), S.C = O(1)}
/*
Using slow and fast pointer approach first find the middle element then remove middle element(temp->next = slow->next {slow (middle element skipped)})
after that delete slow and return head;
*/
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = NULL;

        while(fast && fast->next){                     //finds middle element
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = slow->next;                       //middle element removed
        delete slow;
        return head;
    }
};
/*
Example 1:
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 

Example 2:
Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.

Example 3:
Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
*/


//30. ODD EVEN LINKED LIST                                                  {T.C = O(N), S.C = O(1)}
/*
Using two pointers one from head and another from head->next now traverse ll while(even && even->next) increase both pointers after that
connect odd->next = evenhead (connect odd and even ll).
*/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        //base case
        if(!head || !head->next){
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* temp = even;                 //store head of even ll


        while(even && even->next){             //check second or next element 
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = temp;                     //connect odd->even list

        return head;
    }
};
/*
Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
*/


//31. REVERSE LINKED LIST                                                     {T.C = O(N), S.C = O(1)}
/*
Using prev(null), curr(head) and next(null) pointers while(curr) , next = curr->next , curr->next = prev, prev = curr, curr = next; 
after that return prev.
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
/*
Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []
*/


//32. MAXIMUM TWIN SUM OF A LINKED LIST                                           {T.C = O(N), S.C = O(N)}
//32a. APPROACH 1(By converting LL into vector)
/*
First Store all ll element into a vector then initialize 2 pointers i = 0 and j = n-1 , take twinSum = arr[i]+arr[j] and update max 
after that retun max.
*/
class Solution {
public:
    /*
    ListNode* ArrToLL(vector<int>&arr){
        int n = arr.size();
        //base case
        if(n == 0){
            return NULL;
        }

        ListNode* head = new ListNode(arr[0]);
        ListNode* curr = head;
        for(int i = 1 ; i < n ; i++){
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }
        return head;
    }
    */
    void llToArr(ListNode* head, vector<int>&arr){
        ListNode* temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
    }
    int pairSum(ListNode* head) {
        vector<int>arr;
        llToArr(head, arr);
        int twinSum = 0;
        int n = arr.size();
        int maxi = INT_MIN;
        int i = 0 , j = n-1;
        while(i < j){
            twinSum = arr[i] + arr[j];
            maxi = max(maxi, twinSum);
            i++;
            j--;
        }
        return maxi;
    }
};

//32b. APPROACH 2 (USING STACK)                                                 {T.C = O(N), S.C = O(N)}
/*
Take Stack put ll element into stack, then traverse ll till n/2 and add st.top().
*/
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int>stk;
        ListNode* temp = head;
        while(temp){
            stk.push(temp->val);
            temp = temp->next;
        }

        temp = head;                    //reinitialize temp with head
        int n = stk.size();
        int twinSum = 0;
        int maxi = INT_MIN;
        int i = 0;
        while(i < n/2 && temp){
            twinSum = temp->val + stk.top();
            maxi = max(maxi, twinSum);
            stk.pop();
            temp = temp->next;
            i++;
        }
        return maxi;
    }
};

//32c. APPROCH 3 (USING LL{reverse 2nd half(mid)})                              {T.C = O(N), S.C = O(1)}
/*
Finds the mid node, reverse after the mid node then take two pointers on start and mid and add
the two pointers return max of it.
*/
class Solution {
public:
    int pairSum(ListNode* head) {
        //Finding mid
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = NULL;

        while(fast && fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;


        //Reverse 2nd half of ll

        ListNode* prev = NULL;
        // ListNode* mid = slow;
        ListNode* next = NULL;
        
        while(mid){
            next = mid->next;
            mid->next = prev;
            prev = mid;
            mid = next;
        }

        //Find max result 
        temp = head;                    //reinitialize temp with head
        int twinSum = 0;
        int maxi = INT_MIN;
        int i = 0;
        while(prev){                                 //2nd half start from prev
            twinSum = temp->val + prev->val;
            maxi = max(maxi, twinSum);
            temp = temp->next;
            prev = prev->next;
        }
        return maxi;
        

    }
};
/*
Example 1:
Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6. 

Example 2:
Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 

Example 3:
Input: head = [1,100000]
Output: 100001
Explanation:
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.
*/


/*-------------------------------------------------------- BINARY TREE - DFS ------------------------------------------------------*/
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


/*--------------------------------------------------------------- BINARY TREE BFS -----------------------------------------------*/
//39. BINARY TREE RIGHT SIDE VIEW                                          {T.C = O(N), S.C = O(N)}
/*
Take vector and call solve function in which NRL(Right view) {NLR(Left View)} if(level == ans.size(){size reached change level}), push root->val
in vector and level++.
*/
class Solution {
public:
    void solve(TreeNode* root, vector<int>&ans, int level){
        //base case
        if(!root){
            return;
        }

        //NRL        (for right view)  //for left view (NLR)
        if(level == ans.size()){                   //if level reach ends then change the level and push root->data in vector
            ans.push_back(root->val);           
        }
        solve(root->right, ans, level+1);
        solve(root->left, ans, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        solve(root, ans, 0);                      //0 == initial level
        return ans;
    }
};
/*
Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:
Input: root = [1,null,3]
Output: [1,3]

Example 3:
Input: root = []
Output: []
*/


//40. MAXIMUM LEVEL SUM OF A BINARY TREE                              {T.C = O(N), S.C = O(N)}
/*
Take resultLvl, currLvl, maxiSum and queue(bfs) push root in queue, then bfs(while(!q.empty())) traverse in queue
and update sum also check for left and right subtree after that currLvl++ and update result lvl.
*/
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int resultLvl = 0;
        int currLvl = 1;
        int maxiSum = INT_MIN;
        queue<TreeNode*>q;                             //bfs
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            int sum = 0;

            while(n--){                              //traverse in queue(stores level's nodes)
                TreeNode* frontNode = q.front();
                q.pop();
                sum += frontNode->val;

                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }
            if(sum > maxiSum){
                maxiSum = sum;
                resultLvl = currLvl;
            }
       
            currLvl++;
        }
        return resultLvl;
    }
};
/*
Example 1:
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.

Example 2:
Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2
*/


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


/*------------------------------------------------------- GRAPHS GENERAL ------------------------------------------------*/
//GRAPH
//MINIMUM DISTANCE FINDING ALGORITHM
/*
1. DIJKSTRA'S ALGO                  {not work for -ve weighted graph}
2. BELLMANFORD ALGO                 {work for -ve weighted graph}
3. FLOYD WARSHALL ALGO              {brute force algo}
*/
//MINIMUM SPANNING TREE ALGORITHM
/*
1. KRUSKAL'S ALGO          {intermediate result may be or may be not connected}
2. PRIM'S ALGO             {intermediate result always connected} 
*/

//BFS OF GRAPH                                                      {T.C = O(N+M/ V+E), S.C = O(N+M / V+E)}   //N = nodes, E = edges
/*
We required 3 DS (ans, vis(bool), queue) and also initialize nodeindex = 0, push node in queue and mark vis[node] = 1 and push node in ans
now traverse queue, take out frontNode and push in ans, after that traverse adj[frontNode] , if (!vis[it]) then push it and mark vis[it]=1.
*/
class Solution {
  public:
    void BFS(vector<int>adj[], vector<int>&ans, vector<bool>&vis, int node){
        queue<int>q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            for(auto it : adj[frontNode]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<bool>vis(V, 0);
        BFS(adj, ans, vis, 0);                        //node index = 0
        return ans;
    }
};
/*
Example 1:
Input:
V = 5, E = 4
adj = {{1,2,3},{},{4},{},{}}
Output: 
0 1 2 3 4
Explanation: 
0 is connected to 1 , 2 , 3.
2 is connected to 4.
so starting from 0, it will go to 1 then 2
then 3. After this 2 to 4, thus bfs will be
0 1 2 3 4.

Example 2:
Input:
V = 3, E = 2
adj = {{1,2},{},{}}
Output: 
0 1 2
Explanation:
0 is connected to 1 , 2.
so starting from 0, it will go to 1 then 2,
thus bfs will be 0 1 2. 
*/


//DFS OF GRAPH                                                        {T.C = O(N+M / V+E), S.C = O(N+M / V+E)}
/*
We required 2 DS (ans, vis(bool)) and also initialize nodeindex = 0,  mark vis[node] = 1 and push node in ans,  now traverse adj[node],
if (!vis[it]) then push it and mark vis[it]=1 and make recursive call to DFS.
*/
class Solution {
  public:
    void DFS(vector<int>adj[], vector<int>&ans, vector<bool>&vis, int node){
        vis[node] = 1;
        ans.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                DFS(adj, ans, vis, it);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<bool>vis(V, 0);
        DFS(adj, ans, vis, 0);                       //0 = nodeindex
        return ans;

        /*
        //handle disconnected components
        for(int i = 0 ; i < V ; i++){
            dfs(0, adj, ans, vis);                                  //0 = starting index or node
        }
        */
    }
};
/*
Example 1:
Input: V = 5 , adj = [[2,3,1] , [0], [0,4], [0], [2]]
Output: 0 2 4 3 1
Explanation: 
0 is connected to 2, 3, 1.
1 is connected to 0.
2 is connected to 0 and 4.
3 is connected to 0.
4 is connected to 2.
so starting from 0, it will go to 2 then 4,
and then 3 and 1.
Thus dfs will be 0 2 4 3 1.

Example 2:
Input: V = 4, adj = [[1,3], [2,0], [1], [0]]
Output: 0 1 2 3
Explanation:
0 is connected to 1 , 3.
1 is connected to 0, 2. 
2 is connected to 1.
3 is connected to 0. 
so starting from 0, it will go to 1 then 2
then back to 0 then 0 to 3
thus dfs will be 0 1 2 3. 
*/


/*----------------------------------------------------- GRAPHS DFS ------------------------------------------------*/
//43. KEYS AND ROOMS                                             {T.C = O(N+M), S.C = O(N+M)}
/*
Simple dfs , take bool vector and call dfs if after dfs any room is left or(vis == false) then return false else true.
*/
class Solution {
public:
    void dfs(vector<vector<int>>&rooms, vector<bool>&vis, int node){
        vis[node] = true;
        for(auto it : rooms[node]){
            if(!vis[it]){
                dfs(rooms, vis, it);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n, false);
        dfs(rooms, vis, 0);                      //0 = nodeindex
        for(auto it : vis){                      //if there is single false then ans not possible
            if(it ==  false){
                return false;
            }
        }
        return true;
    }
};
/*
Example 1:
Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.

Example 2:
Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.
*/


//44. NUMBER OF PROVINCES                                       {T.C = O(N^2), S.C = O(N+M)}
/*
Actually We are finding the components(islands) in this , we use simple dfs and take for loop for handling disconnected
components and in dfs Call we checks for index(for(int i = 0 ; i < n ; i++)) not for value(auto it : isConnected[node])
*/
class Solution {
public:
    void dfs(vector<vector<int>>&isConnected, vector<bool>&vis, int node){
        int n = isConnected.size();
        vis[node] = 1;
        for(int i = 0 ; i < n ; i++){                           //checks for index not value(auto it : isConnected[node])
            if(!vis[i] && isConnected[node][i] == 1){           //checks there is direct connnection.
                dfs(isConnected, vis, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int uniqueNodes = 0;
        vector<bool>vis(n, 0);
        for(int i = 0 ; i < n ; i++){                       //for disconnected components
            if(!vis[i]){
                dfs(isConnected, vis, i);                           //0 = nodeIndex
                uniqueNodes++;
            }
        }
        return uniqueNodes;
    }
};
/*
Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
*/


//45. REORDER ROUTES TO MAKE ALL PATHS LEAD TO THE CITY ZERO              {T.C = O(N+M), S.C = O(N+M)}
/*
Initialize a count variable = 0, make and adj list, with pair<value, 1or0(real path or imaginary path)> and vised array
then make dfs call in dfs call simple dfs mark vis[node] = 1 then iterate over adjcency list and if not vis[node / v] ,
if(it.second == 1) real path(means it is real and moving away from 0 so we have to flip) count++ finally return count.
*/
class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>&adj, vector<bool>&vis, int &count, int node){
        vis[node] = 1;
        for(auto it : adj[node]){              //pair<int, int>it    {value, (1 or 0)}
            int v = it.first;
            int check = it.second;             //1 = real, 0 = imaginary
            if(!vis[v]){                       //node's value or node is not visited
                if(check == 1){                //means it is real and moving away from 0 so we have to flip
                    count++;
                }
                dfs(adj, vis, count, v);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        int count = 0;                                //no. of flips
        vector<vector<pair<int, int>>>adj(n);
        vector<bool>vis(n, 0);
        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            adj[u].push_back({v, 1});                 //real path(1)
            adj[v].push_back({u, 0});                 //imaginary path(0)
        }

        dfs(adj, vis, count, 0);                             //0 = starting/node index
        return count;
    }
};
/*
Example 1:
Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 2:
Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 3:
Input: n = 3, connections = [[1,0],[2,0]]
Output: 0
*/


//46. EVALUATE DIVISION                                       {T.C = O(N+M), S.C = O(N+M)}
/*
similar question to graph with with weight or graph traversal
*/
class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string, double>>> &adj, string src, string dst, double &ans, double prod, unordered_set<string>&vis){
        if(vis.find(src) != vis.end()){
            return;
        }
        vis.insert(src);       //mark visited
        if(src == dst){
            ans = prod;
            return;
        }
        for(auto it : adj[src]){
            string v = it.first;
            double val = it.second;
            dfs(adj, v, dst, ans, prod*val, vis);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //similar question to graph with with weight or graph traversal
        int n = equations.size();

        //create adjacency list
        // unordered_map<int, int>mp;
        unordered_map<string, vector<pair<string, double>>>adj;
        for(int i = 0 ; i < n ; i++){
            string u = equations[i][0];       //"a"
            string v = equations[i][1];       //"b"
            double val = values[i];            //2

            adj[u].push_back({v, val});     //a/b
            adj[v].push_back({u, 1.0/val}); //b/a
        }

        vector<double>result;

        for(auto it : queries){
            string src = it[0];
            string dst = it[1];

            double ans = -1.0;
            double prod = 1.0;


            if(adj.find(src) != adj.end()){
                unordered_set<string>vis;                 //vis set created each time 
                dfs(adj, src, dst, ans, prod, vis);
            }
            result.push_back(ans);
        }
        return result;
    }
};
/*
Example 1:
Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0

Example 2:
Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]

Example 3:
Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
*/


/*------------------------------------------------------- GRAPH BFS ----------------------------------------------------------*/
//47. NEAREST EXIT FROM ENTRANCE IN MAZE                                   {T.C = O(N*M), S.C = O(N)}
/*
We use simple BFS approach, take queue initialize with entrance position , take count of minSteps =0, mark grid visited (grid[en[0]][en[1]] = '+')
while !q.empty() take sz of queue in that while (que sze--) simply extract top element and check the condition if exit find return minSteps else
return -1;
*/
class Solution {
public:
    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});                 //push initial position(entrance of maze)
        int minSteps = 0;

        // mark the entrance cell as visited
        grid[entrance[0]][entrance[1]] = '+';

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto frontNode = q.front();
                q.pop();
                int i = frontNode.first;
                int j = frontNode.second;

                // if exit cell is found return minSteps
                if(!(i == entrance[0] && j == entrance[1]) && (i == 0 || j == 0 || i == n - 1 || j == m - 1)){
                    return minSteps;
                }

                //explore all neighbours
                vector<vector<int>>directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                for(auto it : directions){
                    int new_i = i + it[0];
                    int new_j = j + it[1];

                    if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] != '+'){
                        grid[new_i][new_j] = '+';
                        q.push({new_i, new_j});
                    }
                }
            }
            minSteps++;
        }
        return -1;
    }
};
/*
Example 1:
Input: maze = [["+","+",".","+"],
               [".",".",".","+"],
               ["+","+","+","."]], 
       entrance = [1,2]
Output: 1
Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
Initially, you are at the entrance cell [1,2].
- You can reach [1,0] by moving 2 steps left.
- You can reach [0,2] by moving 1 step up.
It is impossible to reach [2,3] from the entrance.
Thus, the nearest exit is [0,2], which is 1 step away.

Example 2:
Input: maze = [["+","+","+"],
               [".",".","."],
               ["+","+","+"]],
       entrance = [1,0]
Output: 2
Explanation: There is 1 exit in this maze at [1,2].
[1,0] does not count as an exit since it is the entrance cell.
Initially, you are at the entrance cell [1,0].
- You can reach [1,2] by moving 2 steps right.
Thus, the nearest exit is [1,2], which is 2 steps away.

Example 3:
Input: maze = [[".","+"]],
       entrance = [0,0]
Output: -1
Explanation: There are no exits in this maze.
*/


//48. ROTTING ORANGES                                                         {T.C = O(N*M), S.C = O(N)}
/*
Take queue{{row, col}, time} traverse in a grid if its 2 (rotten) push in queue with 0 time and mark vis = 2, else vis = 0(not rotten) , if element
is 1 then cntFreshOranges++, intitialze variable time and count = 0, apply bfs and check for neighbours , finally return time.
*/
class Solution {
  public:
    int orangesRotting(vector<vector<int>>&grid) {
      int n = grid.size();
      int m = grid[0].size();

      queue<pair<pair<int, int>,int>>q;                // store {{row, column}, time}
      int vis[n][m];
      int cntFresh = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (grid[i][j] == 2) {                      // if cell contains rotten orange push in queue with time 0 and mark vis(rotten {2})
            q.push({{i, j}, 0}); 
            vis[i][j] = 2;                            
          }
          else {                                      // if not rotten
            vis[i][j] = 0;
          }
          if (grid[i][j] == 1){                       // count fresh oranges
            cntFresh++;
          } 
        }
      }

      int tm = 0;
      int cnt = 0;
      vector<vector<int>>directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

      // bfs traversal (until the queue becomes empty)
      while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();

        //explore neighbours
        for (auto it : directions) {
          int nrow = r + it[0];
          int ncol = c + it[1];
          if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
            q.push({{nrow, ncol}, t + 1});                // push in queue with timer increased
            vis[nrow][ncol] = 2;                          // mark as rotten
            cnt++;
          }
        }
      }
      
      if (cnt != cntFresh){                              // if all oranges are not rotten
        return -1;                     
      } 
      return tm;
    }
};
/*
Example 1:
Input: grid = [[2,1,1],
               [1,1,0],
               [0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],
               [0,1,1],
               [1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
*/


/*----------------------------------------------------- HEAP / PRIORITY QUEUE -----------------------------------------*/
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


/*---------------------------------------------------- BINARY SEARCH -------------------------------------------------*/
//53. GUESS NUMBER HIGHER OR LOWER                                  {T.C = O(LOGN), S.C = O(1)}
/*
First there is Pre defined guess function with output(0, 1, -1) , use binary search and find the location of guess number
and update accordingly finally return pick.
*/
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


/*----------------------------------------------------- BACKTRACKING --------------------------------------------------*/
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


/*---------------------------------------- DYNAMIC PROGRAMMING (DP) --------------------------------------------------*/
//59. NTH TRIBONACCI NUMBER                                         {T.C = O(N), S.C = O(N)}
/*
Bottom up(initial index = n) approach in TOP DOWN (DP) first check for base cases , then follow standardise dp steps
and store(dp[i] = solve(i-3)+solve(i-2)+solve(i-1)).
*/
class Solution {
public:
    int solve(int n, vector<int>&dp, int i){
        //base case
        if(i == 0){
            return 0;
        }
        if(i == 1 || i == 2){
            return 1;
        }
        //step3 if ans already present return it
        if(dp[i] != -1){
            return dp[i];
        }

        //step2 store ans in dp
        dp[i] = solve(n, dp, i-3)+solve(n, dp, i-2) + solve(n, dp, i-1);
        return dp[i];
    }
    int tribonacci(int n) {
        if(n == 0){
            return 0;
        }
        vector<int>dp(n+1, -1);
        int ans = solve(n, dp, n);                         //n = initial index = n
        return ans;
    }
};
/*
Example 1:
Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

Example 2:
Input: n = 25
Output: 1389537
*/


//60. MIN COST CLIMBING STAIRS                                       {T.C = O(N), S.C = O(N)}
/*
Use dp and take min(n-1 and n-2) , in solveMem handle base case if(n == 0) return cost[0] similarly for 1 , store ans in
dp = cost[i] + min(solveMem(n-1), solveMem(n-2))
*/
class Solution {
public:
    int solveMem(vector<int>&cost , int n , vector<int>&dp){
        //base case
        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return cost[1];
        }

        //step-3 if answer already present retur it.
        if(dp[n] != -1){
            return dp[n];
        }

        //step2 store ans in dp
        dp[n] = cost[n] + min(solveMem(cost, n-1, dp), solveMem(cost, n-2, dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        //step-1 create dp array
        vector<int>dp(n+1, -1);
        int ans = min(solveMem(cost, n-1, dp), solveMem(cost, n-2, dp));
        return ans;
    }
};
/*
Example 1:
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
*/


//61. HOUSE ROBBER                                                    {T.C = O(N), S.C = O(N)}
/*
Use simple dp and use concept of take(incl) or nontake(excl) , for include = nums[n] + solveMem(nums, n-2, dp) {adjacnt cant include}
for exclude = 0 + solveMem(n-1, dp), after that return max of it.
*/
class Solution {
public:
    int solveMem(vector<int>&nums,int n, vector<int>&dp){
        //base case
        if(n < 0){
            return 0;
        }

        //step3 if ans already present return it
        if(dp[n] != -1){
            return dp[n];
        }

        //step2 recursive call
        int incl = nums[n] + solveMem(nums,n-2, dp);         //adjacent element cant include
        int excl = 0 + solveMem(nums, n-1, dp);

        dp[n] = max(incl, excl);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        //step1 create a dp vector
        vector<int>dp(n+1, -1);
        return solveMem(nums, n-1, dp);                      //traverse from last element (n-1)
    }
};
/*
Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
*/


//62. DOMINO AND TROMINO TILING                                           {T.C = O(N), S.C = O(N)}
/*
We have to use formula ans = 2*(n-1) + (n-3) and store ans n dp , finally return it.
*/
class Solution {
public:
    int solveMem(int n, vector<int>&dp){
        int mod = 1e9+7;
        //base case
        if(n == 1 || n == 2){
            return n;
        }
        if(n == 3){
            return 5;
        }

        //step3 if ans already present return it
        if(dp[n] != -1){
            return dp[n];
        }

        //step2 store ans in dp
        dp[n] = (2*solveMem(n-1, dp)%mod + solveMem(n-3, dp)%mod ) % mod;    //formula = 2*(n-1) + (n-3)

        return dp[n];
    }
    int numTilings(int n) {
        //step1 create a dp vector
        vector<int>dp(n+1, -1);
        return solveMem(n, dp);                         //n = traverse from last
    }
};
/*
Example 1:
Input: n = 3
Output: 5
Explanation: The five different ways are show above.

Example 2:
Input: n = 1
Output: 1
*/