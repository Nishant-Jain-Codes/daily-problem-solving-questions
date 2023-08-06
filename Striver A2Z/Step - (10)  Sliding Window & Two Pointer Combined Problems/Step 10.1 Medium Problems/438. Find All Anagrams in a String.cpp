class Solution {
public:
    vector<int> findAnagrams(string txt, string word) {
        vector<int> reqHash(26,0);
        for(int i=0;i<word.length();i++)
            reqHash[word[i]-'a']++;
        vector<int> hash(26,0);
        int i =0;
        int j = 0;
        int k = word.length();
        vector<int> ans;
        while(j<txt.length()){
            hash[txt[j]-'a']++;
            if(j-i+1<k)
                j++;
            else{
                for(int idx=0;idx<26;idx++){
                    if(hash[idx]!=reqHash[idx])
                        break;
                    if(idx==25)
                        ans.push_back(i);
                }
                hash[txt[i]-'a']--;
                i++;
                j++;
            }
        }
        return ans;
    }
};