// https://www.codechef.com/START67C/problems/COUNTP


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
// time complexity :  O(n)
// space complexity : O(n)

void solution()
{
    int n;cin>>n;
    int e=0,o=0;
    for(int i=0;i<n;i++)
    {
        int in;cin>>in;
        if(in%2==0)
            e++;
        else 
            o++;
    }
     bool ans=true;
    if(n>2&&o<2)
        ans=false;
    if(o%2!=0)
        ans=false;
    YorN(ans);
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------