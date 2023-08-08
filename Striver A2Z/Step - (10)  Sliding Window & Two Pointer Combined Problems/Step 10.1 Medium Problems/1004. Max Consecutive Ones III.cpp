class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int freq0 = 0, i = 0, j = 0, ans = 0;
        while(j<nums.size()){
            if(nums[j]==0)
                freq0++;
            if(freq0<=k){
                ans = max ( ans, j-i+1 );
                j++;
            }
            else {
                while(freq0>k){
                    if(nums[i]==0)
                        freq0--;
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};