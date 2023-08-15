class Solution {
public:
    int jump(vector<int>& nums) {
        return greedySolution(nums);
        return bruteForceRecursive(nums);
    }
private:    
    int greedySolution(vector<int>& nums){
        int jumps=0,currEnd=0,currFarthest=0;
        for(int i=0;i<nums.size()-1;i++){
            currFarthest = max(currFarthest,i+nums[i]);
            if(i==currEnd){
                jumps++;
                currEnd = currFarthest;
            }
        }
        return jumps;
    }
private:
    int bruteForceRecursive(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        return recursion(0,nums,dp);
    }
    int recursion(int index,vector<int>&nums,vector<int>& dp){
        if(index>=nums.size()-1)
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int ans = 1e9;
        for(int i=1;i<=nums[index];i++){
            ans = min(ans,1+recursion(index+i,nums,dp));
        }
        return dp[index] = ans;
    }
};