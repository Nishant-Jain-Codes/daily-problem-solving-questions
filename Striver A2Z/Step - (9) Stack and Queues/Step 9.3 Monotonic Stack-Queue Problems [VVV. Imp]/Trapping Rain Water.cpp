//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int height[], int n){
        // code here
        int l = 0;
        int r = n - 1;
        int lMax = 0;
        int rMax = 0;
        int ans = 0;
        while (l != r)
        {
            if (height[l] <= height[r])
            {
                if (lMax <= height[l])
                {
                    lMax = height[l];
                }
                else
                {
                    ans += lMax - height[l];
                }
                                    l++;
            }
            else
            {
                if (rMax <= height[r])
                {
                    rMax = height[r];
                }
                else
                {
                    ans += rMax - height[r];
                }
                r--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends