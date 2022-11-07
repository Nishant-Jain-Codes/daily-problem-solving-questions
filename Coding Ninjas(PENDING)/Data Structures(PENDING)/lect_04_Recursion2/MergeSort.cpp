/*

Merge Sort Code
Send Feedback
Sort an array A using Merge Sort.
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
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 

*/

// solution 

void merge_two_sorted_array(int input[],int si,int mid,int ei)
{
    int *helper = new int[ei-si+1];//temp array
    
    int i=si;
    int j = mid+1;
    int k=0;
    while(i<=mid && j<=ei)
    {
        if(input[i]<=input[j])
        {
           helper[k]=input[i];
            i++;
            k++;
        }
        else
        {
            helper[k]=input[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
      helper[k]=input[i];
            i++;
            k++; 
    }
    while(j<=ei)
    {
        helper[k]=input[j];
            j++;
            k++;
    }
    int l=0;
    for(int i = si; i<=ei;i++)
    {
        input[i]=helper[l];
        l++;        
    }
    delete [] helper;
    return ;
}


void mergeSortHelper(int input[],int si,int ei)
{	
    int mid = si + ((ei-si)/2);
    
    if (si>=ei)
    {
        return ;
    }
    
    
    
    mergeSortHelper(input,si,mid);
    mergeSortHelper(input,mid + 1,ei);
    merge_two_sorted_array(input,si,mid,ei);
    return ;
}

void mergeSort(int input[], int size)
{
	mergeSortHelper(input,0,size-1);
        return ;
}
