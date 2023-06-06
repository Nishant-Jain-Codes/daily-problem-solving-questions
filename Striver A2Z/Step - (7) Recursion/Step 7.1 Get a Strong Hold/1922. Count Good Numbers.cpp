// https://leetcode.com/problems/count-good-numbers/

class Solution {
private:
    const int MOD = 1e9 + 7;

    long long power(long long x, long long n) {
        if (n == 0)
            return 1;

        long long halfPower = power(x, n / 2) % MOD;
        long long result = (halfPower * halfPower) % MOD;

        if (n % 2 == 1)
            result = (result * x) % MOD;

        return result;
    }

public:
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long evenSol = power(5, even);
        long long oddSol = power(4, odd);

        long long result = (evenSol * oddSol) % MOD;

        return result;
    }
};
