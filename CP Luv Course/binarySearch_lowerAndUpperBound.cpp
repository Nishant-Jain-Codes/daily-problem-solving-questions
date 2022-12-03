// linkers , defines , constants

#include <bits/stdc++.h>
using namespace std;
#define int             long long int
#define in(v,n)        for(int i=0;i<n;i++) cin>>v[i];
#define co(x)         cout<<x<<endl;
const string yes = "YES";
const string no = "NO";
void solution();
//===============SHORTCUT FUNCTIONS===================
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
void inVec(vector<int>&v,int &n)
{
    for(int i=0;i<n;i++)
    {
        int in;cin>>in;
        v.push_back(in);
    }
    return;
}
//=============MAIN FUNCTION===============
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
bool binarySearch(vector<int>&nums,int x)
{
    int lo=0,hi=nums.size()-1;
    while(hi-lo>1)
    {
        int mid = (hi-lo)/2;
        if(nums[mid]>x)
        {
            hi=mid-1;
        }
        else
        {
            lo=mid;
        }
    }
    if(nums[lo]==x||nums[hi]==x)
        return true;
    else 
        return false;
         

}
int upper_bound(vector<int>&nums , int x)
{
    int lo=0,hi=nums.size()-1;
    while(hi-lo>1)
    {
        int mid = (hi-lo)/2;
        if(nums[mid]<=x)
        {
            lo=mid+1;
        }
        else
        {
            hi=mid;
        }
    }
    if(nums[lo]>x)
        return lo;
    else if(nums[hi]>x)
        return hi;
    else 
        return -1;
}
int lower_bound(vector<int>&nums , int x)
{
    int lo=0,hi=nums.size()-1;
    while(hi-lo>1)
    {
        int mid = (hi-lo)/2;
        if(nums[mid]<x)
        {
            lo=mid+1;
        }
        else
        {
            hi=mid;
        }
    }
    if(nums[lo]>=x)
        return lo;
    else if(nums[hi]>=x)
        return hi;
    else 
        return -1;
}


void solution()
{
    int n;cin>>n;
    vector<int>vec;
    inVec(vec,n);
    int x;cin>>x;
    YorN(binarySearch(vec,x));
    co(lower_bound(vec,x));
    co(upper_bound(vec,x))
}

//CODE ENDS HERE----------------------------------------------------------------------------------------------