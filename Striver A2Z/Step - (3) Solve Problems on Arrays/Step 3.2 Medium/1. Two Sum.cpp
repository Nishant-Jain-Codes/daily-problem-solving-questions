// https://leetcode.com/problems/two-sum/description/

    // !logic
    // store the array elements in the map
    // travers through array and check if X-arr[i] exists in the map 
    // if yes return the pair 


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um;
        for(int i =0;i<nums.size();i++)
        {
            if(um.count(nums[i])>0)
                    um[nums[i]]++;
            else 
                um[nums[i]]=1;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(um.count(k-nums[i])>0)
        }
    }
};