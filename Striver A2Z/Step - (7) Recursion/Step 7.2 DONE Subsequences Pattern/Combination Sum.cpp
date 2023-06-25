//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        vector<int> output;
        set<int> digits = set<int>(nums.begin(),nums.end());
        nums = vector<int>(digits.begin(),digits.end());
        helperFunc(0,0,nums,target,output,answer);
        sort(answer.begin(),answer.end());
        return answer;
    }
private:
    
    void helperFunc(int curIdx , int curSum , vector<int> & nums ,int target , vector<int>& output, vector<vector<int>> & answer){
        if(curIdx==nums.size()){
            if(curSum==target){
                answer.push_back(output);
            }
            return;
        }
        if(curSum>target){
            return;
        }
        //picking current 
        output.push_back(nums[curIdx]);
        helperFunc(curIdx,curSum+nums[curIdx],nums,target,output,answer);
        output.pop_back();
        //not picking current
        helperFunc(curIdx+1,curSum,nums,target,output,answer);
    }
};
//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
        if(result.size()==0){
            cout<<"Empty";
        }
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends