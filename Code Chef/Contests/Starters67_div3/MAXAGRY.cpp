// https://www.codechef.com/START67C/problems/MAXAGRY

// linkers , defines , constants

#include <bits/stdc++.h>
using namespace std;
#define int             long long int
#define in(v,n)        for(int i=0;i<n;i++) cin>>v[i];
#define co(x)         cout<<x<<endl;
const string yes = "YES";
const string no = "NO";
void solution();
void YorN(bool ans)
{
    if(ans)
        {
            co(yes);
            
        }
    else 
        {
            co(no);
        }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    // your code goes here
    int t;
    cin>>t;

    while(t--)
    {
        solution();
     
    }
    return 0;
}




// CODE STARTS HERE-------------------------------------------------------------------------------------------
// time complexity :  O(1)
// space complexity : O(1)

void solution()
{
    int n,k;
    cin>>n>>k;
    int ans;
    if(n==1)
        ans=0;
    else 
    {
        if(k>(n/2))
            k=n/2;
        int m = (n*(n-1))/2;
        int b = ((n-k)*(n-k-1))/2;
        int a = (n-(k*2))*k;
        int c = (k*(k-1))/2;
        ans = m-b+a+c;
        
    }

     co(ans);

}
//CODE ENDS HERE----------------------------------------------------------------------------------------------