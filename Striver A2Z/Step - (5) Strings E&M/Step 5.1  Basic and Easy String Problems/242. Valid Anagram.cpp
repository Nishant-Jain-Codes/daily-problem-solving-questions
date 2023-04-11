// https://leetcode.com/problems/valid-anagram/description/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> sMap,tMap;
        for(auto c : s){
            sMap[c]++;
        }
        for(auto c : t){
            tMap[c]++;
        }
        for(auto x : sMap){
            if(x.second != tMap[x.first])
                return false;
        }
        for(auto x : tMap){
            if(x.second != sMap[x.first])
                return false;
        }
        return true ;
    }
};