// https://leetcode.com/problems/roman-to-integer/description/

class Solution {
public:
    int romanToInt(string s) {
    unordered_map<char,int> val= {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };
    if(s.length()==0)
        return 0;
    int ans =val[s[s.length()-1]];
    for(int i=s.length()-1;i>0;i--){
        if(val[s[i]]>val[s[i-1]])
            ans -= val[s[i-1]];
        else 
            ans += val[s[i-1]];
    }
    return ans;
}
};