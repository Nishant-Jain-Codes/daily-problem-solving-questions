class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto no : nums){
            ans = ans^no;
        }
        return ans;
    }
};