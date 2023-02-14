// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mPro=0;//maximum profit
        int mPri=INT_MAX;//minimum price
        for(auto x:prices){
            mPri = min(mPri,x);
            mPro = max(mPro,x-mPri);
        }
        return mPro;
    }
};