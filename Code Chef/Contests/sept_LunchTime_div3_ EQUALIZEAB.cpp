/*
https://www.codechef.com/LTIME112C/problems/EQUALIZEAB

*/

// solution 



// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(1)
// time complexity :  O(1)
void solution()
{
  int a,b,x;
  cin>>a>>b>>x;
  bool ans=(((a-b)%(2*x))==0)||(((b-a)%(2*x))==0);
    YorN(ans);
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
