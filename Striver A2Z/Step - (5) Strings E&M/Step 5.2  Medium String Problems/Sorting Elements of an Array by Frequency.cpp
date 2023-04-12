// https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=sorting-elements-of-an-array-by-frequency

#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> p1, pair<int,int> p2){
    if(p1.second == p2.second)
        return p1.first< p2.first;
    return p1.second>p2.second;
}
void solution(vector<int>vec){
    unordered_map<int,int> map;
    for(auto x : vec)
        map[x]++;
    vector<pair<int,int>> p;
    for(auto x: map){
        p.push_back({x.first,x.second});
    }
    sort(p.begin(),p.end(),comp);
    for(auto x : p){
        
        for(int i=0;i<x.second;i++)
        {
            cout<<x.first<<" ";
            
        }
    }
    cout<<endl;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int size;
	    cin>>size;
	    vector<int> vec;
	    for(int i=0;i<size;i++){
	        int in;
	        cin>>in;
	        vec.push_back(in);
	    }
	    solution(vec);
	}
	return 0;
}