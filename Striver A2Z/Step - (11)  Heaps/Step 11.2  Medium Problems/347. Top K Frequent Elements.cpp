class Solution {
public:
    struct compare{
        bool operator()(pair<int,int>&p1,pair<int,int>&p2){
            return p1.second>p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int x : nums)
            mp[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        for(auto freqOfX : mp){
            pq.push({freqOfX.first,freqOfX.second});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> answer;
        while(!pq.empty()){
            answer.push_back(pq.top().first);
            pq.pop();
        }
        return answer;
    }
};