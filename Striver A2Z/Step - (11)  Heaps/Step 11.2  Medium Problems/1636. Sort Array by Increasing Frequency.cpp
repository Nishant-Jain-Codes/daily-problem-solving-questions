class Solution {
public:

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x : nums)
            mp[x]++;
        vector<pair<int,int>> parr;
        for(auto x:mp){
            parr.push_back({x.second,x.first});//freq,no
        }
        sort(parr.begin(),parr.end(),[&](pair<int,int> & p1, pair<int,int> &p2){
                if(p1.first == p2.first)
                    return p1.second>p2.second;
                else
                    return p1.first<p2.first;
            });
        vector<int>answer;
        for(auto p : parr){
            int freq = p.first;
            int no = p.second;
            while(freq){
                answer.push_back(no);
                freq--;
            }
        }
        return answer;
    }
};