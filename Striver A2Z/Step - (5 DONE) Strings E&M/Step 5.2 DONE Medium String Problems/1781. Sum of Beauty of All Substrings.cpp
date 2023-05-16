// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/

class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            int freq[26] = {0};
            for(int j=i;j<s.length();j++){
                freq[s[j]-'a']++;
                int maxFreq=0;
                int minFreq=s.length();
                for(int k=0;k<26;k++){
                    if(freq[k]>0){
                        maxFreq=max(maxFreq,freq[k]);
                        minFreq=min(minFreq,freq[k]);
                    }
                }
                ans+=maxFreq-minFreq;
            }
        }
        return ans;
    }
};