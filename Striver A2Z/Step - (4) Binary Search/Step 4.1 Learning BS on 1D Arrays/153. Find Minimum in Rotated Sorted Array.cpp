// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/910732849/


class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int lo = 0;
        int hi = n-1;
        int curMin = arr[0];
        while(hi-lo>1){
            int mid = (hi+lo)/2;
            bool isLeftSorted = arr[mid]>= arr[lo];
            if(isLeftSorted){
                curMin = min(curMin,arr[lo]);
                lo=mid+1;
            }else{
                curMin = min(curMin,arr[mid]);
                hi=mid-1;
            }
        }
        return min(curMin,min(arr[lo],arr[hi]));
    }
};