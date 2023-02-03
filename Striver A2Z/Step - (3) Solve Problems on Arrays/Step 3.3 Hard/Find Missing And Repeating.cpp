// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-missing-and-repeating


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    //method 1
    /*
    int *findTwoElement(int *arr, int n) {
        // code here
        unordered_map<int,int> m;
        long long int sum =0;
        for(int i=0;i<n;i++)
            {   sum+=arr[i];
                m[arr[i]]++;}
        int fno;
        int sno;
        for(int i=1;i<=n;i++){
            if(m.count(i)){
                if(m[i]==2)
                    fno=i;
            }else{
                sno=i;
            }
        }
        int *ans = new int[2];
        ans[0]=fno;
        ans[1]=sno;
        return ans;
        
    }
    */
    
    //method 2
      int *findTwoElement(int *a, int n) {
        int *answer=new int[2]{-1};
        int i=0;
        int value=0;
        int element=0;
        
        for(i=0; i<n;i++){
            value = abs(a[i]);
            element = a[value-1];
            if(element > 0) a[value-1] = -element;
            else answer[0]=value;//if element is negative therfore its value is accessed again so its the repeating character
        }
        for(i=0;i<n;i++){
            if(a[i]>0){//if tha value at an index is positve therefor that index was not accesse so its value doesnt exist
                answer[1]=i+1;
                break;
            }
        }
        return answer;
     }   
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends