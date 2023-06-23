class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        return memoisation(nums,nums.size()-1,nums.size()/2,0,sum,dp);
        return recursion(nums,nums.size()-1,nums.size()/2,0,sum);//array , index, takenNumber, curSum, sum
    }
private: 
    //time complexity (2^n)  
    //space complexity (n) stack space
    int recursion(vector<int>& nums , int idx ,int canTake , int curSum , const int & sum ){
        if(idx<0 && canTake>0)
            return INT_MAX;
        if(idx<0 && canTake==0)
        {
            return abs((sum-curSum)-curSum);
        }

        int notTake = recursion(nums, idx-1, canTake, curSum , sum);
        int take = INT_MAX;
        if(canTake>0)
            take = recursion(nums, idx-1, canTake-1, curSum+nums[idx] , sum);
        return min(notTake, take);
    }
    //! not working ! 
    int memoisation(vector<int>& nums , int idx ,int canTake , int curSum , const int & sum , vector<vector<int>> &dp){

        if (idx < 0 && canTake > 0)
            return INT_MAX;
        if (idx < 0 && canTake == 0) {
            return abs((sum - curSum) - curSum);
        }

        if (dp[idx][canTake] != -1) {
            return dp[idx][canTake];
        }

        int notTake = memoisation(nums, idx - 1, canTake, curSum, sum, dp);
        int take = INT_MAX;
        if (canTake > 0)
            take = memoisation(nums, idx - 1, canTake - 1, curSum + nums[idx], sum, dp);

        return dp[idx][canTake] = min(notTake, take);
}
};