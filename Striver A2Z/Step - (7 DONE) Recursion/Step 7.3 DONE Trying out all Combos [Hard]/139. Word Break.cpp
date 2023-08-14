class Solution {
private: 
    bool dfs(int idx , string & s , unordered_set<string>&dict,vector<int> &dp){
        if(idx == s.size()){
            return true;
        }
        if(dp[idx]!=-1)
            return dp[idx];
        bool ans = false;
        for(int i=idx;i<s.size();i++){
            string temp = s.substr(idx, i-idx+1);
            if(dict.find(temp) != dict.end()){
                ans = ans || dfs(i+1, s, dict,dp);
            }
        }
        return dp[idx] = ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1,-1);
        unordered_set<string> dict;
        for(auto &word : wordDict){
            dict.insert(word);
        }
        if( dfs(0, s, dict,dp) == 1)
            return true;
        else 
            return false;
    }
};