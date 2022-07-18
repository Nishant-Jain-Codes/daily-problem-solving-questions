/*

Return subsets sum to K
Send Feedback
Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :
Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Constraints :
1 <= n <= 20
Sample Input :
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output :
3 3
5 1

*/

// solution 

/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/
int helper(int input[], int size, int si,int output[][50], int k) 
{
    if(size==si)
    {
        if(k==0)
        {
            output[0][0]=0;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int twod1[10000][50];
    int twod2[10000][50];
    int sc1=helper(input,size,si+1,twod1,k);
    int sc2=helper(input,size,si+1,twod2,k-input[si]);

    for(int i=0;i<sc1;i++)
    {
        for(int j=0;j<=twod1[i][0];j++)
        {
            output[i][j]=twod1[i][j];
        }
    }
    
    for(int i=0;i<sc2;i++)
    {
        output[i+sc1][0]=1+twod2[i][0];
        output[i+sc1][1]=input[si];
        for(int j = 1 ; j<=twod2[i][0];j++)
        {
            output[i+sc1][j+1]=twod2[i][j];
        }
    }
    return sc1+sc2;
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
    
    return helper(input,n,0,output,k);

}
