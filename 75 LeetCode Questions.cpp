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