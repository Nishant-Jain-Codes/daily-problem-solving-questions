/*
https://www.codechef.com/LP2TO305/problems/ADDI
*/



// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(1)
// time complexity :  O(logn)
void solution()
{
  int n;cin>>n;
  int totalbits=0;
  int n1=n;
  while(n>0)
  {
      n/=2;
      totalbits++;
  }
  co(totalbits-__builtin_popcount(n1));
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
