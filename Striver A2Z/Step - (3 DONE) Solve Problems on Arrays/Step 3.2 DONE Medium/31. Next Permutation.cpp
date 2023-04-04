// https://leetcode.com/problems/next-permutation/description/

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size();
        int idx1=-1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                idx1=i;
                break;
            }
        }
        if(idx1<0)
            reverse(arr.begin(),arr.end());
        else{
            int idx2 ;
            for(int i=n-1;i>idx1;i--){
                if(arr[i]>arr[idx1]){
                    idx2=i;
                    break;
                }
            }
            swap(arr[idx1],arr[idx2]);
            reverse(arr.begin()+idx1+1,arr.end());
        }
    }
};