/*

https://www.codechef.com/START62C/problems/FINALSUM

*/

// linkers , defines , constants

#include <bits/stdc++.h>
using namespace std;
#define int             long long int
#define lb             lower_bound
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
    int t;
    cin>>t;
    while(t--)
    {
        solution();
     
    }
    return 0;
}
//CODE STARTS HERE-----------------------------------------------------------

// time complexity O(n)
// space complexity O(1)


void solution()
{
   int n,q;
   cin>>n>>q;
    int sum=0;
   for(int i=0;i<n;i++)
   {
    int in;cin>>in;
    sum+=in;
   }
   for(int i=0;i<q;i++)
   {
    int l,r;
    cin>>l>>r;
    if((l%2==0&&r%2==0)||(l%2!=0&&r%2!=0))
        sum++;
   }

   co(sum);
}


//CODE ENDS HERE----------------------------------------------------------------------------------------------