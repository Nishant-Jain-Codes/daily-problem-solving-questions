https://leetcode.com/problems/3sum/description/


class Solution {
public:
    //O(N^2) time
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int targ = 0;
        for(int i=0;i<nums.size()-2;i++){
            int first = nums[i];
            int si = i+1;
            int ei = nums.size()-1;
            while(si<ei){

                if((nums[si]+nums[ei]+first) > targ){
                    ei--;
                }
                else if((nums[si]+nums[ei]+first) < targ){
                    si++;
                }
                else {  
                    vector<int> triplet {first , nums[si],nums[ei]};
                    ans.push_back(triplet);
                    while(si<ei && nums[si]==triplet[1])
                        si++;
                    while(si<ei && nums[ei]==triplet[2])
                        ei--;
                    
                }
            }
            while(i<nums.size()-1 && nums[i+1]==nums[i])
                i++;
        }
        return ans;
    }
};