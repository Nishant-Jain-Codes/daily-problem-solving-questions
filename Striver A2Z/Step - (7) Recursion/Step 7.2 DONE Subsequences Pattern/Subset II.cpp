//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> output;
        sort(nums.begin(), nums.end());
        helper(nums, 0, output, answer);
        return answer;
    }
private:
    void helper(vector<int>&nums , int curIdx , vector<int>& output, vector<vector<int>>&answer){
        answer.push_back(output);
        for(int i = curIdx;i<nums.size();i++){
            if(i!=curIdx && nums[i] == nums[i-1]){
                continue;
            }
            output.push_back(nums[i]);
            helper(nums, i+1, output, answer);
            output.pop_back();
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends