// https://leetcode.com/problems/majority-element/

class Solution {
public:
    //using Boyer-Moore Majority Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int candidate =-1;
        int votes = 0;
        for(int i=0;i<nums.size();i++){
            if(votes==0){
                candidate = nums[i];
                votes=1;
            }
            else{
                if(nums[i]==candidate)
                    votes++;
                else 
                    votes--;
            }
        }
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==candidate)
                cnt++;
        }
        if(cnt>nums.size()/2)
            return candidate;
        else 
            return -1;
    }
};