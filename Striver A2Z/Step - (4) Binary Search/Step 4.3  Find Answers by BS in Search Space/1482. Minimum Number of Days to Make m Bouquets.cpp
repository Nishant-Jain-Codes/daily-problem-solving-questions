// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/



class Solution {
public:
bool minTime(int minT,int M,int  K ,vector<int> &bloomDay){
       int Kadj = 0;
        int curAdj =0;
        for(int i=0;i<bloomDay.size();i++){
           
            bool curTreeBloom = bloomDay[i]<=minT;
            if(curTreeBloom)
                curAdj++;
            else 
                curAdj=0;
             if(curAdj==K){
                Kadj++;
                curAdj=0;
            }
        }
        return Kadj>=M;
    }
    int minDays(vector<int>& bloomDay, int M, int K) {
        int lo=0;
        int hi=1e9;
        while(hi-lo>1)
        {
            int mid = (hi+lo)/2;
            if(minTime(mid,M,K,bloomDay)){
                hi=mid;
            }
            else {
                lo = mid+1;
            }
        }
        if(minTime(lo,M,K,bloomDay))
            return lo;
        else if(minTime(hi,M,K,bloomDay))
            return hi;
        else 
            return -1;
    }
};