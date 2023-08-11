class Solution {
public:
    //optimised
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> count(3, 0); 
        int ans = 0, i = 0, j = 0;

        for (j = 0; j < n; ++j) {
            count[s[j] - 'a']++;  
            while (count[0] && count[1] && count[2]) {
                count[s[i] - 'a']--; 
                i++;  
            }
            ans += i;  
        }

        return ans;
    }
    //tle ! O(N^2)
    int numberOfSubstrings(string s) {
        int a=0,b=0,c=0,ans=0,i=0,j=0;
        while(j<s.size()){
            char curChar = s[j];
            if(curChar=='a')a++;
            else if(curChar=='b')b++;
            else c++;
            if(c&&b&&a){
                int temp = i;
                int ta=a;
                int tb=b;
                int tc=c;
                while(temp<j && (ta>1||tb>1||tc>1)){
                    if(s[temp]=='a'&&ta>1)ta--;
                    else if(s[temp]=='b'&&tb>1)tb--;
                    else if(s[temp]=='c'&&tc>1) tc--;
                    else break;
                    temp++;
                }
                ans+=temp-i+1;
            }
            j++;
        }
        return ans;
    }
};