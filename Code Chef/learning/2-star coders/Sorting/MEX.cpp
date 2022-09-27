/*

https://www.codechef.com/LP2TO302/problems/MEX

*/

// solution 


// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(n)
void solution()
{
    int n,k;cin>>n>>k;
    unordered_map<int,bool> map;
    int MAX=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int in;cin>>in;
        map[in]=true;
        MAX=max(MAX,in);
    }
    vector<int> vec;
    for(int i=0;i<=MAX;i++)
    {
        if(map.count(i)<=0)
            vec.push_back(i);
    }
  if(k>=vec.size())
  { 
      int ans=(k-vec.size())+MAX+1;
      co(ans);
  }
  else 
  {
      int ans=vec[k];
      co(ans);
  }
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
