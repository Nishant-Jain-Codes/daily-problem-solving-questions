https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution {
public:
    bool possible_to_ship(vector<int>& weights,int days,int weight){
        int cur_Weight=0;
        int cur_days=0;
        for(auto w : weights){
            if(w>weight)
                return false;
            if(cur_Weight+w > weight){
                cur_Weight=0;
                cur_days++;
            }
            cur_Weight+=w;
        }
        cur_days+=1;
        return cur_days<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = 1;
        int hi = 1e8;
        while(hi-lo>1){
            int mid = (hi+lo)/2;
            if(possible_to_ship(weights,days,mid)){
                hi=mid;
            }
            else 
            {
                lo=mid+1;
            }
        }
        if(possible_to_ship(weights,days,lo))
            return lo;
        if(possible_to_ship(weights,days,hi))
            return hi;
        return -1;
    }
};