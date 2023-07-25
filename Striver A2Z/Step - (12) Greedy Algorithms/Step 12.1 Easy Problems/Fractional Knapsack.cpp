//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,int>> valuePerWeight(n,{0,0});
        for(int i=0;i<n;i++){
            valuePerWeight[i].first = (double)arr[i].value*0.1/arr[i].weight;
            valuePerWeight[i].second = arr[i].weight;
        }
        sort(valuePerWeight.begin(),valuePerWeight.end());
        double ans = 0;
        int idx = n-1;
        while(W>0){
            if(W>=valuePerWeight[idx].second){
                ans += valuePerWeight[idx].first*valuePerWeight[idx].second;
                W -= valuePerWeight[idx].second;
            }
            else{
                ans += valuePerWeight[idx].first*W;
                W = 0;
            }
            idx--;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends