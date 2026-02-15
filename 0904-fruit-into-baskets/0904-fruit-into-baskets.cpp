class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        unordered_map<int,int>mpp;
        
        int left=0, maxLength = 0;

        for(int right = 0; right<n; right++)
        {
            mpp[fruits[right]]++;

            if(mpp.size() > 2)
            {
                mpp[fruits[left]]--;

                if(mpp[fruits[left]] == 0)
                {
                    mpp.erase(fruits[left]);
                }
                left++;
            }
            if(mpp.size() <= 2)
            {
                maxLength = max(maxLength, right-left+1);
            }
        }
        return maxLength;
    }
};