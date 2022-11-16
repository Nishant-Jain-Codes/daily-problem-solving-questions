// https://www.codechef.com/START65C/problems/CNDY

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
   int n;
   cin>>n;
   unordered_map<int,int> map;
   for(int i=0;i<2*n;i++)
   {
    int in ;cin>>in;
    map[in]++;
   }
   int one = 0;
   int oneP=0;
   int two=0;
   for(auto x:map)
   {
    if(x.second>2)
        oneP++;
    else if(x.second==2)
        two++;
    else if(x.second==1)
        one++;

   }
   YorN((one+oneP+(2*two))/n==2);
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------