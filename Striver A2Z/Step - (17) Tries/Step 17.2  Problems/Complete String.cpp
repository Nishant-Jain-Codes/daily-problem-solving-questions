#include <bits/stdc++.h> 
class TrieNode{
private:
    TrieNode *links[26];
    bool isEnd;
public:
    TrieNode(){
        isEnd = false;
        for(int i=0;i<26;i++){
            links[i] = NULL;
        }
    }
    void setEnd(){
        isEnd = true;
    }
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    TrieNode* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, TrieNode *node){
        links[ch-'a'] = node;
    }
    bool isEndTrue(){
        return isEnd;
    }
};
class Trie{
private:
    TrieNode *root;
public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string &word){
        TrieNode* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool hasWord(string &Word){
        TrieNode* node = root;
        for(int i=0;i<Word.length();i++){
            if(!node->containsKey(Word[i])){
                return false;
            }
            node = node->get(Word[i]);
        }
        return node->isEndTrue();
    }
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie trie;
    for(auto & word : a){
        trie.insert(word);
    }
    int ans = 0;
    string ansStr = "";
    for(int i=0;i<a.size();i++){
        bool hasAll = true;
        int count = 1;
        for(int j=0;j<a[i].length()-1;j++){
            string prefix = a[i].substr(0,j+1);
            if(!trie.hasWord(prefix)){
                hasAll = false;
                break;
            }
            count++;
        }
        if(hasAll){
            if(count > ans){
                ans = count;
                ansStr = a[i];
            }
            else if(count == ans){
                ansStr = min(ansStr, a[i]);
            }
        }
    }
    if(ansStr == "") ansStr = "None";
    return ansStr;
}