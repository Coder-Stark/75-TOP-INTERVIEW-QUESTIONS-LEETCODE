//TRIE

#include<bits/stdc++.h>
using namespace std;

//70.  IMPLEMENT TRIE (PREFIX TREE)                    {T.C = O(N + N), S.C = O(N*M {no. of word , lenghth of word})}
/*
//trie's main functions = insert, search, delete
//first we have to create a struct (isEndOfWord, child array)
//second we have to write function for creating new node for an trie
//initialize trieNode with root
//write for insert and with some upgradation search and startswith fucntion made
*/
class Trie {
public:
    struct trieNode{                   //basic requirement of trie is endofword and child
        bool isEndOfWord;
        trieNode *child[26];
    };

    trieNode *getNode(){              //for making newnode in trie
        trieNode* newNode = new trieNode();

        newNode->isEndOfWord = false;     //endofword should be false for new node
        for(int i = 0 ; i < 26 ; i++){
            newNode->child[i] = NULL;     //creating empty vector
        }
        return newNode;
    }

    trieNode* root;

    Trie() {
        root = getNode();
    }
    
    //if we create insert then search and starts with is just slight updation of code
    void insert(string word) {  //apple
        trieNode* crawler = root;             //crawler work as iterator
        for(int i = 0 ; i < word.length() ; i++){
            char ch = word[i];
            int idx = ch-'a';

            if(crawler->child[idx] == NULL){
                crawler->child[idx] = getNode();  //'a'
            }
            crawler = crawler->child[idx];       //move forward
        }
        crawler->isEndOfWord = true;      //'e' reach end
    }
    
    bool search(string word) {  //'apple'
        trieNode* crawler = root;             //crawler work as iterator
        for(int i = 0 ; i < word.length() ; i++){
            char ch = word[i];
            int idx = ch-'a';

            if(crawler->child[idx] == NULL){    //character in the word being searched for doesn't exist in the trie
                return false;
            }
            crawler = crawler->child[idx];       //move forward
        }
        if(crawler != NULL && crawler->isEndOfWord == true){  //'e'
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) { //'app'
        trieNode* crawler = root;             //crawler work as iterator
        int i = 0;
        for(i = 0 ; i < prefix.length() ; i++){    //same as search just word => prefix
            char ch = prefix[i];
            int idx = ch-'a';

            if(crawler->child[idx] == NULL){    //character in the word being searched for doesn't exist in the trie
                return false;
            }
            crawler = crawler->child[idx];       //move forward
        }
        if(i == prefix.length()){
            return true;
        }
        return false;
    }
};
/*
Example 1:
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]
Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
*/


//71. SEARCH SUGGESTIONS SYSTEMS
//USING SORTING AND BINARY SEARCH                                           {T.C = O(N*LOGN), S.C = O(N)}
/*
First sort the products, then iterate to searchword string prefix += it, find the index of lower_bound and store in start, push empty vector in ans
then iterate with condition(start ; atmost 3times && prefix match ; i++ ) , ans.back().push_back(prod) , initialize bsStart with start(for efficency)'
finally return ans.
*/
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>ans;
        sort(products.begin(), products.end());
        int n = products.size();
        int start = 0, bsStart = 0;
        string prefix;
        for(auto it : searchWord){
            prefix += it;
            start = lower_bound(products.begin()+bsStart, products.end(), prefix) - products.begin();  //gives index
            ans.push_back({});
            // it iterates at most three times && prefix of the product matches the current value of prefix
            for(int i = start ; i < min(start+3, n) && !products[i].compare(0, prefix.length(), prefix); i++){
                ans.back().push_back(products[i]);
            }
            bsStart = start;
        }
        return ans;
    }
};
/*
Example 1:
Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
After typing mou, mous and mouse the system suggests ["mouse","mousepad"].

Example 2:
Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Explanation: The only word "havana" will be always suggested while typing the search word.
*/
