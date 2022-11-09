// https://www.codechef.com/START64C/problems/DIVIDEMAKEEQ

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

void solution ()
{
    int n;cin>>n;
    int arr[n];
    in(arr,n);
    int noOfOne = 0;
    int m = arr[0];
    int j=0;
    unordered_map<int,bool> map;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
            noOfOne++;
        if(arr[i]<m)
        {
            m = arr[i];
            j=i;
        }
        map[arr[i]] = true;
    }
    swap(arr[0],arr[j]);
    int ans =0;
    if(noOfOne>0)
    {
        ans = n - noOfOne;
    }
    else if(map.size()==1)
    {
        ans=0;
    }
    else 
    {
        int sameGCD = 0;
        bool diffGDC = false;
        for(int i=1;i<n;i++)
        {

            int gcd = __gcd(m,arr[i]);
            //cout<<arr[i]<<" "<<m<<" "<<gcd<<endl;
            if(gcd==m)
                {
                    if(arr[i]!=m)
                    {
                        sameGCD++;
                    }
                }
            else 
            {
                diffGDC=true;

                co(n);
                return ;
            }
        }
        co(sameGCD);
        return;

    }
co(ans);
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------