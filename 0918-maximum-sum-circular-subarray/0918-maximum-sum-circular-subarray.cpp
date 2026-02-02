class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        int maxSum = nums[0], curMax = 0;
        int minSum = nums[0], curMin = 0;

        for(int i=0; i<n; i++)
        {
            curMax = max(nums[i], curMax + nums[i]);
            maxSum = max(maxSum, curMax);

            curMin = min(nums[i], curMin + nums[i]);
            minSum = min(minSum, curMin);
     
            totalSum += nums[i];
        }
        if(maxSum < 0)
        {
            return maxSum;
        }
        return max(maxSum, totalSum - minSum);
    }
};