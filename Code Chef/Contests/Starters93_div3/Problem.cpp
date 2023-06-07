#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long int
#define co(x) cout << x << endl
void yn(bool x){
    if(x)
        cout<<"YES"<<endl;
    else 
        cout<<"NO"<<endl;
}

void solve(){
    int n,m;
    cin>>n>>m;
    bool possible = false;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if((n-i+(3*j)) ==( m + i -j)){
                possible = true;
                break;
            }
        }
    }
    yn(possible);
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
    solve();
    }
    return 0;
}