class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        long long dividendLL = abs((long long)dividend);
        long long divisorLL = abs((long long)divisor);
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        long long quotient = 0;
        while(dividendLL >= divisorLL){
            //find the biggest multiple such that (divisor * multiple <= dividend)
            long long temp = divisorLL;
            long long multiple = 1;
            while(dividendLL >= (temp << 1)){
                //keep doubling the divisor until it is greater than dividend
                temp <<= 1;
                multiple <<= 1;
            }
            dividendLL -= temp;
            quotient += multiple;
        }
        return sign * quotient;
    }
};

// GETTING TLE ! ! ! ! ! ! ! ! ! !
class Solution
{
public:
    int divide(int dividendGiven, int divisorGiven)
    {
        long long dividend = dividendGiven;
        long long divisor = divisorGiven;
        int sign = 1;
        if (dividend < 0)
        {
            dividend *= -1;
            sign *= -1;
        }
        if (divisor < 0)
        {
            divisor *= -1;
            sign *= -1;
        }
        long long quotent = 0;
        while (dividend > 0)
        {
            dividend -= divisor;
            quotent = (quotent + 1);
        }
        if (dividend != 0)
            quotent--;
        if (quotent > INT_MAX)
        {
            if (sign == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }
        return quotent * sign;
    }
};