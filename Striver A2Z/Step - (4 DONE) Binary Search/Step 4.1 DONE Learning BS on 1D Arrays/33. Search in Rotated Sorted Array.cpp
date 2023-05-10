// https://leetcode.com/problems/search-in-rotated-sorted-array/description/


class Solution {
public:
    int search(vector<int>& arr, int x) {
        int lo=0;
        int hi=arr.size()-1;
        while(hi-lo>1){
            int mid = (hi+lo)/2;
            if(arr[mid]==x)
                return mid;
            bool isLeftSorted = arr[mid]>=arr[lo];
            if(isLeftSorted){
                if(arr[lo]<=x && arr[mid]>=x)
                    hi=mid;
                else 
                    lo=mid+1;
            }
            else {
                if(arr[hi]>=x && arr[mid]<=x)
                    lo=mid;
                else 
                    hi=mid-1;
            }
        }
        if(arr[lo]==x)
            return lo;
        else if(arr[hi]==x)
            return hi;
        else 
            return -1;
    }
};