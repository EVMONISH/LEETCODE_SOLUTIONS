// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         map<int,int>mpp;
//         vector<int> ans;

//         for(int i=0; i<nums.size(); i++)
//         {
//             mpp[nums[i]]++;

//             if(i>=k)
//             {
//                 mpp[nums[i-k]]--;
//                 if(mpp[nums[i-k]] == 0)
//                     mpp.erase(nums[i-k]);
//             }

//             if(i>=k-1)
//                 ans.push_back(mpp.rbegin()->first);
//         }
//         return ans;
//     }
// };


        //using stack and queues

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            if(!dq.empty() && dq.front() <= i-k)
            {
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);

            if(i >= k-1)
            {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};