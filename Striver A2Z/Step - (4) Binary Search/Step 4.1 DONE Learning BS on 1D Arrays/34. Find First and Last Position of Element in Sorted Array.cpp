https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
class Solution {
public:

    vector<int> searchRange(vector<int>& arr, int x) {
    int n=arr.size();
    int lb = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
    int ub = upper_bound(arr.begin(),arr.end(),x)-arr.begin();
    if(lb!=n && arr[lb]==x)
        return {lb,ub-1};
    else 
        return {-1,-1};
    }
};