//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertNewEvent(int N, vector<vector<int>> &intervals, vector<int> &newEvent) {
        // code here
        if(intervals.empty())
            return {newEvent};
        int startTime = newEvent[0];
        int endTime = newEvent[1];
        int i = 0;
        vector<vector<int>> answer;
        while(i<intervals.size()&&startTime>intervals[i][1]){
            answer.push_back(intervals[i]);
            i++;
        }
        while(i<intervals.size() && endTime>=intervals[i][0]){
            startTime = min(startTime,intervals[i][0]);
            endTime = max(endTime,intervals[i][1]);
            i++;
        }
        answer.push_back({startTime,endTime});
        while(i<intervals.size()){
            answer.push_back(intervals[i]);
            i++;
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N,vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0]>>intervals[i][1];
        }
        vector<int> newEvent(2);
        cin>>newEvent[0]>>newEvent[1];
        
        Solution obj;
        vector<vector<int>> ans = obj.insertNewEvent(N, intervals,newEvent);
        cout<<"[";
        for(int i=0;i<ans.size();i++){
            cout<<"["<<ans[i][0]<<','<<ans[i][1]<<']';
            if(i!=(ans.size()-1)) cout<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
// } Driver Code Ends