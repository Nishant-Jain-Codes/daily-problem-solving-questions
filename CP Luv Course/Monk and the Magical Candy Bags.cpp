// https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/?


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
// time complexity :  O(nlogn)
// space complexity : O(n)

void solution()
{
    int n,k;
    cin>>n>>k;
    multiset<int> m;
    for(int i=0;i<n;i++)
    {
        int in ;cin>>in;
        m.insert(in);
    }
    int ans=0;
    for(int i=0;i<k;i++)
    {
        auto last_it = (--m.end());
        ans+=(*last_it);
        m.insert((*last_it)/2);
        m.erase(last_it);
    }
    co(ans);
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------