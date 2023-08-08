int kDistinctChars(int k, string &str)
{
    // Write your code here
    vector<int> hash(26, 0);
    int ans = 0, i = 0, j = 0, distinct = 0;
    while(j<str.length()){
        hash[str[j]-'a']++;
        if(hash[str[j]-'a']==1)
            distinct++;
        if(distinct <= k){
            ans = max(ans, j-i+1);
            j++;
        }
        else if(distinct > k){
            while(distinct > k){
                hash[str[i]-'a']--;
                if(hash[str[i]-'a']==0)
                    distinct--;
                i++;
            }
            j++;
        }
    }
    return ans;
}


