// https://leetcode.com/problems/rotate-array/description/

class Solution {
public:
    void reverseArr(vector<int>& arr,int si,int ei){
        while(si<ei){
            swap(arr[si++],arr[ei--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        int n=nums.size();
        reverseArr(nums,0,n-k-1);
        reverseArr(nums,n-k,n-1);
        reverseArr(nums,0,n-1);
    }
};