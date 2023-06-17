int secretCode(int n, vector<int> &a) {
    // Write your code here.
    if(n<3) return 0;
    int sum = 0;
    for(int i=0;i<3;i++){
        sum += a[i];
    }
    if(sum%10 == 0) return 1;
    for(int i=3;i<n;i++){
        sum += a[i];
        sum -= a[i-3];
        if(sum%10 == 0) return 1;
    }
    return 0;
}
