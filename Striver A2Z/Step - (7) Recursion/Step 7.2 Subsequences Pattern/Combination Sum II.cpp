//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        vector<int> output;
        helper(0,0,nums,target,output,answer);
        return answer;
    }
private:
    void helper(int curIdx , int curSum , vector<int> & nums ,
                int target , vector<int> & output , vector<vector<int>> & answer){
        if(curSum == target){
            answer.push_back(output);
            return;
        }
        if(curIdx == nums.size()){
            return;
        }
        for(int i=curIdx ; i<nums.size();i++){
            if(i!= curIdx && nums[i]==nums[i-1]){
                continue;
            }
            if(curSum+nums[i]>target){
                break;
            }
            output.push_back(nums[i]);
            helper(i+1,curSum+nums[i],nums,target,output,answer);
            output.pop_back();
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends