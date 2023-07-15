
long long xySubstring(string s){
    long long ans = 0;
    int i=0;
    while(i<s.length()){
        int count = 0;
        while((s[i]=='x' || s[i]=='y') && i<s.length()){
            count++;
            i++;
        }
        ans += (count*(count+1)/2);
        i++;
    }
    return ans;
}