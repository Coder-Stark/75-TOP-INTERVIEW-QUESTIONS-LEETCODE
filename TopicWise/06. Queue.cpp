//QUEUE

#include<bits/stdc++.h>
using namespace std;

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