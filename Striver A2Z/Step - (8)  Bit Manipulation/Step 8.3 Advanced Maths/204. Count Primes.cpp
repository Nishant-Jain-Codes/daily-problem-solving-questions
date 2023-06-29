class Solution {
public:
    int countPrimes(int n) {
         // Write Your Code here
        vector<bool> isPrime(N+1,true);
        vector<int> ans ;
        int p=2;
        while(p*p<N){
            if(isPrime[p]){
                for(int i=p*p;i<N;i+=p){
                    isPrime[i]=false;
                }
            }
            p++;
        }
        for(int i=2;i<N;i++){
            if(isPrime[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};