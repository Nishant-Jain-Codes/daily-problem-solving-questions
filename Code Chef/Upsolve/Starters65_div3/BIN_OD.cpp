// https://www.codechef.com/problems/BIN_OD?tab=statement

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
// time complexity :  O(n*60 +q)
// space complexity : O(n*60 +q)

void solution()
{
    int n,q;
    cin>>n>>q;
    vector<vector<int>> arr(60,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        int in;
        cin>>in;
        int k=0;
        //storing all the bits
        while(in>>k)
        {
            arr[k][i]=(in>>k)&1;
            k++;
        }
    }
    //computing prefix sum
    for(int k=0;k<60;k++)
    {
        for(int i=0;i<n;i++)
        {
            arr[k][i+1]+=arr[k][i];
        }
    }
    while(q--)
    {
        int k,l,r,L,R;
        cin>>k>>l>>r>>L>>R;
        int S1 = arr[k][r]-arr[k][l-1];
        int S2 = arr[k][R]-arr[k][L-1];
        int U1 = r-l+1-S1;
        int U2 = R-L+1-S2;
        int ans = (S1*U2)+(U1*S2);
        co(ans);
    }
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------