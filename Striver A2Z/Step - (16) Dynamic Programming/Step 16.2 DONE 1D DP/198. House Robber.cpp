class Solution {
private: 
int optimised(vector<int>& arr ,int n){
        if(n==0)
            return 0;
        vector<int> dp(n+1,-1);
        int prev2 = 0;
        int prev1 = arr[0];
        for(int i = 2 ; i <= n ; i++){
            int curr = max(prev1,arr[i-1]+prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        return optimised(nums,nums.size());
    }
};