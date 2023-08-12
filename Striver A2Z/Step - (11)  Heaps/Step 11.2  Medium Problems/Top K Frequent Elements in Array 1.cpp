//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  struct compare{
        bool operator()(pair<int,int>&p1,pair<int,int>&p2){
            if(p1.second!=p2.second)
                return p1.second>p2.second;
            return p1.first>p2.first;
        }
    };
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        unordered_map<int,int> mp;
        for(int x : nums)
            mp[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        for(auto freqOfX : mp){
            pq.push({freqOfX.first,freqOfX.second});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> answer;
        while(!pq.empty()){
            answer.push_back(pq.top().first);
            pq.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends