#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mPro=0;//maximum profit
        int mPri=INT_MAX;//minimum price
        for(auto x:prices){
            mPri = min(mPri,x);
            mPro = max(mPro,x-mPri);
        }
    return mPro;
}