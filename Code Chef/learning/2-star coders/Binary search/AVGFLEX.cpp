/*

https://www.codechef.com/LP2TO303/problems/AVGFLEX

*/


// solution 


// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(n^2)
void solution()
{
    int n;
    cin>>n;
    int a[n];
    in(a,n);
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int G=n;
        int S=0;
        for(int j=0;j<n;j++)
        {
            if(a[j]<=a[i])
                {
                    S++;
                    G--;
                }
            else 
                break;
        }
        if(S>G)
        ans++;
    }
co(ans);
    
  
  
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
