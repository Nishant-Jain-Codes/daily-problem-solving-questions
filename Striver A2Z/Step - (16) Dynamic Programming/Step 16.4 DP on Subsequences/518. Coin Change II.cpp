class Solution {
private: 
    long long int memoisation(int idx , int sum , vector<int>& coins,vector<vector<long long int>>& dp){
        if(idx<0){
            return sum==0;
        }
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        long long int notTake = memoisation(idx-1,sum,coins,dp);
        long long int take = 0;
        if(sum-coins[idx]>=0){
            take = memoisation(idx,sum-coins[idx],coins,dp);
        }
        return dp[idx][sum] = notTake+take;
        
    }
public:
    int change(int sum, vector<int>& coins) {
        int N = coins.size();
        vector<vector<long long int>> dp(N,vector<long long int>(sum+1,-1));
        return memoisation(N-1,sum,coins,dp);
    }
};