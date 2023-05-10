// https://leetcode.com/problems/koko-eating-bananas/description/


class Solution {
public:
bool canEat(int minB , vector<int>& piles, int N,int H){
       double h=0;
        for(int i=0;i<N;i++){
            h+= ceil(1.0*piles[i] / minB);
        }
        return h<=H;
    }   
    int minEatingSpeed(vector<int>& piles, int h) {
        int H = h;
        int N = piles.size();
        sort(piles.begin(),piles.end());
        int lo=0;
        int hi=1e9;
        while(hi-lo>1){
            int mid = (hi+lo)/2;
            if(canEat(mid,piles,N,H)){
                hi=mid;
            }
            else 
            {
                lo=mid+1;
            }
        }
        if(canEat(lo,piles,N,H))
            return lo;
        else if(canEat(hi,piles,N,H))
            return hi;
        else 
            return -1;
    }
};