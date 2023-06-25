class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(3,-1));
        vector<int> output;
        return memoisation(nums,nums.size()-1,2,output,dp);
        return recursive(nums,nums.size()-1,2,output);
    }
private:
//brute force
    int recursive(vector<int> & nums , int idx , int count , vector<int> & output ){
        if(count == 0){
            if(output.size()<2)
                return 0;
            int cmp1 = to_string(output[1])[0]-'0';
            int cmp2 = to_string(output[0]).back()-'0';
            return __gcd(cmp1,cmp2)==1 ;
        }
        if(idx<0){
            return 0;
        }
        int ans = 0;
        for(int i=idx;i>=0;i--){
            output.push_back(nums[i]);
            ans += recursive(nums,i-1,count-1,output);
            output.pop_back();
        }
        return ans;
    }
int memoisation(vector<int> & nums , int idx , int count , vector<int> & output ,vector<vector<int>> & dp){
        
        if(count == 0){
            if(output.size()<2)
                return 0;
            int cmp1 = to_string(output[1])[0]-'0';
            int cmp2 = to_string(output[0]).back()-'0';
            return __gcd(cmp1,cmp2)==1 ;
        }
        if(idx<0||count<0)
                return 0;
        if(dp[idx][count]!=-1){
            return dp[idx][count];
        }
        if(idx<0){
            return 0;
        }
        int ans = 0;
        for(int i=idx;i>=0;i--){
            output.push_back(nums[i]);
            ans += memoisation(nums,i-1,count-1,output,dp);
            output.pop_back();
        }
        return dp[idx][count] = ans;
    }
};