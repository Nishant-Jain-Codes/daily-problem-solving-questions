class Solution {
public:
    // using bit masking
    vector<vector<int>> subsets(vector<int>& nums) {
        int totalSubsets = 1 << nums.size();
        vector<vector<int>> ans;
        for(int mask = 0;mask<totalSubsets;mask++){
            vector<int> subset;
            for(int i=0;i<nums.size();i++){
                if(mask & (1<<i)){
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};