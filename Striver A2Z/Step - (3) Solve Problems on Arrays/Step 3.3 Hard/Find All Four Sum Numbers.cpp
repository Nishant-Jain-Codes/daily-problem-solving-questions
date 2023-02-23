// https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-all-four-sum-numbers


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int X) {
        // Your code goes here
        int n = nums.size();
        long long int M  = 10e9;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int si = j+1;
                int ei = n-1;
                while(si<ei){
                    long long int sum = ((nums[i]+nums[j])%M +(nums[si]+nums[ei])%M)%M ;
                    if(sum<X)
                        si++;
                    else if(sum>X)
                        ei--;
                    else{
                        vector<int> quad {nums[i],nums[j],nums[si],nums[ei]};      
                        ans.push_back(quad);
                        while(si<ei && nums[si] == quad[2])
                        si++;
                        while(si<ei && nums[ei] == quad[3])
                        ei--;
                    }
                    
                }
                while(j<n-1 && nums[j+1]==nums[j])
                    j++;
            }
            while(i<n-1 && nums[i+1]==nums[i])
                    i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends