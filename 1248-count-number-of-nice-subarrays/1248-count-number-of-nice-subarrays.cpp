class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }

    int atmost(vector<int> &nums, int goal)
    {
        if(goal < 0) return 0;
        
        int left = 0, count=0, sum = 0;

        for(int right = 0; right<nums.size(); right++)
        {
            sum += (nums[right] %2);
            
            while(sum > goal)
            {
                sum -= (nums[left] %2);
                left++;
            }

            count += (right-left+1);
        }
    return count;
    }
};