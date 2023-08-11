class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26, 0);
        int ans = 0 , i = 0 , j = 0;
        while(j<s.size()){
            hash[s[j]-'A']++;
            int flipReq = j-i+1 - *max_element(hash.begin(), hash.end());
            if(flipReq<=k){
                ans = max (ans, j-i+1);
            }
            else {
                hash[s[i]-'A']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};