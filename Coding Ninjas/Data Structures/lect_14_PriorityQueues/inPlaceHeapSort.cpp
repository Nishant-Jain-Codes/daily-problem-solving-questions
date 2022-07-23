/*

Code : In-place heap sort
Send Feedback
Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
Note: Space complexity should be O(1).
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array or N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains array elements after sorting. The elements of the array in the output are separated by single space.
Constraints :
1 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1:
6 
2 6 8 5 4 3
Sample Output 1:
8 6 5 4 3 2

*/
// solution 


#include<bits/stdc++.h>
using namespace std;
void heapSort(int pq[], int n) {
if(n==0)
{
    return ;
}
// inserting array in min heap
    for(int i =1;i<n;i++)
    {
        
        int cI = i;
        //up heapyfy
        while(cI>0)
        {
            int pI = (cI-1)/2;
            if(pq[cI]<pq[pI])
            {
                swap(pq[cI],pq[pI]);
            }
            else
            {
                break;
            }
            cI=pI;
        }
    }
//   deleting array element in min heap
    int i=n;
    while(i>0)
    {
        swap(pq[0],pq[i-1]);
        i--;
        int pI=0;
        int lcI = 2*pI + 1;
        int rcI = 2*pI + 2;
        // down heapyify
        while(lcI<i)
        {
            int mI = pI;
            if(pq[mI]>pq[lcI])
            {
                mI=lcI;
            }
            if(rcI<i&&(pq[rcI]<pq[mI]))
            {
                mI=rcI;
            }
            if(mI==pI)break;
            swap(pq[pI],pq[mI]);
            pI=mI;
            lcI = 2*pI + 1;
            rcI = 2*pI + 2;
        }
    }
}
