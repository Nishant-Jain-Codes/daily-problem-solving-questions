class Node{
private:
    bool isEnd ;
    Node* children[26];
public:
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
private:
    Node* root;
    int unique;
public : 
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
int countDistinctSubstrings(string &s)
{
    //Your code here
    Trie trie;
    int unique = 1;
    for(int i=0;i<s.length();i++){
        string temp = "";
        for(int j=i;j<s.length();j++){
            temp+=s[j];
            trie.insert(temp);
        }
    }
    return trie.getUnique();
}