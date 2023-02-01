// https://leetcode.com/problems/majority-element-ii/description/

class Solution {
public:
// !O(1) using boyer moore voting algorithm
    vector<int> majorityElement(vector<int>& nums) {
        int c1=-1,c2=-1,v1=0,v2=0;
        for(int i=0;i<nums.size();i++){
             // if this element is previously seen,
        // increment count1.
        if (c1 == nums[i])
            v1++;
 
        // if this element is previously seen,
        // increment count2.
        else if (c2 == nums[i])
            v2++;
     
        else if (v1 == 0) {
            v1++;
            c1 = nums[i];
        }
 
        else if (v2 == 0) {
            v2++;
            c2 = nums[i];
        }
 
        // if current element is different from
        // both the previously seen variables,
        // decrement both the counts.
        else {
            v1--;
            v2--;
        }
        }
        v1=0;v2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==c1)
                v1++;
            else if(nums[i]==c2)
                v2++;
        }
        vector<int>ans;
        if(v1>nums.size()/3)
            ans.push_back(c1);
        if(v2>nums.size()/3)
            ans.push_back(c2);
        return ans;
    }
};