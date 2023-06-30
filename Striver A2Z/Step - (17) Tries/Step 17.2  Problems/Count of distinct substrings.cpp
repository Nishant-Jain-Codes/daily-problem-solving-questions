//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends


// } Driver Code Ends

class Node{
public:
    bool isEnd ;
    Node* children[26];

    Node(){
        isEnd = false;
        for(int i=0;i<26;i++)
            children[i] = NULL;
    }
    void put(char ch , Node* node){
        children[ch-'a'] = node;
    }
    bool hasKey(char ch){
        return children[ch-'a'] != NULL;
    }
    Node* get(char ch){
        return children[ch-'a'];
    }
    void setIsEnd(){
        isEnd = true;
    }
    bool getIsEnd(){
        return isEnd;
    }
};
class Trie{
public : 
    Node* root;
    int unique;

    Trie(){
        root = new Node();
        unique = 1;
    }
    void insert(string s){
        Node* curr = root;
        for(int i=0;i<s.length();i++){
            if(!curr->hasKey(s[i])){
                curr->put(s[i],new Node());
            }
            curr = curr->get(s[i]);
        }
        if(curr->getIsEnd()==false){
            unique++;
        }
        curr->setIsEnd();
    }
    int getUnique(){
        return unique;
    }
};

/*You are required to complete this method */
/*You are required to complete this method */
int countDistinctSubstring(string s) {
    Trie trie;
    int unique = 1;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        Node* curr = trie.root;
        for (int j = i; j < n; j++) {
            int index = s[j] - 'a';
            if (curr->children[index] == NULL) {
                curr->children[index] = new Node();
                unique++;
            }
            curr = curr->children[index];
        }
    }

    return unique;
}
