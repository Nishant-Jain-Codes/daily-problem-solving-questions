// https://leetcode.com/problems/split-array-largest-sum/description/

class Solution {
public:
    bool isPossible(vector<int> & nums, int k,int cap){
        int allocated = 1;
        int valAllocated = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>cap)
                return false;
            if(valAllocated + nums[i] > cap){
                allocated++;
                valAllocated = nums[i];
            }
            else {
                valAllocated += nums[i];
            }
            if(allocated>k)
                return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size())
            return -1;
        int lo = INT_MIN;
        int hi = 0;
        for(auto x : nums){
            lo = max(lo,x);
            hi += x;
        }
        int ans = -1;
        while(lo<=hi){
            int mid  = (hi+lo)>>1;
            if(isPossible(nums,k,mid)){
                ans = mid;
                hi=mid-1;
            }
            else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};