/*

Geometric Sum
Send Feedback
Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
using recursion.
Input format :
Integer k
Output format :
Geometric sum (upto 5 decimal places)
Constraints :
0 <= k <= 1000
Sample Input 1 :
3
Sample Output 1 :
1.87500
Sample Input 2 :
4
Sample Output 2 :
1.93750
Explanation for Sample Input 1:
1+ 1/(2^1) + 1/(2^2) + 1/(2^3) = 1.87500

*/

// solution 

#include<math.h>

double geometricSum(int k) {
    if(k==0)
    {
        return 1;
    }
double second=geometricSum(k-1);
double first=1/(pow(2,k));
    return first + second;
}


