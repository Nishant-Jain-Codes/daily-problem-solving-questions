// https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>map;//preSum,freq
        map[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(map.count(sum-k)>0)
                ans+=map[sum-k];
            map[sum]++;
        }
        return ans;
    }
};