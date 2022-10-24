/*

https://leetcode.com/problems/binary-search/

*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i= lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(i!=nums.size()&&nums[i]==target)
            return i;
        else 
            return -1;
        
    }
};