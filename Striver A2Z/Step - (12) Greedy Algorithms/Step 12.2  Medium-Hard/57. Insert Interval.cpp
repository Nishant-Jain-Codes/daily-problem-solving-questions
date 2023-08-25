class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty())
            return {newInterval};
        
        vector<vector<int>> newIntervals;
        int startTime = newInterval[0];
        int endTime = newInterval[1];
        
        int i = 0;
        while(i < intervals.size() && startTime > intervals[i][1]) {
            newIntervals.push_back(intervals[i]);
            i++;
        }
        
        while(i < intervals.size() && endTime >= intervals[i][0]) {
            startTime = min(startTime, intervals[i][0]);
            endTime = max(endTime, intervals[i][1]);
            i++;
        }
        
        newIntervals.push_back({startTime, endTime});
        
        while(i < intervals.size()) {
            newIntervals.push_back(intervals[i]);
            i++;
        }
        
        return newIntervals;
    }
};
