// https://practice.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-days-to-make-m-bouquets

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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
            if(Kadj==M)
                return true;
        }
        return Kadj>=M;
    }
    
    int solve(int M, int K, vector<int> &bloomDay){
      // Code here
       if(bloomDay.size() < M*K)
        return -1;
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

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends