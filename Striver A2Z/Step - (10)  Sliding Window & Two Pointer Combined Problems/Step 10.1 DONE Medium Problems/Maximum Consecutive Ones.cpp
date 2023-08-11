//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) {
        // Code here
        int freq0 = 0, i = 0, j = 0, ans = 0;
        while(j<nums.size()){
            if(nums[j]==0)
                freq0++;
            if(freq0<=k){
                ans = max ( ans, j-i+1 );
                j++;
            }
            else {
                while(freq0>k){
                    if(nums[i]==0)
                        freq0--;
                    i++;
                }
                j++;
            }
        }
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
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends