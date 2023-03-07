// https://leetcode.com/problems/search-insert-position/description/

class Solution {
public:
    int searchInsert(vector<int>& Arr, int k) {
        int N = Arr.size();
        int lb=-1;
        int si=0,ei=N-1;
        while(si<=ei){
            int mid = si + ((ei-si)/2);
            if(Arr[mid]>k){
                ei=mid-1;
            }else if(Arr[mid]<k){
                lb=mid;
                si=mid+1;
                //cout<<lb<<" "<<Arr[mid]<<endl;
            }
            else 
                return mid;
        }
        return lb+1;
    }
};