class Solution {
public:
    bool isGood(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums){
            sum += num;
        }
        int n = nums.size();
        int reqSum = (n*(n+1)/2) + n;
        return sum == reqSum;
    }
};