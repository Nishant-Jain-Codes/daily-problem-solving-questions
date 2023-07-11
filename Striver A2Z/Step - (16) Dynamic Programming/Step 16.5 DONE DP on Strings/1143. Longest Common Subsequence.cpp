class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return memoisation(text1.size()-1,text2.size()-1,text1,text2,dp);
    }
private:
    int memoisation(int i , int j , const string & s1, const string & s2,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j] = memoisation(i-1, j-1, s1, s2,dp) + 1;
        return dp[i][j] =  max(memoisation(i-1, j, s1, s2,dp), memoisation(i, j-1, s1, s2,dp));
    }
};