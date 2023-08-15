class Solution {
public:
    bool canJump(vector<int>& nums) {
        return greedySolution(nums);
        vector<int>dp(nums.size(),-1);
        return recursion(0,nums,dp);
    }
private:    
    bool greedySolution(vector<int>& nums){
        int maxReach = 0;
        for(int i=0;i<nums.size();i++){
            if(i>maxReach)
                return false;
            maxReach = max(maxReach , i+nums[i]);
            if(maxReach>=nums.size())
                return true;
        }
        return true;
    }
    bool recursion(int curIdx , vector<int>& nums,vector<int>&dp){
        if(curIdx>=nums.size())
            return false;
        if(curIdx==nums.size()-1)
            return true;
        if(dp[curIdx]!=-1)
            return dp[curIdx];
        int jumpLen = nums[curIdx];
        bool ans = false;
        if(jumpLen == 0)
            return false;
        for(int i=1;i<=jumpLen;i++){
            ans = ans || recursion(curIdx+i,nums,dp);
        }
        return dp[curIdx] = ans;
    }
};