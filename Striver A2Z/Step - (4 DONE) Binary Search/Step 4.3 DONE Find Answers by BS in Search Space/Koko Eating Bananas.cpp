// https://practice.geeksforgeeks.org/problems/koko-eating-bananas/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=koko-eating-bananas
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canEat(int minB , vector<int>& piles, int N,int H){
        int h=0;
        for(int i=0;i<N;i++){
            h+= ceil(1.0*piles[i] / minB);
        }
        return h<=H;
    }
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
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

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends