/*

Binary Search (Recursive)
Send Feedback
Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.
Note : If given array size is even, take first mid.
Input format :

Line 1 : Array size

Line 2 : Array elements (separated by space)

Line 3 : x (element to be searched)

Sample Input :
6
2 3 4 5 6 8 
5 
Sample Output:
3 

*/

// solution 

// input - input array
// size - length of input array
// element - value to be searched
int bshelper(int *arr , int si , int ei , int x)
{
    if(si>ei)
    {
        return -1; 
    }
    int mid = si +((ei-si)/2);
    if(arr[mid]>x)
    {
        bshelper(arr,si,mid-1,x);
    }
    else if(arr[mid]<x)
    {
        bshelper(arr,mid+1,ei,x);
    }
    else
    {
        return mid;
    }
}
int binarySearch(int input[], int size, int element) {
    // Write your code here
 return bshelper(input,0,size-1,element);
}
