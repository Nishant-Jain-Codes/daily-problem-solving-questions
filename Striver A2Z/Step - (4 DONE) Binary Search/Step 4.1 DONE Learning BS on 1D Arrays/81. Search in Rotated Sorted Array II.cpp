// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

class Solution {
public:
    bool search(vector<int>& arr, int x) {
        int n = arr.size();
        int lo=0;
        int hi=n-1;
        while(hi>=lo){
            int mid = (hi+lo)/2;
            if(arr[mid]==x)
                return true;
            if(arr[lo]==arr[mid] && arr[hi] == arr[mid]){
                lo++;
                hi--;
            }
            else if(arr[mid]>=arr[lo]){
                if(arr[mid]>=x && x>=arr[lo])
                    hi=mid-1;
                else 
                    lo = mid+1;
            }
            else {
                if(arr[mid]<=x && arr[hi]>= x)
                    lo = mid+1;
                else 
                    hi = mid-1;
            }
        }
        return false;
    }
};