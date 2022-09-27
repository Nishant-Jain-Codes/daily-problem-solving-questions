/*
https://www.codechef.com/LP2TO302/problems/EQDIFFER

*/



// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(n)
void solution()
{
  int n ;
  cin>>n;
  unordered_map<int,int> map;
  for(int i=0;i<n;i++)
  {
      int in ;cin>>in;
      map[in]++;
  }
    int mUnq=INT_MIN;
    
    for(auto x:map)
    {
        mUnq=max(mUnq,x.second);
    }
    if(n<=2||mUnq==n)
        {
            co(0);
        }
    else 
    {
        if(mUnq>1)
        {
            co(n-mUnq);
        }
        else 
        {
            co(n-2);
        }
    }
  
  
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
