int countElements(int x, vector<int> &a)
{
    // Write your code here
    unordered_map<int, int> m;
    for(auto num : a)
        m[num]=0;
    int ans = 0;
    for(int i = 0;i<a.size();i++){
        if(m[a[i]]<x)
            {
                ans++;
                m[a[i]]++;
            }
        else 
            break;
    }
    return ans;
}