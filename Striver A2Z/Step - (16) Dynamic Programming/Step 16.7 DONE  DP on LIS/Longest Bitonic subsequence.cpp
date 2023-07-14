//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int LongestBitonicSequence(vector<int> nums)
    {
        // code here
        vector<int> lis = giveLis(nums,false);//not reversed
        vector<int> lds = giveLis(nums,true);//reversed
        // for(int i=0;i<nums.size();i++){
        //     cout<<lis[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<nums.size();i++){
        //     cout<<lds[i]<<" ";
        // }
        int ans = 1;
        for(int i=0;i<nums.size();i++){
            ans = max(ans,lis[i]+lds[i]-1);
        }
        return ans;
    }
private: 
    vector<int>  giveLis(vector<int> nums,bool reverseLis){
        vector<int> dp(nums.size(),1);
        if(reverseLis){
            reverse(nums.begin(),nums.end());
        }
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                int ai = nums[i];
                int aj = nums[j];
                if(ai>aj && dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
        }
        if(reverseLis){
            reverse(dp.begin(),dp.end());
        }
        return dp;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends