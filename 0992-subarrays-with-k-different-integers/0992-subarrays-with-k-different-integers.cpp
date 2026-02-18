class Solution {
public:
    int atmostK(vector<int> &arr, int k)
    {
        unordered_map<int,int> mpp;

        int left = 0, count=0;

        for(int right = 0; right<arr.size(); right++)
        {   
            mpp[arr[right]]++;

            while(mpp.size() > k)
            {
                mpp[arr[left]]--;
                if(mpp[arr[left]] == 0)
                {
                    mpp.erase(arr[left]);
                }
                left++;
            }
            
            count += (right-left+1);
        }
        return count;
    }

int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostK(nums,k) - atmostK(nums,k-1);
    }
};

