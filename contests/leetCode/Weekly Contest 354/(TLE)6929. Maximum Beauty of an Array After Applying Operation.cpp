class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        return bruteForce2(nums,k);
    }
private:
    //tle
    int bruteForce(vector<int>& nums, int k){
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            for(int j=nums[i]-k;j<=nums[i]+k;j++){
                mp[j]++;
            }
        }
        int ans = INT_MIN;
        for(auto it:mp){ 
            ans = max(ans,it.second);
        }
        return ans;
    }
    //tle 
    int bruteForce2(vector<int>& nums, int k){
        unordered_map<int,int> freq;
        for(auto no:nums)
            freq[no]++;
        unordered_map<int,int> mp;
        for(auto nos:freq){
            int no = nos.first;
            int noFreq = nos.second;
            for(int j=no-k;j<=no+k;j++){
                mp[j]+= noFreq;
            }
        }
        int ans = INT_MIN;
        for(auto it:mp){ 
            ans = max(ans,it.second);
        }
        return ans;
    }
};