long long baitAndSwitch(int n, vector<int> &a, int k, int m) {
    // Write your code here.
    vector<long long> diff(n,0);
    for(int i=0;i<n;i++){
        diff[i] = abs(a[i]-m);
    }
    sort(diff.begin(),diff.end(),greater<long long>());
    long long ans = 0;
    for(int i=0;i<k;i++){
        ans += diff[i];
    }
    return ans;
}
