/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        while(i<nums.size()-1)
        {
            if(nums[i]==nums[i+1])
            {   
                nums.erase(nums.begin()+i);
            }
            else 
                i++;
        }
        return nums.size();
    }
};