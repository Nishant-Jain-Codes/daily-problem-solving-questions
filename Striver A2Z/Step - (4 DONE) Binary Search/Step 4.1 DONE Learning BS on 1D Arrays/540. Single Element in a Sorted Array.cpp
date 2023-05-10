// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        if(n==1)
            return arr[0];
        int lo=0;
        int hi=n-1;
        while(lo<=hi){
            int mid = (hi+lo)/2;
            if(mid==0 && arr[0]!=arr[1])
                return arr[0];
            if(mid==n-1 && arr[n-1]!=arr[n-2])
                return arr[n-1];
            if(arr[mid]!=arr[mid-1]&&arr[mid]!=arr[mid+1])
                    return arr[mid];
            int foundIdx = arr[mid]==arr[mid+1]?mid+1:mid;
            if((foundIdx+1)%2==0){
                lo=mid+1;
            }
            else {
                hi=mid-1;
            }
            
        }  
        return arr[lo];
    }
};