// https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_map<int,bool>map;
        int n = arr.size();
      for(int i=0;i<n;i++){
          map[arr[i]]=true;
      }
      int ans=0;
      for(auto x:map){
          if(map.find(x.first-1)==map.end()){
              int curNum = x.first;
              int curCnt = 1;
              while(map.find(curNum+1)!=map.end()){
                  curCnt++;
                  curNum++;
              }
              ans=max(ans,curCnt);
          }
      }
      return ans;
    }
};