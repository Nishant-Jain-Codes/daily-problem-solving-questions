// https://leetcode.com/problems/maximum-product-subarray/description/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int n = nums.size();
        int max_so_far = nums[0], min_so_far = nums[0];
        int max_prod = nums[0];
        for (int i = 1; i < n; i++) {
            int temp_max = max(nums[i], max(max_so_far * nums[i], min_so_far * nums[i]));
            min_so_far = min(nums[i], min(max_so_far * nums[i], min_so_far * nums[i]));
            max_so_far = temp_max;
            max_prod = max(max_prod, max_so_far);
        }
        return max_prod;
    }
};