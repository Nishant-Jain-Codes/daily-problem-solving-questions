/*
Problem
Chef has two numbers AA and BB.

In one operation, Chef can choose either AA or BB and multiply it by 22.

Determine whether he can make both AA and BB equal after any number (possibly, zero) of moves.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of two space-separated integers AA and BB.
Output Format
For each test case, output YES if Chef can make both numbers equal, NO otherwise.

Note that the checker is case-insensitive i.e. YES, Yes, yes, yES are all considered same.

Constraints
1 \leq T \leq 25001≤T≤2500
1 \leq A, B \leq 501≤A,B≤50
Sample 1:
Input
Output
4
5 20
6 6
12 2
50 20
YES
YES
NO
NO
Explanation:
Test case 11: Chef can multiply AA by 22 twice and both AA and BB will become 2020.

Test case 22: Both numbers are already equal.

Test case 33: It can be shown that AA and BB cannot be made equal.

Test case 44: It can be shown that AA and BB cannot be made equal.
*/

// solution 

#include <bits/stdc++.h>
using namespace std;
bool is_Double(int z,int t){
    if(z==t){
        
        return true;
    }
    else if(t>z){
        return false;
    }
    else {
    bool d=is_Double(z,t*2);
    return d;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int z=max(a,b);
        int t=min(a,b);
       bool f=is_Double(z,t);
    if(!is_Double(z,t)){
        cout<<"NO"<<endl;
    }
    else {
        cout<<"YES"<<endl;
    }
}
}
