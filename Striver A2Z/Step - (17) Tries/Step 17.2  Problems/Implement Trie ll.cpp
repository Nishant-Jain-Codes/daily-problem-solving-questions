#include <bits/stdc++.h> 
class Node{

    Node *links[26];
    int countEnd;
    int countPrefix;
public:
    Node(){
        countEnd = 0;
        countPrefix = 0;
        for(int i = 0; i < 26; i++){
            links[i] = NULL;
        }
    }
    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    Node *get(char ch){
        return links[ch - 'a'];
    }
    void put(char ch, Node *node){
        links[ch - 'a'] = node;
    }
    void increaseEnd(){
        countEnd++;
    }
    void increasePrefix(){
        countPrefix++;
    }
    void reducePrefix(){
        countPrefix--;
    }
    void reduceEnd(){
        countEnd--;
    }
    int getCountEnd(){
        return countEnd;
    }
    int getCountPrefix(){
        return countPrefix;
    }
};
class Trie{
    Node *root;
    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            if(!curr->containsKey(word[i])){
                curr->put(word[i],new Node());
            }
            curr = curr->get(word[i]);
            curr->increasePrefix();
            
        }
        curr->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            if(!curr->containsKey(word[i])){
                return 0;
            }
            curr = curr->get(word[i]);
        }
        return curr->getCountEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            if(!curr->containsKey(word[i])){
                return 0;
            }
            curr = curr->get(word[i]);
        }
        return curr->getCountPrefix();
    }

    void erase(string &word){
        // Write your code here.
        if(!countWordsEqualTo(word))
            return ;
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            
            curr = curr->get(word[i]);
            curr->reducePrefix();
        }
        curr->reduceEnd();
    }
};
