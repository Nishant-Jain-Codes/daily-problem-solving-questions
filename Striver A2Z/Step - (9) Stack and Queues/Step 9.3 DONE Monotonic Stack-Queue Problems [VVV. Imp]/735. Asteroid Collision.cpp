class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int asteroid : asteroids) {
            bool collision = false;

            while (!st.empty() && asteroid < 0 && st.top() > 0) {
                if (abs(asteroid) > st.top()) {
                    st.pop();
                } else if (abs(asteroid) == st.top()) {
                    st.pop();
                    collision = true;
                    break;
                } else {
                    collision = true;
                    break;
                }
            }

            if (!collision) {
                st.push(asteroid);
            }
        }

        vector<int> answer(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            answer[i] = st.top();
            st.pop();
        }

        return answer;
    }
};
