vector<int> binaryQueries(int n, vector<int> &a, int q, vector<vector<int>> &queries) {
    // Write your code here.
    vector<int> ansToQueries;
    for(int i=0;i<q;i++){
        int l = queries[i][0];
        int r = queries[i][1];
        int x = queries[i][2];
        int ans = 0;
        for(int j=l;j<=r;j++){
            ans = ans| ( a[j] ^ x);
        }
        ansToQueries.push_back(ans);
    }
    return ansToQueries;
}
