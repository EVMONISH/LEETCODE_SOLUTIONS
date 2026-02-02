class Solution {
public:

    bool check(vector<int> &piles, int h, int mid)
    {
        long long reqTime = 0;
        for(int j=0; j<piles.size(); j++)
        {
            reqTime += (piles[j] + mid - 1) / mid;
        }
        return reqTime <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(piles, h, mid)) {
                ans = mid;
                high = mid - 1;   
            } else {
                low = mid + 1; 
            }
        }
        return ans;
    }
};