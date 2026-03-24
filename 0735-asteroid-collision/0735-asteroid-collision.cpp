class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        vector<int> st;

        for(int i=0; i<n; i++)
        {
            int curr = asteroids[i];

            if(curr > 0)
            {
                st.push_back(curr);
            }
            else{
                while(!st.empty() && st.back() > 0 && st.back() < abs(curr))
                {
                    st.pop_back();
                }

                if(!st.empty() && st.back() == abs(curr))
                {
                    st.pop_back();
                }
                else if(st.empty() || st.back() < 0)
                {
                    st.push_back(curr);
                }
            }
        }
        return st;
    }
};