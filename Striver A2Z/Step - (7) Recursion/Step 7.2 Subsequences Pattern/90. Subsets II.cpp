class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> output;
        sort(nums.begin(), nums.end());
        helper(nums, 0, output, answer);
        return answer;
    }
private:
    void helper(vector<int>&nums , int curIdx , vector<int>& output, vector<vector<int>>&answer){
        answer.push_back(output);
        for(int i = curIdx;i<nums.size();i++){
            if(i!=curIdx && nums[i] == nums[i-1]){
                continue;
            }
            output.push_back(nums[i]);
            helper(nums, i+1, output, answer);
            output.pop_back();
        }
    }
};