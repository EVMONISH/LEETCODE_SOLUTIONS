class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = 0;

        for(int i = 0; i < n; i++)
            if(nums[i] == 1) totalOnes++;

        if(totalOnes == 0 || totalOnes == n)
            return 0;

        int currOnes = 0;
        for(int i = 0; i < totalOnes; i++)
            if(nums[i] == 1) currOnes++;

        int maxOnes = currOnes;

        for(int i = totalOnes; i < n + totalOnes; i++) {
            if(nums[i % n] == 1) currOnes++;
            if(nums[(i - totalOnes) % n] == 1) currOnes--;
            maxOnes = max(maxOnes, currOnes);
        }

        return totalOnes - maxOnes;
    }
};