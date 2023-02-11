// https://leetcode.com/problems/max-consecutive-ones/description/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int curCnt =0;
        for(auto x:nums){
            if(x==0){
                ans = max(ans,curCnt);
                curCnt=0;
            }else
                curCnt++;
        }
        ans = max(ans,curCnt);
        return ans;
    }
};