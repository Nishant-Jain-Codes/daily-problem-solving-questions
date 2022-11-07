/*

Quick Sort Code
Send Feedback
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 

*/

// solution 

int split(int input[],int si , int ei)
{
    int count = 0;
    for(int i = si+1; i<=ei;i++)
    {
        if(input[i]<=input[si])
        {
            count++;
        }
    }
    //swap 
    int temp = input[si + count];
    	input[si+count]=input[si];
    	input[si] = temp;
    
    int lidx=si;
    int ridx=ei;
    int mid = count + si;
    while(lidx<mid&&ridx>mid)
    {
        if(input[lidx]<=input[mid])
        {
            lidx++;
        }
        else if(input[ridx]>input[mid])
        {
            ridx--;
        }
        else
        {
            int temp=input[ridx];
            input[ridx]=input[lidx];
            input[lidx]=temp;
            ridx--;
            lidx++;
        }
    }
    return mid;
}


void QUICKSORT(int input[],int si,int ei)
{
    if(si>=ei)
    {
        return ;
    }
    int mid = split(input,si,ei);
    QUICKSORT(input,si,mid-1);
    QUICKSORT(input,mid+1,ei);
    return ;
    
}

void quickSort(int input[], int size) {
      
    QUICKSORT(input,0,size-1);
	return ;
}
