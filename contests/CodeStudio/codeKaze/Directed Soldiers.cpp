int sol(int n , vector<int> & arr){
    int ans  = 0;
    bool found1 = false;
    for(int i=0;i<n;i++){
        if(arr[i] == 1){
            found1 = true;
        }else if (arr[i] == 0 && found1 == true){
            ans++;
        }
        
    }
    return ans;
}
int sol2(int n , vector<int>& arr){
    int ans  = 0;
    bool found0 = false;
    for(int i=n-1;i>=0;i--){
        if(arr[i] == 0){
            found0 = true;
        }else if (arr[i] == 1 && found0== true){
            ans++;
        }
        
    }
    return ans;
}
int directedSoldiers(int n, vector<int> &a) {
    // Write your code here.
    return min(sol(n,a),sol2(n,a));

}
