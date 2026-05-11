class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();

        vector<unsigned long long> prev(amount + 1, 0),
                                   cur(amount + 1, 0);

        for(int T = 0; T <= amount; T++)
        {
            prev[T] = (T % coins[0] == 0);
        }

        for(int ind = 1; ind < n; ind++)
        {
            cur.assign(amount + 1, 0);

            for(int T = 0; T <= amount; T++)
            {
                unsigned long long notTake = prev[T];

                unsigned long long take = 0;

                if(coins[ind] <= T)
                    take = cur[T - coins[ind]];

                cur[T] = take + notTake;
            }

            prev = cur;
        }

        return prev[amount];
    }
};