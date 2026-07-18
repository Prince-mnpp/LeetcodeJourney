class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > sum) return 0;
        if ((sum + target) % 2) return 0;

        int neededSum = (sum + target) / 2;
        int n = nums.size();

        vector<vector<int>> dp(n + 1,
                               vector<int>(neededSum + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= neededSum; j++) {

                dp[i][j] = dp[i - 1][j];

                if (j >= nums[i - 1])
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
        }

        return dp[n][neededSum];
    }
};