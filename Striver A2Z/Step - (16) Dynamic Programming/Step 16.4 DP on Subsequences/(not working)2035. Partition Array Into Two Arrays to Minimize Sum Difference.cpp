// ! logical bug it is not making equal subarrays it is just making min difference there should be equal size too 

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        nt mostNeg = 0;
        for(int i=0;i<nums.size();i++){
            if(mostNeg>nums[i])
                mostNeg = nums[i];
        }
        for(int i=0;i<nums.size();i++){
            nums[i]+=abs(mostNeg);
        }
        return tabulation(nums.size(),nums);i
    }
private:
    int tabulation(int n , vector<int> & nums){
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        dp[0][nums[0]] = true;
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool notTake = dp[i-1][j];
                bool take = false;
                if(j-nums[i]>=0){
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j]= notTake || take;
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<=(sum+1)/2;i++){
            if(dp[n-1][i]){
                int s1 = i;
                int s2 = sum-i;
                ans = min(ans, abs(s1-s2));
            }
        }
        return ans;
    }
};