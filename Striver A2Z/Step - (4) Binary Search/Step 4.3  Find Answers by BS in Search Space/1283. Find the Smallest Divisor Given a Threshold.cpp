https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

class Solution {
public:
    int divSum(vector<int>& nums,int threshold,int divisor){
        int sum =0;
        for(auto x : nums){
            sum+= ceil((x*1.0)/divisor);
            if(sum>threshold)
                return false;
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo=1;
        int hi=1e7;
        while(hi-lo>1){
            int mid = (hi+lo)/2;
            if(divSum(nums,threshold,mid)){
                hi=mid;
            }
            else 
             {
                lo = mid+1;
             }   
        }
        if(divSum(nums,threshold,lo))
            return lo;
        if(divSum(nums,threshold,hi))
            return hi;
        return -1;
    }
};