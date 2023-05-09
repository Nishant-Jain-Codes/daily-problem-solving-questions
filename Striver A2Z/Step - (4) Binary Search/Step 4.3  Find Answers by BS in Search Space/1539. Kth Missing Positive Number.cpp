// https://leetcode.com/problems/kth-missing-positive-number/description/

class Solution {
public:
    bool sol(const unordered_set<int> & s,int cap,int k){
        int counter=0;
        for(int i=1;i<=cap;i++){
            if(s.find(i)==s.end())
                counter++;
        }
        return counter>=k;
    }
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> s;
        for(auto x : arr)
            s.insert(x);
        int lo = 0;
        int hi = 1e4;
        int ans = -1;
        while(lo<=hi){
            int mid = (hi+lo)>>1;
            if(sol(s,mid,k))
                {
                    ans = mid;
                    hi=mid-1;
                }
            else 
                lo=mid+1;
        }
        return ans;
    }
};