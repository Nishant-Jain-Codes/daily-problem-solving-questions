// https://leetcode.com/problems/maximum-subarray/description/

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        int ans = arr[0];
         int sum=0;
         for(int i=0;i<n;i++){
             sum+=arr[i];
             ans = max(sum,ans);
             if(sum<0)
                sum=0;
         }
         return ans;
    }
};