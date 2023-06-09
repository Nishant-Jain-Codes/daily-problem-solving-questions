class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        vector<int> output;
        helper(0,0,nums,target,output,answer);
        return answer;
    }
private:
    void helper(int curIdx , int curSum , vector<int> & nums ,
                int target , vector<int> & output , vector<vector<int>> & answer){
        if(curSum == target){
            answer.push_back(output);
            return;
        }
        if(curIdx == nums.size()){
            return;
        }
        for(int i=curIdx ; i<nums.size();i++){
            if(i!= curIdx && nums[i]==nums[i-1]){
                continue;
            }
            if(curSum+nums[i]>target){
                break;
            }
            output.push_back(nums[i]);
            helper(i+1,curSum+nums[i],nums,target,output,answer);
            output.pop_back();
        }
    }
};