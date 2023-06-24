int outfitSelection(int n){
    // Write your code here
    int ans = 1;
    for(int i=n;i>n-2;n--){
        ans*=i;
    }
    return ans;
}