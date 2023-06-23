// User function Template for C++

class Solution {
private:
    int memoisation(const string & s , int idx , vector<int> & dp){
        if(idx==s.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int ans = 1;
        for(int i=idx ; i<s.size();i++){
            if(i!=idx && s[i]==s[i-1]){
                continue;
            }
            ans += memoisation(s,i+1,dp);
        }
        return dp[idx] = ans;
    }

public:
    string betterString(string s1, string s2) {
        // code here
        string str1 = s1;
        string str2 = s2;
        sort(str1.begin(),str1.end());
        sort(str2.begin(),str2.end());
        vector<int> dp1 (str1.size(),-1);
        vector<int> dp2 (str2.size(),-1);
        int sol1 = memoisation(str1,0,dp1);
        int sol2 = memoisation(str2,0,dp2);
        //cout<<sol1<<" "<<sol2<<endl;
        if(sol1>=sol2){
            return s1;
        }
        return s2;
    }
};
