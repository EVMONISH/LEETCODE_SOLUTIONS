class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int>mpp;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++)
        {
            mpp[nums[i]]++;

            if(i>=k)
            {
                mpp[nums[i-k]]--;
                if(mpp[nums[i-k]] == 0)
                    mpp.erase(nums[i-k]);
            }

            if(i>=k-1)
                ans.push_back(mpp.rbegin()->first);
        }
        return ans;
    }

};