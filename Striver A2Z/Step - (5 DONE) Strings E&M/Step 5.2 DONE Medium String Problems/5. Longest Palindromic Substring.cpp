// https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s) {
        int res = 0;
        string ans = "";
        for(int i=0;i<s.length();i++){
            // checking for odd length
            int l = i;
            int r = i;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                if(r-l+1 > res){
                    res = r-l+1;
                    ans = s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
            //checking for even length
            l = i;
            r = i+1;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                if(r-l+1 > res){
                    res = r-l+1;
                    ans = s.substr(l,r-l+1);
                }
                l--;
                r++;
            }            
        }
        return ans;
    }
};