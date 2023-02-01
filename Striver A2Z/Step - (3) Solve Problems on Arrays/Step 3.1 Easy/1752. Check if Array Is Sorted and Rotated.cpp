// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/


class Solution {
public:
    bool check(vector<int>& arr) {
        int min = arr[0];
        int rotated = false;
        int n=arr.size();
        if(n<=1)
            return true;
        for(int i=0;i<n-1;i++){
            if(arr[i+1]<arr[i])
            {
                i++;
                while(i<n-1)
                {
                    if(arr[i]>min || arr[i]>arr[i+1])
                        return false;

                    i++;
                }
                if(min<arr[n-1])
                    return false;
            }
        }
        return true;
    }
};