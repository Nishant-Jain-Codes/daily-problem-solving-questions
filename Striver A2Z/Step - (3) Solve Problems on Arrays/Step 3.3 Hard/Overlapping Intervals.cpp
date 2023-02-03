// https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=overlapping_intervals

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
         for(auto interval : intervals){
             pq.push(interval);
         }
         vector<vector<int>> ans;
         while(!pq.empty()&&pq.size()>1){
             vector<int> f = pq.top();
             pq.pop();
             vector<int> s = pq.top();
             if(f[1]>=s[0]){
                f[1]=max(f[1],s[1]);
                pq.pop();
                pq.push(f);
             }else
             {
                 ans.push_back(f);
             }
         }
         if(pq.size()==1)
         {
             ans.push_back(pq.top());
             pq.pop();
         }
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends