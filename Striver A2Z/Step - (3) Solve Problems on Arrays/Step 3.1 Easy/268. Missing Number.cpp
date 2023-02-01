// https://leetcode.com/problems/missing-number/description/


class Solution {
public:
    int missingNumber(vector<int>& A) {
        long long int sum = 0;
        int N= A.size()-1;
    for(int i=0;i<=N;i++)
        sum+=A[i];
    long long int sumcheck = 0;
    N++;
    sumcheck = (N*(N+1))/2;
    return sumcheck-sum;
    }
};