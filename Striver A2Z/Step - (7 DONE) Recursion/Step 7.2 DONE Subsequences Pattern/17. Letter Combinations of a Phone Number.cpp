class Solution {
private:
    void recursive(int curIdx,const string & digits , unordered_map<char,string> & dict , vector<string> & ans){
        if(curIdx>=digits.size())
            return ;

        if(curIdx == digits.size()-1){
            vector<string> temp;
            string curVals = dict[digits[curIdx]];
            for(auto& ch : curVals){
                temp.push_back( string(1, ch));
            }
            ans = temp;
            return;
        }
        recursive(curIdx+1,digits,dict,ans);
        vector<string> temp;
        string curVals = dict[digits[curIdx]];
        for(auto & ch : curVals){
            for(auto & str : ans){
                temp.push_back(ch+str);
            }
        }
        ans = temp;
    }

public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> dict = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> ans;
        recursive(0, digits, dict, ans);
        return ans;
    }
};