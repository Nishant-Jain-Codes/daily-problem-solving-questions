// https://leetcode.com/problems/word-ladder-ii/

class Solution {
    unordered_map<string,int> mpp;
    vector<vector<string>> ans;
    string b;
private:
    void dfs(string word, vector<string>  & seq){
        if(word == b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return ;
        }
        int curStep = mpp[word];
        for(int i =0;i<word.length();i++){
            char original = word[i];
            for(char c = 'a';c<='z';c++){
                word[i] = c;
                if(mpp.find(word)!=mpp.end() && mpp[word] == curStep -1){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        mpp[beginWord] = 1;
        dict.erase(beginWord);
        int wordLength = beginWord.length();
        while(!q.empty()){
            string curWord = q.front();
            int steps = mpp[curWord];
            q.pop();   
            if(curWord == endWord)
                break;         
            for(int i =0;i<wordLength;i++){
                char original = curWord[i];
                for(char c = 'a';c<='z';c++){
                    curWord[i] = c;
                    if(dict.count(curWord)){
                        q.push(curWord);
                        dict.erase(curWord);
                        mpp[curWord] = steps+1;
                    }
                }
                curWord[i] = original;
            }
        }
        if(mpp.find(endWord)!=mpp.end()){
            b=beginWord;
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
            
        return ans;
    }
};