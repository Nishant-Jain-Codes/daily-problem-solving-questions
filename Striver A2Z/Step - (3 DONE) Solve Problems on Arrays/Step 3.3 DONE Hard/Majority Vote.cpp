// https://practice.geeksforgeeks.org/problems/majority-vote/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=majority-vote


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code here
        unordered_map<int,int> m;
        for(auto x:nums)
            m[x]++;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(m[nums[i]] > n/3)
            {
                ans.push_back(nums[i]);
                m[nums[i]]=0;
            }
        }
        if(ans.empty())
            ans.push_back(-1);
        return ans;
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
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends