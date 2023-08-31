//O(n) time, O(1) space
int findCelebrity(int n) {
    int potentialCelebrity = 0;
    
    // Find potential celebrity
    for (int i = 1; i < n; ++i) {
        if (knows(potentialCelebrity, i)) {
            potentialCelebrity = i;
        }
    }
    
    // Verify potential celebrity
    for (int i = 0; i < n; ++i) {
        if (i != potentialCelebrity && (knows(potentialCelebrity, i) || !knows(i, potentialCelebrity))) {
            return -1; // No celebrity found
        }
    }
    
    return potentialCelebrity;
}
// O(n^2) time, O(1) space
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int celeb = -1;
        for(int i=0;i<n;i++){
            bool knows = false;
            for(int j=0;j<n;j++){
                if(i==j)
                    continue;
                if(M[i][j])
                    knows = true;
            }
            if(!knows)
                {
                    celeb = i;
                    break;
                }
        }
        if(celeb==-1)
            return -1;
        bool allKnow = true;
        for(int j=0;j<n;j++){
            if(j==celeb)
                continue;
            if(M[j][celeb]!=1)
                {
                    return -1;
                }
        }
        return celeb;
    }
};