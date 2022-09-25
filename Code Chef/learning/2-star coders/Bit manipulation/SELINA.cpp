/*

https://www.codechef.com/LP2TO305/problems/SELINA?tab=statement

*/

// solution


// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(n)
void solution()
{
  string s;
  cin>>s;
    unordered_map<char,int> map;
    for(int i=0;i<s.size();i++)
    {
        map[s[i]]++;
    }
    for(int i=0;i<s.size();i++)
    {
        if(map[s[i]]%2!=0)
        {
            co(s[i]);
            return;
        }
    }
    co(-1);
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
