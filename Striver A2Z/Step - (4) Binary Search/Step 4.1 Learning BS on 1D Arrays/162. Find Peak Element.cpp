// https://leetcode.com/problems/find-peak-element/description/

class Solution {
public:
    //O(N) complexity
    // int findPeakElement(vector<int>& nums) {
    //     for(int i=0;i<nums.size();i++){
    //         if((i-1==-1||nums[i-1]<nums[i])&&(i+1==nums.size()||nums[i+1]<nums[i]))
    //             return i;
    //     }
    //     return -1;
    // }
    
    int findPeakElement(vector<int>& arr){
        int n = arr.size();
        int lo = 0;
        int hi = n-1;
        while(hi-lo>1){
            int mid = (hi+lo)/2;
            if(mid==0)
                return arr[0]>arr[1]? 0:1;
            if(mid==n-1)
                return arr[n-1]>arr[n-2]? n-1:n-2;
            if(arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1])
                return mid;
            if(arr[mid]<arr[mid-1])
                hi=mid-1;
            else 
                lo = mid+1;
        }
        if(arr[lo]>arr[hi])
            return lo;
        else 
            return hi;
    }
};