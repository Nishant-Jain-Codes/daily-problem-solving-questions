//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        int count=0,ans=0,i=0,j=0;
        while(j<nums.size()){
            count+= nums[j]%2==0 ? 0 : 1;
            while(i<j && count>k){
                count-=nums[i]%2==0 ? 0 : 1;
                i++;
            }
            if(count==k){
                int temp = i;
                while(temp<=j && nums[temp]%2==0){
                    temp++;
                }
                ans+=temp-i+1;
            }
            j++;
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
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends