class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        vector<vector<int>> mergedIntervals;
        for (const vector<int>& interval : intervals) {
            if (mergedIntervals.empty() || interval[0] > mergedIntervals.back()[1]) {
                mergedIntervals.push_back(interval);
            } else {
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], interval[1]);
            }
        }
        
        return mergedIntervals;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
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