// https://leetcode.com/problems/reverse-pairs/description/

class Solution {
public:
 long long int merge(vector<int>& arr,long long  si,long long mid ,long long ei){
         long long *tempArr = new long long[ei-si+1];
    int li = si;
    int ri = mid+1;
    int cnt = 0;
    int k = 0;
    while(li <= mid && ri <= ei) {
        if(ceil(arr[li]/2.0) > arr[ri]) {
            cnt += (mid-li+1);
            ri++;
        } else {
            li++;
        }
    }
    li = si;
    ri = mid+1;
    k = 0;
    while(li <= mid && ri <= ei) {
        if(arr[li] <= arr[ri]) {
            tempArr[k++] = arr[li++];
        } else {
            tempArr[k++] = arr[ri++];
        }
    }
    while(li <= mid) {
        tempArr[k++] = arr[li++];
    }
    while(ri <= ei) {
        tempArr[k++] = arr[ri++];
    }
    k = 0;
    for(int i = si; i <= ei; i++) {
        arr[i] = tempArr[k++];
    }
    delete[] tempArr;
    return cnt;

    }
    long long int mergeSort(vector<int>& arr, long long si , long long ei){
        long long int invCnt=0;
        if(si<ei)
        {       long long mid = ((ei+si)/2);
                invCnt += mergeSort(arr,si,mid);
                invCnt +=mergeSort(arr,mid+1,ei);
                invCnt += merge(arr,si,mid,ei);
        }
        return invCnt;
    }
    int reversePairs(vector<int>& arr) {
        return mergeSort(arr,0,arr.size()-1);
    }
};