//LINKED LIST

#include<bits/stdc++.h>
using namespace std;

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
