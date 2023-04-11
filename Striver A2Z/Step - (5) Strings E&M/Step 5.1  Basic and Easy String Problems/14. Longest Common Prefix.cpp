// https://leetcode.com/problems/longest-common-prefix/description/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp ="";
        string ref = strs[0];
        for(int i=0;i<ref.length();i++){
            char refC = ref[i];
            for(int j=1;j<strs.size();j++){
                string curStr = strs[j];
                if(strs[j][i] != refC)
                    return lcp;
            }
            lcp+=refC;
        }
        return ref;
    }
};