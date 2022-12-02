// https://leetcode.com/problems/subsets/

vector<vector<int>>ans;
void generate(vector<int> &subSet,int idx,vector<int>&nums)
{
    if(idx==nums.size())
    {
        ans.push_back(subSet);
        return;
    }
    generate(subSet,idx+1,nums);//not considering
    subSet.push_back(nums[idx]);
    generate(subSet,idx+1,nums);//considering
    subSet.pop_back();
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<int>subSet;
    
        generate(subSet,0,nums);
        return ans;
    }