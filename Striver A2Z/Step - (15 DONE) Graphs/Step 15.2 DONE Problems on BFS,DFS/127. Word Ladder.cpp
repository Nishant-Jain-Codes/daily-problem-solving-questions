// https://leetcode.com/problems/word-ladder/submissions/957565297/

class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set <string> dict(wordList.begin(), wordList.end());
        queue<pair<string,int>> q;
        q.push({startWord,1});
        dict.erase(startWord);
        while(!q.empty()){
            string curWord = q.front().first;
            int curDist = q.front().second;
            q.pop();
            for(int idx = 0;idx<curWord.length();idx++){
                string temp = curWord;
                for(char c = 'a';c<='z';c++){
                    temp[idx] = c;
                    if(dict.find(temp)!=dict.end()){
                        if(temp == targetWord){
                            return curDist+1;
                        }
                        q.push({temp,curDist+1});
                        dict.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};