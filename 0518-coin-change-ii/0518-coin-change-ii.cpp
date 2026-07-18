class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<unsigned long long> prev(amount + 1, 0);

        for (int amt = 0; amt <= amount; amt++) {
            if (amt % coins[0] == 0)
                prev[amt] = 1;
        }

        for (int ind = 1; ind < n; ind++) {

            vector<unsigned long long> cur(amount + 1, 0);

            for (int amt = 0; amt <= amount; amt++) {

                unsigned long long notTake = prev[amt];

                unsigned long long take = 0;

                if (coins[ind] <= amt)
                    take = cur[amt - coins[ind]];

                cur[amt] = take + notTake;
            }

            prev = cur;
        }

        return (int)prev[amount];
    }
};