// https://leetcode.com/problems/isomorphic-strings/description/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> map,map2;
        if(s.length()!=t.length())
            return false;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            char c2 = t[i];
            if((map.find(c)!=map.end() && map[c] != c2) || map2.find(c2)!=map2.end()&&map2[c2]!=c)
                return false;
            else 
                {
                    map[c]=c2;
                    map2[c2]=c;
                }
        }
        return true;
    }
};