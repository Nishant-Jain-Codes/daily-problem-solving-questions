// https://leetcode.com/problems/reverse-integer/description/
#include<bits/stdc++.h>
class Solution {
public:
    int reverse(int n) {
         int ans=0;
        while(n!=0){
            int pop = n%10;
            if (ans > INT_MAX/10 || (ans == INT_MAX / 10 && pop > 7)) return 0;
            if (ans < INT_MIN/10 || (ans == INT_MIN / 10 && pop < -8)) return 0;

            ans= ans*10 + pop;
             
            n/=10;
        }
        return ans;
    }
};