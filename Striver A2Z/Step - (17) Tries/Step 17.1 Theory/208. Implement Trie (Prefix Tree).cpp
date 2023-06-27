class Trie {
    bool flag;
    Trie* next[26];
public:
    Trie() {
        flag = false;
        memset(next, NULL, sizeof(next));
    }
    // time complexity : O(n) 
    void insert(string word) {
        Trie * curNextArr = this;
        for(int i=0;i<word.length();i++){
            int charIdx = word[i] - 'a';
            if(curNextArr->next[charIdx] == NULL){
                curNextArr->next[charIdx] = new Trie();
            }
            if(i == word.length()-1){
                curNextArr->next[charIdx]->flag = true;
            }
            curNextArr = curNextArr->next[charIdx];
        }
    }
    // time complexity : O(n)
    bool search(string word) {
        Trie * curNextArr = this;
        for(int i=0;i<word.length();i++){
            int charIdx = word[i] - 'a';
            if(curNextArr->next[charIdx] == NULL){
                return false;
            }
            if(i == word.length()-1 && curNextArr->next[charIdx]->flag == false){
                return false;
            }
            curNextArr = curNextArr->next[charIdx];
        }
        return true;
    }
    // time complexity : O(n)
    bool startsWith(string prefix) {
        Trie * curNextArr = this;
        for(int i=0;i<prefix.length();i++){
            int charIdx = prefix[i] - 'a';
            if(curNextArr->next[charIdx] == NULL){
                return false;
            }
            curNextArr = curNextArr->next[charIdx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */