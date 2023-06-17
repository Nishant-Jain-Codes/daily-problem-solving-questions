vector<long long> countOperations(int n, vector<int> &a, long long x, int q, vector<vector<int>> &queries) {
    // Write your code here.
    vector<long long> result(q,0);
    long long sum =0;
    //calculate sum of A 
    for(int i=0;i<n;i++){
        sum += a[i];
    }
    for(int query = 0; query <q;query++){
        int index = queries[query][0];
        int value = queries[query][1];
        //update sum
        sum = sum - a[index] + value;
        a[index]= value;
        //calculate result
        if(sum!=0)
        result[query] = ceil(sum*1.0/x) ;
    }
    return result;

}
