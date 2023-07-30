class Solution {
public:
    int minCut(string s) {
        
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return memoization(s, 0, s.size()-1, dp);
        return recursion(s, 0, s.size()-1);
    }
private: 
    bool isPalindrome(string &s, int i , int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    int recursion(string &s, int i , int j){
        if(i>=j || isPalindrome(s, i, j)) 
            return 0;
        int ans = INT_MAX;
        for(int k = i+1;k<j;k++){
            int leftBreaks = recursion(s,i,k);
            int rightBreaks = recursion(s,k+1,j);
            ans = min(ans, leftBreaks + rightBreaks + 1);
        }
        return ans;
    }

    int memoization(string &s, int i , int j,vector<vector<int>> & dp){
        if(i>=j || isPalindrome(s, i, j)) 
            return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(j-i == 1) return dp[i][j] = 1;
        int ans = INT_MAX;
        for(int k = i+1;k<j;k++){
            int leftBreaks = memoization(s, i,k,dp);
            int rightBreaks = memoization(s,k+1,j,dp);
            ans = min(ans, leftBreaks + rightBreaks + 1);
        }
        return dp[i][j] = ans;
    }
};