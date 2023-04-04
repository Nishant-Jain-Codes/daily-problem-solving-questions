// https://leetcode.com/problems/4sum/description/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int X) {
        int n = nums.size();
        long long int M  = 10e9;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int si = j+1;
                int ei = n-1;
                while(si<ei){
                    long long int sum = ((nums[i]+nums[j])%M +(nums[si]+nums[ei])%M)%M ;
                    if(sum<X)
                        si++;
                    else if(sum>X)
                        ei--;
                    else{
                        vector<int> quad {nums[i],nums[j],nums[si],nums[ei]};      
                        ans.push_back(quad);
                        while(si<ei && nums[si] == quad[2])
                        si++;
                        while(si<ei && nums[ei] == quad[3])
                        ei--;
                    }
                    
                }
                while(j<n-1 && nums[j+1]==nums[j])
                    j++;
            }
            while(i<n-1 && nums[i+1]==nums[i])
                    i++;
        }
        return ans;
    }
};