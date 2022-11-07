/*

Second Largest
Send Feedback
Take input a stream of n integer elements, find the second largest element present.
The given elements can contain duplicate elements as well. If only 0 or 1 element is given, the second largest should be INT_MIN ( - 2^31 ).
Input format :

Line 1 : Total number of elements (n)

Line 2 : N elements (separated by space)

Sample Input 1:
 4
 3 9 0 9
Sample Output 1:
 3
Sample Input 2 :
 2
 4 4
Sample Output 2:
 -2147483648
Sample Output Explanation:
Since both the elements are equal here, hence second largest element is INT_MIN i.e. ( -2^31 )

*/

// solution 

#include<iostream>

using namespace std;

int main ()
{
    int n;
    cin>>n;
    int max1=-2147483648;
    int max2=-2147483648;
    int in;
    for(int i = 1;i<=n;i++)
    {
        cin>>in;
        if(in>max1)
        {
            max2=max1;
            max1=in;
        }
        else if(in>max2&&in!=max1)
        {
            max2=in;
        }
    }
    cout<<max2;
    return 0;
}
