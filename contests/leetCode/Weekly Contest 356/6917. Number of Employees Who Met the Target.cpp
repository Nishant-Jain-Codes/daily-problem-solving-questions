class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count = 0;
        for(auto & emp : huo)
            if(emp >= target)
                count++;
        return count;
    }
};