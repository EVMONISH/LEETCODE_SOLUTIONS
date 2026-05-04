class Solution {
public:

    bool SubsetSumToK(int n, int k, vector<int> &arr)
    {
        vector<bool> prev(k+1,0), cur(k+1,0);

        prev[0] = cur[0] = true;
        if(arr[0]<=k) prev[arr[0]] = true;

        for(int ind=1; ind<n; ind++)
        {
            for(int target=1; target<=k; target++)
            {
                bool notTake = prev[target];
                bool take = false;
                if(arr[ind] <= target) take = prev[target-arr[ind]];
                cur[target] = take | notTake;
            }
            prev = cur;
        }
        return prev[k];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for(int i=0; i<n; i++) totalSum += nums[i];
        if(totalSum % 2 == 1) return false;
        int target = totalSum / 2;
        return SubsetSumToK(n, target, nums);
    }
};