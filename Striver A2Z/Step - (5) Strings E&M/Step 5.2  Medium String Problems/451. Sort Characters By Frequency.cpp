// https://leetcode.com/problems/sort-characters-by-frequency/description/

bool comp(pair<char,int> p1, pair<char,int> p2){
            if(p1.second == p2.second)
                return p1.first<p2.first;
            return p1.second > p2.second;
        }
class Solution {
public:
        
    string frequencySort(string s) {
        unordered_map<char,int> map;
        for(auto c : s){
            map[c]++;
        }
        vector<pair<char,int>> p;
        for(auto x : map){
            p.push_back({x.first,x.second});
        }
        sort(p.begin(),p.end(),comp);
        string ans="";
        for(auto x : p){
            for(int i=0;i<x.second;i++)
            {
                ans+=x.first;
            }
        }
        return ans;
    }
};