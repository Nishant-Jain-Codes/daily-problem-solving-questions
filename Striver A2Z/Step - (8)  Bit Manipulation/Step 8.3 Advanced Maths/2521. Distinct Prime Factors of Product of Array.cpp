class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        vector<int> primes = sieve(1e4+10);
        unordered_set<int> s;
        for(auto no:nums){
            insertPrime(no,s,primes);
        }
        return s.size();
    }
private:
    void insertPrime(int no , unordered_set<int>& s, vector<int>& primes){
        for(int i=0;i<primes.size();i++){
            if(no%primes[i]==0){
                s.insert(primes[i]);
                while(no%primes[i]==0){
                    no/=primes[i];
                }
            }
        }
        if(no>1){
            s.insert(no);
        }
    }
    vector<int> sieve(int n){
        vector<int> isPrime(n+1,true);
        vector<int> ans;
        for(int i=2;i*i<=n;i++){
            if(isPrime[i]){
                ans.push_back(i);
                for(int j=i*i;j<=n;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        return ans;
    }
};