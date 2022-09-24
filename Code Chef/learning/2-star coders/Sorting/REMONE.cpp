/*

https://www.codechef.com/LP2TO302/problems/REMONE?tab=statement

*/


// solution 




// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(nlogn)
void solution()
{
  int n;cin>>n;
  int a[n],b[n-1];
  in(a,n);
  sort(a,a+n);
  in(b,n-1);
  sort(b,b+n-1);
  int x1=abs(b[n-2]-a[n-1]);//last element taken of a
  int x2=abs(b[n-2]-a[n-2]);//last not taken 
    unordered_map<int,int> A;
    for(int i=0;i<n;i++)
        A[a[i]]++;
    
    int x1freq=0;    
    int x2freq=0;    
    for(int i=0;i<n-1;i++)
    {
        if(A.count(b[i]-x1)>0)
            x1freq++;
    }
    for(int i=0;i<n-1;i++)
    {
        if(A.count(b[i]-x2)>0)
            x2freq++;
    }
    if(x1==0)
    {
        co(x2);return;
    }
    else if(x2==0)
    {
        co(x1);return;
    }
    if(x1freq>x2freq)
        {co(x1);}
    else if(x1freq<x2freq) 
        {co(x2);}
    else 
    {
        co(min(x1,x2));
    }
  }
//CODE ENDS HERE----------------------------------------------------------------------------------------------
