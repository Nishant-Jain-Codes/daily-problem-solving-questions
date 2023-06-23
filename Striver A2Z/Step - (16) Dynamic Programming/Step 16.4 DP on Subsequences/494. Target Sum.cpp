class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return recursion(nums.size()-1, nums, target);
    }
private:
    int recursion(int idx , const vector<int> & nums , int target){
        if(idx < 0)
            return target == 0;
        int negative = recursion(idx-1,nums,target+nums[idx]);
        int positive =  recursion(idx-1,nums,target-nums[idx]);
        return positive + negative;
    }
};