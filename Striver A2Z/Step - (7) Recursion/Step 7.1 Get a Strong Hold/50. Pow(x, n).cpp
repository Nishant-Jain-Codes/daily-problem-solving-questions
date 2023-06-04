// https://leetcode.com/problems/powx-n/description/

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        
        long long exp = n;  // Convert n to long long to handle the edge case of n = -2147483648
        
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }
        
        return power(x, exp);
    }
    
private:
    double power(double x, long long n) {
        if (n == 0)
            return 1;
        
        double halfPower = power(x, n / 2);
        double result = halfPower * halfPower;
        
        if (n % 2 == 1) {
            result *= x;
        }
        
        return result;
    }
};
